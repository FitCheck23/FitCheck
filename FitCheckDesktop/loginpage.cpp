#include "loginpage.h"
#include "ui_loginpage.h"

LoginPage::LoginPage(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginPage)
    , m_apiKey( QString() )
{
    ui->setupUi(this);


    this->setStyleSheet("background-color: #001D2B;");


    this->ui->lineEdit->setStyleSheet("QLineEdit{ border-width: 3px; border-style: solid; border-color: white; color: white; }");
    this->ui->lineEdit_2->setStyleSheet("QLineEdit{ border-width: 3px; border-style: solid; border-color: white; color: white; }");
    connect(ui->pushButton_cont,SIGNAL(clicked()),this,SLOT(cont_clicked()));
    connect(ui->pushButton_create,SIGNAL(clicked()),this,SLOT(create_clicked()));

    this->ui->pushButton_cont->setStyleSheet("QPushButton {background-color: #555657; color: white}" "QPushButton:hover {background-color: #66c011;}");
    this->ui->pushButton_create->setStyleSheet("QPushButton {background-color: #555657; color: white;}""QPushButton:hover {background-color: #66c011;}");

    m_networkAccessManager = new QNetworkAccessManager( this );
    connect( this, &LoginPage::userSignedIn, this, &LoginPage::performAuthenticatedDatabaseCall );

    m_networkReply = m_networkAccessManager->get(QNetworkRequest(QUrl("https://digital-twin-31756-default-rtdb.europe-west1.firebasedatabase.app/Users.json")));
    connect(m_networkReply, &QNetworkReply::readyRead, this, &LoginPage::saveUsersData);


    this->setWindowFlags(Qt::WindowStaysOnTopHint);
    this->showFullScreen();
}

void LoginPage::skipLogin(){
    //id-mail-pw-name-age-h8-w8
    QVector<QString> testData;
    testData.push_back("a");
    testData.push_back("b");
    testData.push_back("c");
    testData.push_back("d");
    testData.push_back("e");
    testData.push_back("f");
    testData.push_back("g");
    emit userEnters(testData);
}

void LoginPage::getAllUserDatas(){
    m_networkReply = m_networkAccessManager->get(QNetworkRequest(QUrl("https://digital-twin-31756-default-rtdb.europe-west1.firebasedatabase.app/Users.json")));
    connect(m_networkReply, &QNetworkReply::readyRead, this, &LoginPage::saveUsersData);

}

void LoginPage::saveUsersData()
{
    allUsers = static_cast<QString>(m_networkReply->readAll());
}



LoginPage::~LoginPage()
{
    delete ui;
    m_networkAccessManager->deleteLater();
}


void LoginPage::create_clicked()
{
    this->close();
    emit userCreateAccount();
}

void LoginPage::resizeEvent(QResizeEvent *event)
{
    QMainWindow::resizeEvent(event);
    ui->frame->setGeometry((this->width()-500)/2, (this->height()-900)/2, 500, 400);
    ui->gridWidget->setGeometry((this->width()-500)/2, (this->height()-200)/2, 500, 400);
}

////////////
//
///////////



void LoginPage::setAPIKey(const QString &apiKey)
{
    m_apiKey = apiKey;
}


void LoginPage::signUserUp(const QString &emailAddress,const QString &password,const QString &name,const QString &age,const QString &height,const QString &weight)
{
    QString signUpEndpoint = "https://identitytoolkit.googleapis.com/v1/accounts:signUp?key=" + m_apiKey;

    currentUserData.push_back("");
    currentUserData.push_back(emailAddress);
    currentUserData.push_back(password);
    currentUserData.push_back(name);
    currentUserData.push_back(age);
    currentUserData.push_back(height);
    currentUserData.push_back(weight);
    isSignUp = true;

    QVariantMap variantPayload;
    variantPayload["email"] = emailAddress;
    variantPayload["password"] = password;
    variantPayload["returnSecureToken"] = true;

    QJsonDocument jsonPayload = QJsonDocument::fromVariant( variantPayload );
    performPOST( signUpEndpoint, jsonPayload );
}


void LoginPage::cont_clicked()
{
    QString email , password;
    email = ui->lineEdit->text();
    password = ui->lineEdit_2->text();
    signUserIn(email, password);
}

void LoginPage::signUserIn(const QString &emailAddress, const QString &password)
{
    QString signInEndpoint = "https://identitytoolkit.googleapis.com/v1/accounts:signInWithPassword?key=" + m_apiKey;

    currentUserData.push_back("");              //for user id
    currentUserData.push_back(emailAddress);    //for email
    currentUserData.push_back(password);        //for password
    currentUserData.push_back("");              //for name
    currentUserData.push_back("");              //for age
    currentUserData.push_back("");              //for height
    currentUserData.push_back("");              //for weight

    isSignIn = true;

    QVariantMap variantPayload;
    variantPayload["email"] = emailAddress;
    variantPayload["password"] = password;
    variantPayload["returnSecureToken"] = true;

    QJsonDocument jsonPayload = QJsonDocument::fromVariant( variantPayload );
    performPOST( signInEndpoint, jsonPayload );

}

