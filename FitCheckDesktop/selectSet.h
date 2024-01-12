#ifndef SELECTSET_H
#define SELECTSET_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QTextBrowser>
#include <QVBoxLayout>
#include <QPalette>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class selectSet; }
QT_END_NAMESPACE


class selectSet : public QMainWindow
{
    Q_OBJECT

public:
    selectSet(QWidget *parent = nullptr);
    ~selectSet();


public slots:
    void selectSetShow(QVector<QString> CurrentUserData);

signals:
    void select2Desktop(QVector<QString> currentUserData, QString selectedSet);

private slots:
    void contToDesktop();
private:
    Ui::selectSet *ui;
    QVector<QString> userData;

};


#endif // SELECTSET_H
