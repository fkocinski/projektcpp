#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //ladowanie bazy danych z informacjami o kontach uzytkownikow
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("../KantorCpp/kantor.db");

    if(!database.open()) //jezeli nie udalo sie otworzyc bazy danych
    {
        qDebug() << "Nie udalo sie otworzyc bazy danych.";
    }
    else //jezeli pomyslnie wczytano baze danych
    {
        qDebug() << "Pomyslnie wczytano baze danych.";
    }

    ui->labelError->setVisible(false);

    currencies[0] = 1; //wszystkie kursy sa przeliczane na PLN, zatem kurs PLN = 1

    ui->comboBoxWaluta->addItem("USD");
    ui->comboBoxWaluta->addItem("EUR");
    ui->comboBoxWaluta->addItem("CHF");
    ui->comboBoxWaluta->addItem("GBP");
    ui->comboBoxWaluta->addItem("CAD");
    ui->comboBoxWaluta->addItem("JPY");
    ui->comboBoxWaluta->addItem("CZK");
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

int MainWindow::getCurrencyIndex(const QString& currencyCode) //funkcja przypisujaca walucie miejsce w tablicy currencies
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
    QString replyString = reply->readLine(); //odpowiedz w formacie JSON
    QStringList replyList = replyString.split(':'); //podzial odpowiedzi przy kazdym znaku :
    QString urlString = reply->url().toString(); //URL, z ktorego otrzymalismy odpowiedz
    QStringList urlList = urlString.split('/'); //podzial url przy kazdym znaku /
    QString currencyValueString = replyList.value(replyList.size() - 1).left(6); //wartosc waluty
    float currency = currencyValueString.toFloat(); //zamiana waluty na liczbe float
    QString currencyCode = urlList.value(urlList.size() - 2); //trzyliterowy kod waluty (np. USD)

    currencies[getCurrencyIndex(currencyCode)] = currency; //umieszczenie kursu na odpowiednim miejscu w tablicy
    qDebug() << "Pobrano: " << currencyCode << " " << currencies[getCurrencyIndex(currencyCode)];
}

