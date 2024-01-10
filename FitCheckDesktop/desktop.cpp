#include "desktop.h"
#include "ui_desktop.h"
#include<QDebug>
#include <QDateTime>
#include<QTimer>
#include<QApplication>
#include <QElapsedTimer>
#include<QMovie>
#include<QThread>
#include<QString>
#include<QApplication>



QString dbUrl = "https://digital-twin-31756-default-rtdb.europe-west1.firebasedatabase.app/Users/";
QString jsonExt= ".json";

//static int counter = 2; //for adjusting nextMove
Desktop::Desktop(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Desktop)
{
    ui->setupUi(this);

    this->setStyleSheet("background-color: #001D2B;");
    ui->CurrentMove->setStyleSheet("background-color: #068496; color: white;");
    ui->NextMove->setStyleSheet("background-color: #068496; color: white;");
    ui->Start->setStyleSheet("background-color: #068496; color: white;");
    ui->Stop->setStyleSheet("background-color: #068496; color: white;");
    ui->minute->setStyleSheet("background-color: #001D2B; color: white;");
    ui->second->setStyleSheet("background-color: #001D2B; color: white;");
    ui->lineEdit_name->setStyleSheet("background-color: #068496; color: white;");
    ui->lineEdit_age->setStyleSheet("background-color: #068496; color: white;");
    ui->lineEdit_height->setStyleSheet("background-color: #068496; color: white;");
    ui->lineEdit_weight->setStyleSheet("background-color: #068496; color: white;");
    ui->lineEdit_5->setStyleSheet("background-color: #068496; color: white;");
    ui->lineEdit_6->setStyleSheet("background-color: #068496; color: white;");
    ui->lineEdit_7->setStyleSheet("background-color: #068496; color: white;");
    ui->lineEdit_8->setStyleSheet("background-color: #068496; color: white;");
    ui->pushButton_Edit->setStyleSheet("background-color: #068496; color: white;");
    ui->pushButton_Save->setStyleSheet("background-color: #068496; color: white;");
    ui->lineEdit_5->setAlignment(Qt::AlignCenter);
    ui->lineEdit_6->setAlignment(Qt::AlignCenter);
    ui->lineEdit_7->setAlignment(Qt::AlignCenter);
    ui->lineEdit_8->setAlignment(Qt::AlignCenter);
    ui->lineEdit_name->setAlignment(Qt::AlignCenter);
    ui->lineEdit_age->setAlignment(Qt::AlignCenter);
    ui->lineEdit_height->setAlignment(Qt::AlignCenter);
    ui->lineEdit_weight->setAlignment(Qt::AlignCenter);


    ui->pushButton_Edit->setFixedSize(150,60);
    QFont fontEdit = ui->pushButton_Edit->font();
    fontEdit.setPointSize(12); // Set the font size
    fontEdit.setBold(true);    // Make it bold
    ui->pushButton_Edit->setFont(fontEdit);

    ui->pushButton_Save->setFixedSize(150,60);
    QFont fontSave = ui->pushButton_Save->font();
    fontSave.setPointSize(12); // Set the font size
    fontSave.setBold(true);    // Make it bold
    ui->pushButton_Save->setFont(fontSave);


    QFont fontCurMove = ui->CurrentMove->font();
    fontCurMove.setPointSize(18); // Set the font size
    fontCurMove.setBold(true);    // Make it bold
    ui->CurrentMove->setFont(fontCurMove);

    QFont fontNextMove = ui->NextMove->font();
    fontNextMove.setPointSize(18); // Set the font size
    fontNextMove.setBold(true);    // Make it bold
    ui->NextMove->setFont(fontNextMove);


    ui->Start->setFixedSize(250,80);
    QFont fontStart = ui->Start->font();
    fontStart.setPointSize(18); // Set the font size
    fontStart.setBold(true);    // Make it bold
    ui->Start->setFont(fontStart);

    ui->Stop->setFixedSize(250,80);
    QFont fontStop = ui->Start->font();
    fontStop.setPointSize(18); // Set the font size
    fontStop.setBold(true);    // Make it bold
    ui->Stop->setFont(fontStop);

    ui->textBrowser_score->setFixedHeight(350);

    ui->lineEdit_5->setFixedHeight(50);
    QFont font1 = ui->lineEdit_5->font();
    font1.setPointSize(18); // Set the font size
    font1.setBold(true);    // Make it bold
    ui->lineEdit_5->setFont(font1);

    ui->lineEdit_name->setFixedHeight(50);
    QFont font2 = ui->lineEdit_name->font();
    font2.setPointSize(18); // Set the font size
    font2.setBold(true);    // Make it bold
    ui->lineEdit_name->setFont(font2);

    ui->lineEdit_6->setFixedHeight(50);
    QFont font3 = ui->lineEdit_6->font();
    font3.setPointSize(18); // Set the font size
    font3.setBold(true);    // Make it bold
    ui->lineEdit_6->setFont(font3);

    ui->lineEdit_age->setFixedHeight(50);
    QFont font4 = ui->lineEdit_age->font();
    font4.setPointSize(18); // Set the font size
    font4.setBold(true);    // Make it bold
    ui->lineEdit_age->setFont(font4);


    ui->lineEdit_7->setFixedHeight(50);
    QFont font5 = ui->lineEdit_7->font();
    font5.setPointSize(18); // Set the font size
    font5.setBold(true);    // Make it bold
    ui->lineEdit_7->setFont(font5);

    ui->lineEdit_height->setFixedHeight(50);
    QFont font6 = ui->lineEdit_height->font();
    font6.setPointSize(18); // Set the font size
    font6.setBold(true);    // Make it bold
    ui->lineEdit_height->setFont(font6);

    ui->lineEdit_8->setFixedHeight(50);
    QFont font7 = ui->lineEdit_8->font();
    font7.setPointSize(18); // Set the font size
    font7.setBold(true);    // Make it bold
    ui->lineEdit_8->setFont(font7);

    ui->lineEdit_weight->setFixedHeight(50);
    QFont font8 = ui->lineEdit_weight->font();
    font8.setPointSize(18); // Set the font size
    font8.setBold(true);    // Make it bold
    ui->lineEdit_weight->setFont(font8);



    QFont fontSetName = ui->comboBox_setName->font();
    fontSetName.setPointSize(18); // Set the font size
    fontSetName.setBold(true);    // Make it bold
    ui->comboBox_setName->setFont(fontSetName);


    ui->comboBox_setName->addItem("                             Set 1");
    ui->comboBox_setName->addItem("                            Set 2");
    ui->comboBox_setName->addItem("                            Set 3");

    QFont fontSetDur = ui->comboBox_setDuration->font();
    fontSetDur.setPointSize(18); // Set the font size
    fontSetDur.setBold(true);    // Make it bold
    ui->comboBox_setDuration->setFont(fontSetDur);

    ui->comboBox_setDuration->addItem(" Pose Duration:   10  secs");
    ui->comboBox_setDuration->addItem(" Pose Duration:   20  secs");
    ui->comboBox_setDuration->addItem(" Pose Duration:   30  secs");


    ui->comboBox_setName->setStyleSheet("background-color: #068496; color: white;");
    ui->comboBox_setDuration->setStyleSheet("background-color: #068496; color: white;");
    ui->comboBox_setName->setMaximumHeight(60);
    ui->comboBox_setDuration->setMaximumHeight(60);

    connect(ui->comboBox_setName, SIGNAL(currentIndexChanged(int)), this, SLOT(setChanged(int)));
    connect(ui->comboBox_setDuration, SIGNAL(currentIndexChanged(int)), this, SLOT(setChanged(int)));


    //////////////////
    set1.push_back("T_Pose");
    set1.push_back("Mountain_Pose");
    set1.push_back("Goddess_Pose");


    set2.push_back("Chair_Pose");
    set2.push_back("Flamingo_Pose");
    set2.push_back("Half_Moon_Pose");


    set3.push_back("Tree_Pose_1");
    set3.push_back("Tree_Pose_2");
    set3.push_back("Warrior_Pose");

    allSets.push_back(set1);
    allSets.push_back(set2);
    allSets.push_back(set3);

    setAllPosesAngles();

    seconds = 0;
    minutes = 0;
    movementIndex=0;
    ui->second->display(seconds);
    ui->minute->display(minutes);

    myTimer = new QTimer(this);
    connect(myTimer, SIGNAL(timeout()),this,SLOT(timer()));

    beReadyTimer = new QTimer(this);
    connect(beReadyTimer, SIGNAL(timeout()),this,SLOT(beReadyReduce()));
    /*ui->digitalTwinFrame->setFixedWidth(this->width()/2);
    ui->digitalTwinFrame->setFixedHeight(this->height());*/

    currentUserData.push_back("");  //initial Id

    m_networkAccessManager = new QNetworkAccessManager(this);
    // Initialize the timer with a 10 second interval
    getDataTimer = new QTimer(this);
    connect(getDataTimer, &QTimer::timeout, this, &Desktop::getCurrentUserData);


    connect(ui->pushButton_Edit, SIGNAL(clicked()), this, SLOT(enableEdit()));
    connect(ui->pushButton_Save, SIGNAL(clicked()), this, SLOT(saveChangings()));
    connect(ui->Start, SIGNAL(clicked()), this, SLOT(beReadyStartSlot()));
    connect(ui->Stop, SIGNAL(clicked()), this, SLOT(StopPose()));


    ////////
    //TCP Part
    TCP_Server = new QTcpServer();
    if(TCP_Server->listen(QHostAddress::Any, TcpPort)){
        connect(TCP_Server, &QTcpServer::newConnection, this, &Desktop::newTcpConnection);
    }else{
        qDebug() << "TCP Server Error";
    }


}
void Desktop::setChanged(int index)
{


    myTimer->stop();
    beReadyTimer->stop();

    isStarted = "false";
    updateCurrentMovement();

    currentSet = allSets[ui->comboBox_setName->currentIndex()];
    duration = 10 + 10*ui->comboBox_setDuration->currentIndex();

    currentPoseID = -1;
    setFinish = false;
    setChangeMake5 =4;
    goNextMovement();
}



