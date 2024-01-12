#include "loginpage.h"
#include "createaccount.h"
#include "desktop.h"
#include "selectSet.h"

#include <QApplication>

#include    <QObject>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Desktop desktopPage;
    LoginPage loginPage;
    createAccount createPage;
    selectSet selectset;

//    desktopPage.show();
    loginPage.setAPIKey("AIzaSyAJWH2DOJ5txLo-696TknpHi_xjMcZ4-_4");

    QObject::connect(&loginPage, &LoginPage::userEnters, &selectset, &selectSet::selectSetShow);
    QObject::connect(&loginPage, &LoginPage::userEnters, &createPage, &createAccount::closeCreatePage);
    QObject::connect(&loginPage, &LoginPage::userCreateAccount, &createPage, &createAccount::showCreatePage);
    QObject::connect(&createPage, &createAccount::checkNewAccount, &loginPage , &LoginPage::signUserUp);
    QObject::connect(&loginPage, &LoginPage::invalidCreate, &createPage , &createAccount::printErrorType);
    QObject::connect(&selectset, &selectSet::select2Desktop, &desktopPage, &Desktop::showDesktop);


//    loginPage.skipLogin();


    return a.exec();

}

