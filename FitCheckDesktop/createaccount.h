#ifndef CREATEACCOUNT_H
#define CREATEACCOUNT_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QTextBrowser>
#include <QVBoxLayout>
#include <QPalette>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class createAccount; }
QT_END_NAMESPACE

class createAccount : public QMainWindow
{
    Q_OBJECT

public:
    createAccount(QWidget *parent = nullptr);
    ~createAccount();
    QString getEmail();
    QString getPassword();
    QString getName();
    QString getAge();
    QString getHeight();
    QString getWeight();


public slots:
    void showCreatePage();
    void createAccount_clicked();
    void closeCreatePage();
    void printErrorType(const QString &errorType);

signals:
    void checkNewAccount(const QString &emailAddress,const QString &password,const QString &name,const QString &age,const QString &height,const QString &weight);

private:
    Ui::createAccount *ui;

    QString newEmail;
    QString newPassword;
    QString newName;
    QString newAge;
    QString newHeight;
    QString newWeight;

};

#endif // CREATEACCOUNT_H