void Desktop::AddToTcpSocketList(QTcpSocket *socket)
{
    TcpClient=socket;
    connect(socket, &QTcpSocket::readyRead, this, &Desktop::readTcpData);
    connect(socket, &QTcpSocket::disconnected, this, &Desktop::discardTcpSocket);
    qDebug() << " TCP CONNECTED!!!";

}

void Desktop::newTcpConnection()
{
    while(TCP_Server->hasPendingConnections()){
        AddToTcpSocketList(TCP_Server->nextPendingConnection());
    }
}

void Desktop::readTcpData()
{

    QByteArray DataBuffer;
    DataBuffer = TcpClient->read(sizeof(PoseData));
    poseData = *reinterpret_cast<PoseData*>(DataBuffer.data());

    calculateScore(poseData);

}

void Desktop::discardTcpSocket()
{
    TcpClient->deleteLater();

}



/////////////////////////////////////////////////




Desktop::~Desktop()
{
    delete ui;

    system("taskkill /im MediaPipeDemo.exe /f");

    qApp->quit();
}
void Desktop::setColors()
{

}

void Desktop::enableEdit()
{
    getDataTimer->stop();
    myTimer->stop();

    myTimer->stop();
    beReadyTimer->stop();

    isStarted = "false";
    updateCurrentMovement();

    ui->lineEdit_name->setEnabled(true);
    ui->lineEdit_age->setEnabled(true);
    ui->lineEdit_weight->setEnabled(true);
    ui->lineEdit_height->setEnabled(true);
}

