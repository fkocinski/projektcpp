#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("../KantorCpp/kantor.db");

    if(!database.open()) 
    {
        qDebug() << "Nie udalo sie otworzyc bazy danych.";
    }
    else 
    {
        qDebug() << "Pomyslnie wczytano baze danych.";
    }

    ui->labelError->setVisible(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::getCurrencies()
{
    QNetworkAccessManager* manager = new QNetworkAccessManager(this);
    connect(manager, &QNetworkAccessManager::finished, this, &MainWindow::downloadFinished);

    QNetworkRequest requestUSD(QUrl("http://api.nbp.pl/api/exchangerates/rates/A/USD/?format=JSON"));
    QNetworkRequest requestEUR(QUrl("http://api.nbp.pl/api/exchangerates/rates/A/EUR/?format=JSON"));
    QNetworkRequest requestCHF(QUrl("http://api.nbp.pl/api/exchangerates/rates/A/CHF/?format=JSON"));
    QNetworkRequest requestCAD(QUrl("http://api.nbp.pl/api/exchangerates/rates/A/CAD/?format=JSON"));
    QNetworkRequest requestGBP(QUrl("http://api.nbp.pl/api/exchangerates/rates/A/GBP/?format=JSON"));
    QNetworkRequest requestJPY(QUrl("http://api.nbp.pl/api/exchangerates/rates/A/JPY/?format=JSON"));
    QNetworkRequest requestCZK(QUrl("http://api.nbp.pl/api/exchangerates/rates/A/CZK/?format=JSON"));

    manager->get(requestUSD);
    manager->get(requestEUR);
    manager->get(requestCHF);
    manager->get(requestCAD);
    manager->get(requestGBP);
    manager->get(requestJPY);
    manager->get(requestCZK);
}

int MainWindow::getCurrencyIndex(const QString& currencyCode) 
{
    if(currencyCode == "USD") return 0;
    if(currencyCode == "EUR") return 1;
    if(currencyCode == "CHF") return 2;
    if(currencyCode == "CAD") return 3;
    if(currencyCode == "GBP") return 4;
    if(currencyCode == "JPY") return 5;
    return 6;         
}

void MainWindow::downloadFinished(QNetworkReply* reply)
{
    QString replyString = reply->readLine(); 
    QStringList replyList = replyString.split(':');:
    QString urlString = reply->url().toString(); 
    QStringList urlList = urlString.split('/'); 
    QString currencyValueString = replyList.value(replyList.size() - 1).left(6); 
    float currency = currencyValueString.toFloat(); 
    QString currencyCode = urlList.value(urlList.size() - 2); 

    currencies[getCurrencyIndex(currencyCode)] = currency;
    qDebug() << "Pobrano: " << currencyCode << " " << currencies[getCurrencyIndex(currencyCode)];
}

void MainWindow::on_pushButtonZaloguj_clicked()
{
    getCurrencies();

    if(ui->lineEditLogin->text().isEmpty() || ui->lineEditHaslo->text().isEmpty())
    {
        QMessageBox::warning(this, "Blad", "Nie podano loginu i/lub hasla.");
        return;
    }

    
    QString username = ui->lineEditLogin->text();
    QString password = ui->lineEditHaslo->text();

    if(!database.isOpen())
    {
        qDebug() << "Nie udalo sie otworzyc bazy danych!";
        return;
    }

    QSqlQuery query;

    if(query.exec("select * from users where username='" + username + "' and password='" + password + "'")) //zapytanie bazy danych o podane dane
    {
        int count = 0;
        while(query.next())
        {
            ++count;
        }
        if(count == 1) 
        {
            ui->labelPowitanie->setText("Witaj ponownie, " + username);
            ui->stackedWidget->setCurrentIndex(1); 
        }
        else 
        {
            ui->labelError->setVisible(true); 
        }
    }
    else
    {
        qDebug() << query.lastError().text();
    }
}

void MainWindow::on_pushButtonWyloguj_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}