void MainWindow::on_pushButtonZaloguj_clicked()
{
    getCurrencies();

    if(ui->lineEditLogin->text().isEmpty() || ui->lineEditHaslo->text().isEmpty()) //jezeli nie podano loginu lub hasla
    {
        QMessageBox::warning(this, "Blad", "Nie podano loginu i/lub hasla.");
        return;
    }

    //zapisanie danych podanych przez uzytkownika do zmiennych
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
        if(count == 1) //dane logowania sa prawidlowe
        {
            gotoProfile();
        }
        else //dane logowania sa nieprawidlowe
        {
            ui->labelError->setVisible(true); //wyswietlanie bledu
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

    //uzupelnienie portfela o dane z bazy danych

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

    fillComboBox(ui->comboBoxWalutaL);

    ui->stackedWidget->setCurrentIndex(1); //przejscie do profilu uzytkownika
}

void MainWindow::gotoCharts()
{
    ui->stackedWidget->setCurrentIndex(2);
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

void MainWindow::fillComboBox(QComboBox* comboBox)
{
    comboBox->clear();
    comboBox->addItems({"PLN", "USD", "EUR", "CHF", "CAD", "GBP", "JPY", "CZK"});
}

void MainWindow::on_pushButtonWyloguj_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_comboBoxWalutaL_currentIndexChanged(const int index)
{
    fillComboBox(ui->comboBoxWalutaR);
    ui->comboBoxWalutaR->removeItem(index);
    ui->doubleSpinBoxKwota->setMaximum(wallet[index]);
}

void MainWindow::on_pushButtonWymien_clicked()
{
    const float value = ui->doubleSpinBoxKwota->value();

    if(value <= 0) //jezeli kwota jest nie wieksza niz zero - zakoncz
    {
        return;
    }

    const int leftCurrencyIndex = ui->comboBoxWalutaL->currentIndex(); //indeks waluty sprzedawanej
    const int rightCurrencyIndex = getCurrencyIndex(ui->comboBoxWalutaR->currentText()); //indeks waluty kupowanej

    const float leftCurrecyValue = value * currencies[leftCurrencyIndex]; //przeliczenie sprzedawanej waluty na PLN

    wallet[leftCurrencyIndex] -= value; //odjecie odpowiedniej wartosci z portfela waluty sprzedawanej
    wallet[rightCurrencyIndex] += leftCurrecyValue / currencies[rightCurrencyIndex]; //dodanie odpowiedniej wartosci do portfela waluty kupowanej

    //aktualizacja danych w bazie danych
    QSqlQuery query;

    query.prepare("update users set PLN = ?, USD = ?, EUR = ?, CHF = ?, CAD = ?, GBP = ?, JPY = ?, CZK = ? where username='" + username + "'");

    for(int i = 0; i < 8; i++) //wypelnianie miejsc ? kolejnymi wartosciami walut w portfelu
    {
        query.addBindValue(wallet[i]);
    }

    if(!query.exec())
    {
        qDebug() << query.lastError().text();
    }

    //aktualizacja wyswietlanych danych
    updateWalletLabels();
    ui->doubleSpinBoxKwota->setMaximum(wallet[leftCurrencyIndex]);
}

void MainWindow::on_pushButtonWykresy_clicked()
{
    gotoCharts();
}

void MainWindow::on_pushButtonPowrot_clicked()
{
    gotoProfile();
}

void MainWindow::on_pushButtonRysuj_clicked()
{
    drawChart();
}

QString MainWindow::getStartDate()
{
    QDate today = QDate::currentDate();
    QDate start = today.addDays(-30);

    QString result;

    result += QString::number(start.year());
    result += "-";
    result += QString::number(start.month());
    result += "-";
    result += QString::number(start.day());

    return result;
}

QString MainWindow::getEndDate()
{
    QDate today = QDate::currentDate();
    QString result;

    result += QString::number(today.year());
    result += "-";
    result += QString::number(today.month());
    result += "-";
    result += QString::number(today.day());

    return result;
}

void MainWindow::getLast30(const QString& currencyCode)
{
    QNetworkAccessManager* manager = new QNetworkAccessManager(this);
    connect(manager, &QNetworkAccessManager::finished, this, &MainWindow::chartDataDownloadFinished);

    QNetworkRequest request(QUrl("http://api.nbp.pl/api/exchangerates/rates/A/" + currencyCode + "/last/30/?format=json"));
    manager->get(request);
}

void MainWindow::drawChart()
{
    series = new QLineSeries();

    //pobranie ostatnich 30 kursow wybranej waluty do tablicy values
    getLast30(ui->comboBoxWaluta->currentText());

    //stworzenie nowego wykresu
    chart = new QChart();
    chart->legend()->hide();
    chart->addSeries(series);
    chart->createDefaultAxes();
    chart->setTitle("Ostatnie 30 kursów");

    QChartView* chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    //wyswietlenie gotowego wykresu
    ui->graphicsViewWykres->setViewport(chartView);
}

void MainWindow::chartDataDownloadFinished(QNetworkReply* reply)
{
    QString replyString = reply->readAll(); //wczytanie calej odpowiedzi do stringa
    QStringList replyList = replyString.split("\"mid\":"); //podzial odpowiedzi w miejscach wystepowania "mid":

    values.clear(); //przygotowanie listy
    for(int i = 1; i < replyList.size(); i++) //iterowanie po wszystkich stringach powstalych po podziale replyString
    {
        float value = replyList[i].left(5).toFloat(); //zamiana kursu na liczbe float
        values.append(value); //dodanie do listy values
    }

    //dodanie wartosci do serii
    for(int i = 0; i < values.size(); i++)
    {
        series->append(i + 1, values[i]);
    }

    float min = *std::min_element(values.begin(), values.end());
    float max = *std::max_element(values.begin(), values.end());

    chart->axisX()->setRange(1, 30);
    chart->axisY()->setRange(min, max);
}