void Desktop::saveChangings()
{
    ui->lineEdit_name->setEnabled(false);
    ui->lineEdit_age->setEnabled(false);
    ui->lineEdit_weight->setEnabled(false);
    ui->lineEdit_height->setEnabled(false);

    currentUserData[3] = ui->lineEdit_name->text();
    currentUserData[4] = ui->lineEdit_age->text();
    currentUserData[5] = ui->lineEdit_height->text();
    currentUserData[6] = ui->lineEdit_weight->text();

    updatePersonalInfo();


    getDataTimer->start(getDataFrequency);
}

void Desktop::updatePersonalInfo() {
    QString currentUrl = dbUrl + currentUserData[0] + jsonExt;

    if(score_percentage<0)
    {
        score_percentage = 0;
    }

    QVariantMap curMovVariant;
    curMovVariant["currentMove"] = currentSet[currentPoseID];
    curMovVariant["isStarted"] = isStarted;
    curMovVariant["duration"] = QString::number(duration);
    curMovVariant["accuracy"] = QString::number(currentAccuracy);
    curMovVariant["liveScore"] = QString::number(score_percentage);

    QVariantMap infoVariant;
    infoVariant["email"] = currentUserData[1];
    infoVariant["password"] = currentUserData[2];
    infoVariant["name"] = currentUserData[3];
    infoVariant["age"] = currentUserData[4];
    infoVariant["height"] = currentUserData[5];
    infoVariant["weight"] = currentUserData[6];
    infoVariant["currentMovement"] = curMovVariant;

    QJsonDocument jsonPayload = QJsonDocument::fromVariant( infoVariant );
    m_networkReply = m_networkAccessManager->put(QNetworkRequest(QUrl(currentUrl)), jsonPayload.toJson());
}
void Desktop::getAllUsersData() {
    QString currentUrl = dbUrl + jsonExt;
    m_networkReply = m_networkAccessManager->get(QNetworkRequest(QUrl(currentUrl)));
    connect(m_networkReply, &QNetworkReply::readyRead, this, &Desktop::findCurrentUserId);
}

