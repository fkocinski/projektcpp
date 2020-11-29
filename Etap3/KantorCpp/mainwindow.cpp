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

    currencies[0] = 1;
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
    if(currencyCode == "PLN") return 0;
    if(currencyCode == "USD") return 1;
    if(currencyCode == "EUR") return 2;
    if(currencyCode == "CHF") return 3;
    if(currencyCode == "CAD") return 4;
    if(currencyCode == "GBP") return 5;
    if(currencyCode == "JPY") return 6;
    return 7;         //CZK
}

void MainWindow::downloadFinished(QNetworkReply* reply)
{
    QString replyString = reply->readLine();
    QStringList replyList = replyString.split(':');
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


    username = ui->lineEditLogin->text().toLower();
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
            gotoProfile();
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

void MainWindow::gotoProfile()
{
    ui->labelPowitanie->setText("Witaj ponownie, " + username);



    QSqlQuery query;
    if(query.exec("select PLN, USD, EUR, CHF, CAD, GBP, JPY, CZK from users where username='" + username + "'"))
    {
        while(query.next())
        {
            wallet[0] = query.value(0).toFloat();
            wallet[1] = query.value(1).toFloat();
            wallet[2] = query.value(2).toFloat();
            wallet[3] = query.value(3).toFloat();
            wallet[4] = query.value(4).toFloat();
            wallet[5] = query.value(5).toFloat();
            wallet[6] = query.value(6).toFloat();
            wallet[7] = query.value(7).toFloat();
        }
    }
    else
    {
        qDebug() << query.lastError().text();
    }

    updateWalletLabels();

    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::updateWalletLabels()
{
    ui->labelPLNValue->setText(QString::number(wallet[0]));
    ui->labelUSDValue->setText(QString::number(wallet[1]));
    ui->labelEURValue->setText(QString::number(wallet[2]));
    ui->labelCHFValue->setText(QString::number(wallet[3]));
    ui->labelCADValue->setText(QString::number(wallet[4]));
    ui->labelGBPValue->setText(QString::number(wallet[5]));
    ui->labelJPYValue->setText(QString::number(wallet[6]));
    ui->labelCZKValue->setText(QString::number(wallet[7]));
}

void MainWindow::on_pushButtonWyloguj_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}
