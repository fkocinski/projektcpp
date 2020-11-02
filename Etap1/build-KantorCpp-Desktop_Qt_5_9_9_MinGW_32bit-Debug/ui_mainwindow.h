/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *pageLogowanie;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *labelLogin;
    QLabel *labelHaslo;
    QPushButton *pushButtonZaloguj;
    QLineEdit *lineEditLogin;
    QLineEdit *lineEditHaslo;
    QLabel *labelLogowanie;
    QLabel *labelError;
    QWidget *pageMenu;
    QLabel *labelKantor;
    QLabel *labelPowitanie;
    QPushButton *pushButtonWyloguj;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 600);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 0, 800, 600));
        sizePolicy.setHeightForWidth(stackedWidget->sizePolicy().hasHeightForWidth());
        stackedWidget->setSizePolicy(sizePolicy);
        stackedWidget->setMinimumSize(QSize(800, 600));
        stackedWidget->setMaximumSize(QSize(800, 600));
        pageLogowanie = new QWidget();
        pageLogowanie->setObjectName(QStringLiteral("pageLogowanie"));
        gridLayoutWidget = new QWidget(pageLogowanie);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(210, 120, 364, 269));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        labelLogin = new QLabel(gridLayoutWidget);
        labelLogin->setObjectName(QStringLiteral("labelLogin"));
        QFont font;
        font.setFamily(QStringLiteral("Calibri"));
        font.setPointSize(18);
        labelLogin->setFont(font);

        gridLayout->addWidget(labelLogin, 1, 0, 1, 1);

        labelHaslo = new QLabel(gridLayoutWidget);
        labelHaslo->setObjectName(QStringLiteral("labelHaslo"));
        labelHaslo->setFont(font);

        gridLayout->addWidget(labelHaslo, 3, 0, 1, 1);

        pushButtonZaloguj = new QPushButton(gridLayoutWidget);
        pushButtonZaloguj->setObjectName(QStringLiteral("pushButtonZaloguj"));
        pushButtonZaloguj->setFont(font);

        gridLayout->addWidget(pushButtonZaloguj, 4, 1, 1, 1);

        lineEditLogin = new QLineEdit(gridLayoutWidget);
        lineEditLogin->setObjectName(QStringLiteral("lineEditLogin"));
        lineEditLogin->setFont(font);

        gridLayout->addWidget(lineEditLogin, 1, 1, 1, 1);

        lineEditHaslo = new QLineEdit(gridLayoutWidget);
        lineEditHaslo->setObjectName(QStringLiteral("lineEditHaslo"));
        lineEditHaslo->setFont(font);
        lineEditHaslo->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(lineEditHaslo, 3, 1, 1, 1);

        labelLogowanie = new QLabel(gridLayoutWidget);
        labelLogowanie->setObjectName(QStringLiteral("labelLogowanie"));
        QFont font1;
        font1.setFamily(QStringLiteral("Calibri"));
        font1.setPointSize(36);
        font1.setBold(true);
        font1.setWeight(75);
        labelLogowanie->setFont(font1);
        labelLogowanie->setTextFormat(Qt::AutoText);
        labelLogowanie->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(labelLogowanie, 0, 1, 1, 1);

        labelLogin->raise();
        labelHaslo->raise();
        lineEditHaslo->raise();
        lineEditLogin->raise();
        pushButtonZaloguj->raise();
        labelLogowanie->raise();
        labelError = new QLabel(pageLogowanie);
        labelError->setObjectName(QStringLiteral("labelError"));
        labelError->setEnabled(true);
        labelError->setGeometry(QRect(260, 420, 321, 31));
        QFont font2;
        font2.setFamily(QStringLiteral("Calibri"));
        font2.setPointSize(20);
        labelError->setFont(font2);
        stackedWidget->addWidget(pageLogowanie);
        pageMenu = new QWidget();
        pageMenu->setObjectName(QStringLiteral("pageMenu"));
        labelKantor = new QLabel(pageMenu);
        labelKantor->setObjectName(QStringLiteral("labelKantor"));
        labelKantor->setGeometry(QRect(310, 20, 181, 51));
        QFont font3;
        font3.setFamily(QStringLiteral("Calibri"));
        font3.setPointSize(48);
        font3.setBold(true);
        font3.setWeight(75);
        labelKantor->setFont(font3);
        labelPowitanie = new QLabel(pageMenu);
        labelPowitanie->setObjectName(QStringLiteral("labelPowitanie"));
        labelPowitanie->setGeometry(QRect(10, 30, 291, 51));
        QFont font4;
        font4.setFamily(QStringLiteral("Calibri"));
        font4.setPointSize(16);
        labelPowitanie->setFont(font4);
        pushButtonWyloguj = new QPushButton(pageMenu);
        pushButtonWyloguj->setObjectName(QStringLiteral("pushButtonWyloguj"));
        pushButtonWyloguj->setGeometry(QRect(610, 40, 131, 31));
        pushButtonWyloguj->setFont(font4);
        stackedWidget->addWidget(pageMenu);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setEnabled(true);
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        statusbar->setEnabled(true);
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Kantor C++", Q_NULLPTR));
        labelLogin->setText(QApplication::translate("MainWindow", "Login:", Q_NULLPTR));
        labelHaslo->setText(QApplication::translate("MainWindow", "Has\305\202o:", Q_NULLPTR));
        pushButtonZaloguj->setText(QApplication::translate("MainWindow", "Zaloguj", Q_NULLPTR));
        labelLogowanie->setText(QApplication::translate("MainWindow", "Logowanie", Q_NULLPTR));
        labelError->setText(QApplication::translate("MainWindow", "Niepoprawny login lub has\305\202o.", Q_NULLPTR));
        labelKantor->setText(QApplication::translate("MainWindow", "Kantor", Q_NULLPTR));
        labelPowitanie->setText(QApplication::translate("MainWindow", "Witaj ponownie, ", Q_NULLPTR));
        pushButtonWyloguj->setText(QApplication::translate("MainWindow", "Wyloguj", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