void Desktop::getCurrentUserData() {
    QString currentUrl = dbUrl + currentUserData[0] + jsonExt;
    m_networkReply = m_networkAccessManager->get(QNetworkRequest(QUrl(currentUrl)));
    connect(m_networkReply, &QNetworkReply::readyRead, this, &Desktop::saveUsersData);
}

void Desktop::saveUsersData()
{
    if(currentUserData[0] == ""){
        findCurrentUserId();
    }

    currentUserAllDatas = static_cast<QString>(m_networkReply->readAll());

    QJsonDocument jsonDoc = QJsonDocument::fromJson(currentUserAllDatas.toUtf8());

    if (!jsonDoc.isNull() && jsonDoc.isObject()) {
        QJsonObject jsonObj = jsonDoc.object();

        // Extract top-level values
        currentUserData[1] = jsonObj.value("email").toString();
        currentUserData[2] = jsonObj.value("password").toString();
        currentUserData[3] = jsonObj.value("name").toString();
        currentUserData[4] = jsonObj.value("age").toString();
        currentUserData[5] = jsonObj.value("height").toString();
        currentUserData[6] = jsonObj.value("weight").toString();

        showPersonalInfo();
    }
}

void Desktop::findCurrentUserId()
{
    QString allUsers = static_cast<QString>(m_networkReply->readAll());
    QJsonDocument jsonDoc = QJsonDocument::fromJson(allUsers.toUtf8());

    QJsonObject jsonObj = jsonDoc.object();

    for (const auto &key : jsonObj.keys()) {
        QJsonObject innerObj = jsonObj.value(key).toObject();
        QString innerEmail = innerObj.value("email").toString();

        if (innerEmail == currentUserData[1]) {
            currentUserData[0] = key;  // ID
            saveUsersData();
        }
    }

}