void LoginPage::networkReplyReadyRead()
{
    QByteArray response = m_networkReply->readAll();
    //    qDebug() << response;
    m_networkReply->deleteLater();

    parseResponse( response );
}

void LoginPage::performAuthenticatedDatabaseCall()
{
    QString endPoint = "https://digital-twin-31756-default-rtdb.europe-west1.firebasedatabase.app/Users.json?auth=" + m_idToken;
    m_networkReply = m_networkAccessManager->get( QNetworkRequest(QUrl("endPoint")));
    connect( m_networkReply, &QNetworkReply::readyRead, this, &LoginPage::networkReplyReadyRead );
}

void LoginPage::performPOST(const QString &url, const QJsonDocument &payload)
{
    QNetworkRequest newRequest( (QUrl( url )) );
    newRequest.setHeader( QNetworkRequest::ContentTypeHeader, QString( "application/json"));
    m_networkReply = m_networkAccessManager->post( newRequest, payload.toJson());
    connect( m_networkReply, &QNetworkReply::readyRead, this, &LoginPage::networkReplyReadyRead );
}

void LoginPage::parseResponse(const QByteArray &response)
{
    QJsonDocument jsonDocument = QJsonDocument::fromJson( response );
    if ( jsonDocument.object().contains("error") ) //error
    {
        currentUserData.clear();

        QString errorType;

        errorType = extractErrorType(response);

        if(isSignUp){
            emit invalidCreate(errorType);
            ui->lineEdit->setText("errorType");
        }
        else{
            ui->lineEdit->setText(errorType);
            ui->lineEdit_2->setText(errorType);
        }
    }
    else if ( jsonDocument.object().contains("kind"))
    {
        QString idToken = jsonDocument.object().value("idToken").toString();

        QString email = jsonDocument.object().value("email").toString();
        QString localId = jsonDocument.object().value("localId").toString();

//        qDebug() << "User signed in successfully!";

        m_idToken = idToken;

        if(isSignUp){   // kayıt olurken
            createUserDB(currentUserData[1], currentUserData[2], currentUserData[3], currentUserData[4], currentUserData[5], currentUserData[6]);
        }

        emit userSignedIn();
        this->close();
        emit userEnters(currentUserData);// bu sinyalle currentUserData'yo DesktopPage'e yolla
    }
    else{ //error

        QString errorType;

        errorType = extractErrorType(response);

        if(isSignUp){
            emit invalidCreate(errorType);
        }
        else{
            ui->lineEdit->setText(errorType);
            ui->lineEdit_2->setText(errorType);
        }
    }
}

void LoginPage::createUserDB(const QString &emailAddress, const QString &password, const QString &name,const QString &age,const QString &height,const QString &weight){

    QVariantMap currentMovement;
    currentMovement["accuracy"] = "";
    currentMovement["currentMove"] = "";
    currentMovement["duration"] = "";
    currentMovement["isStarted"] = "";
    currentMovement["liveScore"] = "";

    QVariantMap newUser;
    newUser["email"] = emailAddress;
    newUser["password"] = password;
    newUser["name"] = name;
    newUser["age"] = age;
    newUser["height"] = height;
    newUser["weight"] = weight;
    newUser["currentMovement"] = currentMovement;

    QJsonDocument jsonDoc = QJsonDocument::fromVariant(newUser);

    QNetworkRequest newUserRequest(QUrl("https://digital-twin-31756-default-rtdb.europe-west1.firebasedatabase.app/Users/.json"));
    newUserRequest.setHeader(QNetworkRequest::ContentTypeHeader, QString("application/json"));
    m_networkAccessManager->post(newUserRequest, jsonDoc.toJson());

}


QString LoginPage::extractErrorType(const QByteArray &response) {
    // Parse the JSON document
    QJsonDocument jsonDocument = QJsonDocument::fromJson(response);
    if (!jsonDocument.isObject()) {
        return QString();
    }

    // Extract the error object
    QJsonObject errorObject = jsonDocument.object().value("error").toObject();
    if (!errorObject.contains("message")) {
        return QString();
    }

    // Extract the error message
    QString errorMessage = errorObject.value("message").toString();

    // Split the error message into parts
    QStringList parts = errorMessage.split(":");

    // Return the meaningful part
    if (parts.size() > 1) {
        return parts[1].trimmed();
    } else {
        return errorMessage;
    }
}

