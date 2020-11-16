#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QMessageBox>
#include "currency.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButtonZaloguj_clicked();

    void on_pushButtonWyloguj_clicked();

    void downloadFinished(QNetworkReply*);
private:
    Ui::MainWindow *ui;
    QSqlDatabase database;
    float currencies[7]; //tablica walut

    void getCurrencies();
    int getCurrencyIndex(const QString&);
};
#endif // MAINWINDOW_H