void Desktop::updateCurrentMovement()
{
    if(currentUserData[0] == "")
        return;

    if(score_percentage<0)
    {
        score_percentage = 0;
    }

    QString currentUrl = dbUrl + currentUserData[0] + "/currentMovement" + jsonExt;
    QVariantMap curMovVariant;

    curMovVariant["currentMove"] = currentSet[currentPoseID];
    curMovVariant["isStarted"] = isStarted;
    curMovVariant["duration"] = QString::number(duration);
    curMovVariant["liveScore"] = QString::number(score_percentage);
    curMovVariant["accuracy"] = QString::number(currentAccuracy);


    QJsonDocument jsonPayload = QJsonDocument::fromVariant( curMovVariant );
    m_networkReply = m_networkAccessManager->put(QNetworkRequest(QUrl(currentUrl)), jsonPayload.toJson());
}

void Desktop::goNextMovement()
{
    ++setChangeMake5;
    LastDataDateTime = QDateTime::currentDateTime();
    if(currentSet.size() >= currentPoseID+2) {

        currentPoseID++;

        //current move'u post eden fonksiyon
        updateCurrentMovement();


        ui->CurrentMove->setText("Current Pose:  " + currentSet[currentPoseID]);
        if(currentSet.size() == currentPoseID+1)
        {
            ui -> NextMove -> setText("NICE! Nothing left.");
        }
        else{
            ui -> NextMove -> setText("Next Pose: " + currentSet[currentPoseID+1]);
        }
        // currentAccuracy = 0;
        duration = 10 + 10*ui->comboBox_setDuration->currentIndex();
        minutes = duration / 60; // Calculate minutes
        seconds = duration % 60;
        ui->second->display(seconds);
        ui->minute->display(minutes);

        beReadyDuration = beReadyDurationInitial;
        if(setChangeMake5!=5)
            beReadyStartSlot();

    }
    else{
        setFinish = true;
        myTimer->stop();
        beReadyTimer->stop();

        isStarted = "false";
        updateCurrentMovement();
        ui -> CurrentMove -> setText("FIT CHECK TIME!");
    }

    if(startCheck == 1)
    {
        // Set font size
        ui->textBrowser_score->clear();
        int fontSize = 30;
        QColor fontColor = Qt::green;
        QFont font = ui->textBrowser_score->font();
        font.setPointSize(fontSize);
        ui->textBrowser_score->setFont(font);  // Use setFont instead of setCurrentFont
        // Change font color
        QTextCharFormat charFormat;
        charFormat.setForeground(QBrush(fontColor));
        QTextCursor cursor = ui->textBrowser_score->textCursor();
        cursor.select(QTextCursor::Document);
        cursor.mergeCharFormat(charFormat);
        ui->textBrowser_score->setTextCursor(cursor);

        ui->textBrowser_score->append("\n\n");
        ui->textBrowser_score->append("\t\t\tAre you ready to get Fitter?");
    }
    else if( beReady == true)
    {
        // Set font size
        ui->textBrowser_score->clear();
        int fontSize = 30;
        QColor fontColor = Qt::yellow;
        QFont font = ui->textBrowser_score->font();
        font.setPointSize(fontSize);
        ui->textBrowser_score->setFont(font);  // Use setFont instead of setCurrentFont
        // Change font color
        QTextCharFormat charFormat;
        charFormat.setForeground(QBrush(fontColor));
        QTextCursor cursor = ui->textBrowser_score->textCursor();
        cursor.select(QTextCursor::Document);
        cursor.mergeCharFormat(charFormat);
        ui->textBrowser_score->setTextCursor(cursor);

        ui->textBrowser_score->append("\n");
        ui->textBrowser_score->append("\t\t\t\t   GET READY!");
        ui->textBrowser_score->append("\n\t\t\t\t\t     " + QString::number(beReadyDuration));
    }
    else if(setFinish)
    {
        // Set font size
        ui->textBrowser_score->clear();
        int fontSize = 30;
        QColor fontColor = Qt::green;
        QFont font = ui->textBrowser_score->font();
        font.setPointSize(fontSize);
        ui->textBrowser_score->setFont(font);  // Use setFont instead of setCurrentFont
        // Change font color
        QTextCharFormat charFormat;
        charFormat.setForeground(QBrush(fontColor));
        QTextCursor cursor = ui->textBrowser_score->textCursor();
        cursor.select(QTextCursor::Document);
        cursor.mergeCharFormat(charFormat);
        ui->textBrowser_score->setTextCursor(cursor);

        ui->textBrowser_score->append("\t\t  SET FINISHED, congratulations!!");
        ui->textBrowser_score->append("\n\t\t One step closer to a fitter world.");
        ui->textBrowser_score->append("\n\t\t\t Ready to new one?");
        myTimer->stop();
        beReadyTimer->stop();

        isStarted = "false";
        updateCurrentMovement();
    }

}

