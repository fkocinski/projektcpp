#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QMessageBox>
#include <QtCharts>

using namespace QtCharts;

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

    void chartDataDownloadFinished(QNetworkReply*);

    void on_comboBoxWalutaL_currentIndexChanged(int index);

    void on_pushButtonWymien_clicked();

    void on_pushButtonWykresy_clicked();

    void on_pushButtonPowrot_clicked();

    void on_pushButtonRysuj_clicked();

private:
    Ui::MainWindow *ui;
    QSqlDatabase database;
    float currencies[8]; //tablica walut
    float wallet[8]; //portfel
    QString username; //nazwa aktulanie zalogowanego uzytkownika
    QList<float> values; //ostatnie 30 kursow wybranej waluty
    QLineSeries* series; //seria danych w wykresie
    QChart* chart; //wykres

    void getCurrencies();
    int getCurrencyIndex(const QString&);
    void gotoProfile();
    void gotoCharts();
    void updateWalletLabels();
    void fillComboBox(QComboBox*);
    void drawChart();
    void getLast30(const QString&);
    QString getStartDate();
    QString getEndDate();
};
#endif // MAINWINDOW_H
