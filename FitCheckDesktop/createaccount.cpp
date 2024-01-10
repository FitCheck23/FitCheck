#include "createaccount.h"
#include "ui_createAccount.h"

createAccount::createAccount(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::createAccount)
{
    ui->setupUi(this);
    connect(ui->pushButton_createAccount,SIGNAL(clicked()),this,SLOT(createAccount_clicked()));
    ui->textBrowser_checkNewUser->clear();
    QPalette palette = ui->textBrowser_checkNewUser->palette();
    palette.setColor(QPalette::Base, QColor(255, 255, 255, 0)); // 0 alpha makes it fully transparent
    ui->textBrowser_checkNewUser->setPalette(palette);

    ui->logo->setGeometry((this->width()-500)/2, (this->height()-1100)/2, 500, 400);
    ui->frame->setGeometry((this->width()-675)/2, (this->height()-300)/2, 665, 1800);
    this->ui->lineEdit_newEmail->setStyleSheet("QLineEdit{ border-width: 2px; border-style: solid; border-color: white; color: white; }");
    this->ui->lineEdit_newPassword->setStyleSheet("QLineEdit{ border-width: 2px; border-style: solid; border-color: white; color: white; }");
    this->ui->lineEdit_newName->setStyleSheet("QLineEdit{ border-width: 2px; border-style: solid; border-color: white; color: white; }");
    this->ui->lineEdit_newAge->setStyleSheet("QLineEdit{ border-width: 2px; border-style: solid; border-color: white; color: white; }");
    this->ui->lineEdit_newHeight->setStyleSheet("QLineEdit{ border-width: 2px; border-style: solid; border-color: white; color: white; }");
    this->ui->lineEdit_newWeight->setStyleSheet("QLineEdit{ border-width: 2px; border-style: solid; border-color: white; color: white; }");
    this->setStyleSheet("background-color: #001D2B;");
//    ui->verticalLayout_3->setAlignment(Qt::AlignCenter);
    this->ui->pushButton_createAccount->setStyleSheet("QPushButton {background-color: #555657; color: white;} QPushButton:hover {background-color: #66c011;}");
}

void createAccount::showCreatePage(){
    this->show();
}

void createAccount::closeCreatePage(){
    this->close();
}

createAccount::~createAccount()
{
    delete ui;
}

void createAccount::printErrorType(const QString &errorType)
{
    ui->textBrowser_checkNewUser->setText(errorType);
}


void createAccount::createAccount_clicked()
{
    newEmail = ui->lineEdit_newEmail->text();
    newPassword = ui->lineEdit_newPassword->text();
    newName = ui->lineEdit_newName->text();
    newAge = ui->lineEdit_newAge->text();
    newHeight = ui->lineEdit_newHeight->text();
    newWeight = ui->lineEdit_newWeight->text();
    emit checkNewAccount(newEmail, newPassword, newName, newAge, newHeight, newWeight);
}