void Desktop::beReadyReduce()
{
    // Set font size
    ui->textBrowser_score->clear();
    int fontSize = 30;
    QColor fontColor = Qt::yellow;
    QFont font = ui->textBrowser_score->font();
    font.setPointSize(fontSize);
    ui->textBrowser_score->setFont(font);  // Use setFont instead of setCurrentFont
    // Change font color
    QTextCharFormat charFormat;
    charFormat.setForeground(QBrush(fontColor));
    QTextCursor cursor = ui->textBrowser_score->textCursor();
    cursor.select(QTextCursor::Document);
    cursor.mergeCharFormat(charFormat);
    ui->textBrowser_score->setTextCursor(cursor);

    ui->textBrowser_score->append("\n");
    ui->textBrowser_score->append("\t\t\t\t   GET READY!");
    ui->textBrowser_score->append("\n\t\t\t\t\t     " + QString::number(beReadyDuration-1));

    isStarted = "false";
    updateCurrentMovement();

    beReadyDuration -= 1;
    if(beReadyDuration == 0)
    {
        beReadyTimer->stop();
        StartPose();
    }

}

void Desktop::beReadyStartSlot()
{

    startCheck += 1;
    isStarted = "false";
    beReady = true;
    beReadyDuration = beReadyDurationInitial;

    myTimer->stop();
    beReadyTimer->stop();

    isStarted = "false";
    updateCurrentMovement();
    // StopPose();
    beReadyTimer->start(1000);

    // Set font size
    ui->textBrowser_score->clear();
    int fontSize = 30;
    QColor fontColor = Qt::yellow;
    QFont font = ui->textBrowser_score->font();
    font.setPointSize(fontSize);
    ui->textBrowser_score->setFont(font);  // Use setFont instead of setCurrentFont
    // Change font color
    QTextCharFormat charFormat;
    charFormat.setForeground(QBrush(fontColor));
    QTextCursor cursor = ui->textBrowser_score->textCursor();
    cursor.select(QTextCursor::Document);
    cursor.mergeCharFormat(charFormat);
    ui->textBrowser_score->setTextCursor(cursor);

    ui->textBrowser_score->append("\n");
    ui->textBrowser_score->append("\t\t\t\t   GET READY!");
    ui->textBrowser_score->append("\n\t\t\t\t\t     " + QString::number(beReadyDuration));
}

