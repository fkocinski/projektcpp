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
    QWidget *pageProfil;
    QLabel *labelKantor;
    QLabel *labelPowitanie;
    QPushButton *pushButtonWyloguj;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QLabel *labelJPYValue;
    QLabel *labelGBPValue;
    QLabel *labelCHF;
    QLabel *labelUSD;
    QLabel *labelEUR;
    QLabel *labelGBP;
    QLabel *labelCZK;
    QLabel *labelPLNValue;
    QLabel *labelEURValue;
    QLabel *labelPLN;
    QLabel *labelUSDValue;
    QLabel *labelCHFValue;
    QLabel *labelJPY;
    QLabel *labelCADValue;
    QLabel *labelCZKValue;
    QLabel *labelCAD;
    QLabel *labelPortfel;
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
        pageProfil = new QWidget();
        pageProfil->setObjectName(QStringLiteral("pageProfil"));
        labelKantor = new QLabel(pageProfil);
        labelKantor->setObjectName(QStringLiteral("labelKantor"));
        labelKantor->setGeometry(QRect(310, 20, 181, 51));
        QFont font3;
        font3.setFamily(QStringLiteral("Calibri"));
        font3.setPointSize(48);
        font3.setBold(true);
        font3.setWeight(75);
        labelKantor->setFont(font3);
        labelPowitanie = new QLabel(pageProfil);
        labelPowitanie->setObjectName(QStringLiteral("labelPowitanie"));
        labelPowitanie->setGeometry(QRect(20, 30, 281, 51));
        labelPowitanie->setFont(font);
        pushButtonWyloguj = new QPushButton(pageProfil);
        pushButtonWyloguj->setObjectName(QStringLiteral("pushButtonWyloguj"));
        pushButtonWyloguj->setGeometry(QRect(610, 40, 131, 31));
        QFont font4;
        font4.setFamily(QStringLiteral("Calibri"));
        font4.setPointSize(16);
        pushButtonWyloguj->setFont(font4);
        gridLayoutWidget_2 = new QWidget(pageProfil);
        gridLayoutWidget_2->setObjectName(QStringLiteral("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(100, 170, 181, 315));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        labelJPYValue = new QLabel(gridLayoutWidget_2);
        labelJPYValue->setObjectName(QStringLiteral("labelJPYValue"));
        labelJPYValue->setFont(font);

        gridLayout_2->addWidget(labelJPYValue, 7, 1, 1, 1);

        labelGBPValue = new QLabel(gridLayoutWidget_2);
        labelGBPValue->setObjectName(QStringLiteral("labelGBPValue"));
        labelGBPValue->setFont(font);

        gridLayout_2->addWidget(labelGBPValue, 6, 1, 1, 1);

        labelCHF = new QLabel(gridLayoutWidget_2);
        labelCHF->setObjectName(QStringLiteral("labelCHF"));
        labelCHF->setMaximumSize(QSize(60, 16777215));
        labelCHF->setFont(font);

        gridLayout_2->addWidget(labelCHF, 4, 0, 1, 1);

        labelUSD = new QLabel(gridLayoutWidget_2);
        labelUSD->setObjectName(QStringLiteral("labelUSD"));
        labelUSD->setMaximumSize(QSize(60, 16777215));
        labelUSD->setFont(font);

        gridLayout_2->addWidget(labelUSD, 2, 0, 1, 1);

        labelEUR = new QLabel(gridLayoutWidget_2);
        labelEUR->setObjectName(QStringLiteral("labelEUR"));
        labelEUR->setMaximumSize(QSize(60, 16777215));
        labelEUR->setFont(font);

        gridLayout_2->addWidget(labelEUR, 3, 0, 1, 1);

        labelGBP = new QLabel(gridLayoutWidget_2);
        labelGBP->setObjectName(QStringLiteral("labelGBP"));
        labelGBP->setMaximumSize(QSize(60, 16777215));
        labelGBP->setFont(font);

        gridLayout_2->addWidget(labelGBP, 6, 0, 1, 1);

        labelCZK = new QLabel(gridLayoutWidget_2);
        labelCZK->setObjectName(QStringLiteral("labelCZK"));
        labelCZK->setMaximumSize(QSize(60, 16777215));
        labelCZK->setFont(font);

        gridLayout_2->addWidget(labelCZK, 8, 0, 1, 1);

        labelPLNValue = new QLabel(gridLayoutWidget_2);
        labelPLNValue->setObjectName(QStringLiteral("labelPLNValue"));
        labelPLNValue->setFont(font);

        gridLayout_2->addWidget(labelPLNValue, 1, 1, 1, 1);

        labelEURValue = new QLabel(gridLayoutWidget_2);
        labelEURValue->setObjectName(QStringLiteral("labelEURValue"));
        labelEURValue->setFont(font);

        gridLayout_2->addWidget(labelEURValue, 3, 1, 1, 1);

        labelPLN = new QLabel(gridLayoutWidget_2);
        labelPLN->setObjectName(QStringLiteral("labelPLN"));
        labelPLN->setMaximumSize(QSize(60, 16777215));
        labelPLN->setFont(font);

        gridLayout_2->addWidget(labelPLN, 1, 0, 1, 1);

        labelUSDValue = new QLabel(gridLayoutWidget_2);
        labelUSDValue->setObjectName(QStringLiteral("labelUSDValue"));
        labelUSDValue->setFont(font);

        gridLayout_2->addWidget(labelUSDValue, 2, 1, 1, 1);

        labelCHFValue = new QLabel(gridLayoutWidget_2);
        labelCHFValue->setObjectName(QStringLiteral("labelCHFValue"));
        labelCHFValue->setFont(font);

        gridLayout_2->addWidget(labelCHFValue, 4, 1, 1, 1);

        labelJPY = new QLabel(gridLayoutWidget_2);
        labelJPY->setObjectName(QStringLiteral("labelJPY"));
        labelJPY->setMaximumSize(QSize(60, 16777215));
        labelJPY->setFont(font);

        gridLayout_2->addWidget(labelJPY, 7, 0, 1, 1);

        labelCADValue = new QLabel(gridLayoutWidget_2);
        labelCADValue->setObjectName(QStringLiteral("labelCADValue"));
        labelCADValue->setFont(font);

        gridLayout_2->addWidget(labelCADValue, 5, 1, 1, 1);

        labelCZKValue = new QLabel(gridLayoutWidget_2);
        labelCZKValue->setObjectName(QStringLiteral("labelCZKValue"));
        labelCZKValue->setFont(font);

        gridLayout_2->addWidget(labelCZKValue, 8, 1, 1, 1);

        labelCAD = new QLabel(gridLayoutWidget_2);
        labelCAD->setObjectName(QStringLiteral("labelCAD"));
        labelCAD->setMaximumSize(QSize(60, 16777215));
        labelCAD->setFont(font);

        gridLayout_2->addWidget(labelCAD, 5, 0, 1, 1);

        labelPortfel = new QLabel(pageProfil);
        labelPortfel->setObjectName(QStringLiteral("labelPortfel"));
        labelPortfel->setGeometry(QRect(100, 130, 146, 34));
        labelPortfel->setFont(font2);
        stackedWidget->addWidget(pageProfil);
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
        labelJPYValue->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        labelGBPValue->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        labelCHF->setText(QApplication::translate("MainWindow", "CHF:", Q_NULLPTR));
        labelUSD->setText(QApplication::translate("MainWindow", "USD:", Q_NULLPTR));
        labelEUR->setText(QApplication::translate("MainWindow", "EUR:", Q_NULLPTR));
        labelGBP->setText(QApplication::translate("MainWindow", "GBP:", Q_NULLPTR));
        labelCZK->setText(QApplication::translate("MainWindow", "CZK:", Q_NULLPTR));
        labelPLNValue->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        labelEURValue->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        labelPLN->setText(QApplication::translate("MainWindow", "PLN:", Q_NULLPTR));
        labelUSDValue->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        labelCHFValue->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        labelJPY->setText(QApplication::translate("MainWindow", "JPY:", Q_NULLPTR));
        labelCADValue->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        labelCZKValue->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        labelCAD->setText(QApplication::translate("MainWindow", "CAD:", Q_NULLPTR));
        labelPortfel->setText(QApplication::translate("MainWindow", "Stan portfela:", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
