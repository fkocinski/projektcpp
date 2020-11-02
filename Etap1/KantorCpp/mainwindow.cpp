#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

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


void MainWindow::on_pushButtonZaloguj_clicked()
{
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