void Desktop::timer()
{
    QDateTime currentDateTime = QDateTime::currentDateTime();
    qint64 secondsDifference = LastDataDateTime.secsTo(currentDateTime);

    if(secondsDifference >= 1)
    {
        // Set font size
        ui->textBrowser_score->clear();
        int fontSize = 30;
        QColor fontColor = Qt::red;
        QFont font = ui->textBrowser_score->font();
        font.setPointSize(fontSize);
        ui->textBrowser_score->setFont(font);  // Use setFont instead of setCurrentFont
        // Change font color
        QTextCharFormat charFormat;
        charFormat.setForeground(QBrush(fontColor));
        QTextCursor cursor = ui->textBrowser_score->textCursor();
        cursor.select(QTextCursor::Document);
        cursor.mergeCharFormat(charFormat);
        ui->textBrowser_score->setTextCursor(cursor);

        ui->textBrowser_score->append("\n\t\t\t\tNO CAMERA DATA!");
        ui->textBrowser_score->append("\n\n\t\t  Please change camera position.");

    }

    if(!(seconds ==0 && minutes == 0)){
        duration -= 1;

        if(score_percentage>70 && score_percentage<80)
            currentAccuracy += 5;
        else if (score_percentage>80)
            currentAccuracy += 10;
    }
    updatePersonalInfo();
    if(seconds == 0){
        if(minutes == 0){

            myTimer->stop();
            beReadyTimer->stop();

            isStarted = "false";
            updateCurrentMovement();

            goNextMovement();
            if(setFinish){
                myTimer->stop();
                beReadyTimer->stop();

                isStarted = "false";
                updateCurrentMovement();
            }
        }
        else{
            seconds = 59;
            minutes = minutes-1;
        }
    }
    else{
        seconds = seconds-1;
    }
    ui->second->display(seconds);
    ui->minute->display(minutes);
}

void Desktop::StartPose()
{
    currentAccuracy = 0;
    beReady = false;
    isStarted = "true";
    updateCurrentMovement();
    myTimer->start(1000);

}

void Desktop::StopPose()
{
    myTimer->stop();
    beReadyTimer->stop();

    isStarted = "false";
    updateCurrentMovement();

}

void Desktop::on_Exit_clicked()
{
    system("taskkill /im MediaPipeDemo.exe /f");

    qApp->quit();
}

void Desktop::resizeEvent(QResizeEvent *event)
{
    QMainWindow::resizeEvent(event); // call the base class implementation
    ui->centralwidget->setGeometry(0, 0, this->width(), this->height());
}

void Desktop::showDesktop(QVector<QString> CurrentUserData, QString selectedSet)
{
    currentSet = allSets[ui->comboBox_setName->currentIndex()];
    duration = 10 + 10*ui->comboBox_setDuration->currentIndex();

    currentPoseID = -1;

    getAllUsersData();
    getDataTimer->start(getDataFrequency);
    currentUserData = CurrentUserData;
    showPersonalInfo();

    ui->comboBox_setName->setCurrentIndex(0);
    goNextMovement();

    myTimer->stop();
    beReadyTimer->stop();

    isStarted = "false";
    updateCurrentMovement();

    this->setWindowFlags(Qt::WindowStaysOnBottomHint);
    this->showFullScreen();

    // this->show();

    ///////////////
    QString executablePath = QCoreApplication::applicationDirPath();
    executablePath += "/Unreal/MediaPipeDemo.exe";

    unrealEngineAppPath = executablePath;

    // OPEN Unreal Engine
    UEProcess = new QProcess();

    // Set the working directory to the path of the Unreal Engine application
    UEProcess->setWorkingDirectory(QFileInfo(unrealEngineAppPath).path());

    QStringList arguments;
    arguments << "-windowed"<< "resx=960 " << "resy=540 " << "winx=0 " << "winy=0";

    // arguments << "-windowed"<< "resx=480 " << "resy=360 " << "winx=0 " << "winy=0";

    // Start the Unreal Engine application
    UEProcess->startDetached(unrealEngineAppPath,arguments);

    if (!UEProcess->waitForStarted()) {
        qWarning() << "Failed to start Unreal Engine application.";
    }


}

void Desktop::showPersonalInfo()
{
    ui->lineEdit_name->setText(currentUserData[3]);
    ui->lineEdit_age->setText(currentUserData[4]);
    ui->lineEdit_height->setText(currentUserData[5]);
    ui->lineEdit_weight->setText(currentUserData[6]);
}
