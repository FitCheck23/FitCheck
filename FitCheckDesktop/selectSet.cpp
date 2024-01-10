#include "selectSet.h"
#include "ui_selectset.h"


selectSet::selectSet(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::selectSet)
{
    ui->setupUi(this);

    ui->comboBox_set->addItem("Set 1");
    ui->comboBox_set->addItem("Set 2");
    ui->comboBox_set->addItem("Set 3");

    connect(ui->pushButton_cont, SIGNAL(clicked()), this, SLOT(contToDesktop()));
}

selectSet::~selectSet()
{
    delete ui;
}

void selectSet::selectSetShow(QVector<QString> CurrentUserData)
{

    userData = CurrentUserData;
//    this->show();
    emit contToDesktop();

}

void selectSet::contToDesktop()
{
    QString selectedSet = ui->comboBox_set->currentText();

    emit select2Desktop(userData, selectedSet);
//    this->close();
}

