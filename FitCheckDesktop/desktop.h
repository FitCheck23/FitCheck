#ifndef DESKTOP_H
#define DESKTOP_H

#include "loginpage.h"

#include <QMainWindow>
#include<QTimer>
#include<QLabel>

#include <QtNetwork>
#include <QByteArray>
#include <QDataStream>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QJsonObject>
#include <QJsonDocument>
#include <QVariantMap>
#include <QDebug>
#include <QCoreApplication>
#include <QProcess>
#include <QDir>
#include <QMap>
#include <QString>
#include <QVector>
#include <QDateTime>

struct Vector3 {
    float x, y, z,visibility;
};

struct PoseData {
    Vector3 vectors[33];
};


namespace Ui {
class Desktop;
}

class Desktop : public QMainWindow
{
    Q_OBJECT

public:
    Desktop(QWidget *parent = nullptr);
    ~Desktop();
    /*void resizeEvent(QResizeEvent *event) override{
        this->setFixedHeight(this->height());
        QWidget::

    }*/

public slots:
    void showDesktop(QVector<QString> CurrentUserData, QString selectedSet);

private slots:
    void StartPose();

    void StopPose();

    void timer();

    void on_Exit_clicked();
    void getCurrentUserData();
    void getAllUsersData();
    void saveUsersData();

    void enableEdit();
    void saveChangings();
    void newTcpConnection();
    void readTcpData();
    void discardTcpSocket();
    void AddToTcpSocketList(QTcpSocket *socket);
    void setAllPosesAngles();
    float calculateScore(PoseData landmarks);
    float calculateAngle(QVector<float> a, QVector<float> b, QVector<float> c);
    float diffCompareAngle(QVector<float> x, QVector<float> y);
    float Average(QVector<float> vec);
    void comparePose(QVector<float> angle_point, QVector<float> angle_user, QVector<float> angle_target);

    void setChanged(int index);
    void beReadyStartSlot();
    void beReadyReduce();
protected:
    void resizeEvent(QResizeEvent *event);

private:
    Ui::Desktop *ui;
    QTimer *myTimer;
    QTimer *beReadyTimer;
    short int minutes;
    short int seconds;
    QVector<QString> currentUserData; //id-mail-pw-name-age-h8-w8
    QVector<QString> currentMovement; // currentMove-duration-isStarted-accuracy
    QVector<QVector<QString>> nextMovements;    //nextMove
    QNetworkAccessManager * m_networkAccessManager;
    QNetworkReply * m_networkReply;
    int getDataFrequency = 1000;
    QTimer* getDataTimer;
    QString currentUserAllDatas;
    void showPersonalInfo();
    void findCurrentUserId();

    void updateCurrentMovement();
    void goNextMovement();
    int movementIndex;
    void updatePersonalInfo();
    void setColors();

    QTcpServer *TCP_Server;
    QTcpSocket* TcpClient;

    quint16 TcpPort = 12345;
    QString unrealEngineAppPath = "C:/Users/kocse/Desktop/camid0/run.bat";
    QProcess *UEProcess;

    PoseData poseData;
    float score;
    float score_percentage = 0;
    QMap<QString, QVector<float>> allPosesAngles;
    QVector<QVector<QString>> allSets;
    QVector<QString> set1;
    QVector<QString> set2;
    QVector<QString> set3;
    QVector<QString> currentSet;
    int currentPoseID = -1;
    QString poseID;
    QString isStarted = "false";
    int startCheck = 0;
    int duration = 10;
    float currentAccuracy = 0;
    float perfectMinLimit = 80;
    bool poseStarted = false;

    bool beReady = true;
    int beReadyDurationInitial = 5;
    int beReadyDuration = 5;

    bool setFinish = false;

    int setChangeMake5;

    QDateTime LastDataDateTime;
};

#endif // DESKTOP_H
