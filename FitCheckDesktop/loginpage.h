#ifndef LOGINPAGE_H
#define LOGINPAGE_H

#include <QMainWindow>
#include <QObject>

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QJsonObject>
#include <QJsonDocument>
#include <QVariantMap>
#include <QDebug>
#include <QThread>

QT_BEGIN_NAMESPACE
namespace Ui { class LoginPage; }
QT_END_NAMESPACE

class LoginPage : public QMainWindow
{
    Q_OBJECT

public:
    LoginPage(QWidget *parent = nullptr);
    ~LoginPage();
    void setAPIKey( const QString & apiKey );
    void signUserUp(const QString &emailAddress,const QString &password,const QString &name,const QString &age,const QString &height,const QString &weight);
    void signUserIn( const QString & emailAddress, const QString & password );

    void skipLogin();
private slots:
    void cont_clicked();
    void create_clicked();
    void networkReplyReadyRead();
    void performAuthenticatedDatabaseCall();
    void createUserDB(const QString &emailAddress, const QString &password, const QString &name, const QString &age, const QString &height, const QString &weight);
    void saveUsersData();
    void getAllUserDatas();

signals:
    void userEnters(QVector<QString> currentUserData);
    void userCreateAccount();
    void userSignedIn();
    void invalidCreate(const QString &errorType);

protected:
    void resizeEvent(QResizeEvent *event);

private:
    Ui::LoginPage *ui;
    void performPOST( const QString & url, const QJsonDocument & payload );
    void parseResponse( const QByteArray & reponse );
    QString m_apiKey;
    QNetworkAccessManager * m_networkAccessManager;
    QNetworkReply * m_networkReply;
    QString m_idToken;
    QVector<QString> currentUserData; //id-mail-pw-name-age-h8-w8  || currentMove bilgileride gelecek
    bool isSignUp = false;
    bool isSignIn = true;
    QString extractErrorType(const QByteArray &response);
    void fillUserData(QString &userID);

    QString allUsers;
    void findIdByEmail(const QString &jsonDoc, const QString &email);
    void sendToDesktop(const QString &email);
};
#endif // LOGINPAGE_H
