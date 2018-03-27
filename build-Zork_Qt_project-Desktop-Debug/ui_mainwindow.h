/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *westButton;
    QPushButton *eastButton;
    QPushButton *northButton;
    QPushButton *southButton;
    QLabel *compassLogo;
    QListView *inventory;
    QTextEdit *gameMap;
    QTextEdit *gameHistory;
    QTextEdit *mainGameWindow;
    QLabel *histroyLabel;
    QLabel *inventoryLabel;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setWindowModality(Qt::WindowModal);
        MainWindow->resize(1200, 650);
        MainWindow->setMinimumSize(QSize(1200, 650));
        QFont font;
        font.setFamily(QStringLiteral("Montserrat"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        MainWindow->setFont(font);
        QIcon icon;
        icon.addFile(QStringLiteral("../../Downloads/images.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        westButton = new QPushButton(centralWidget);
        westButton->setObjectName(QStringLiteral("westButton"));
        westButton->setGeometry(QRect(543, 510, 35, 35));
        eastButton = new QPushButton(centralWidget);
        eastButton->setObjectName(QStringLiteral("eastButton"));
        eastButton->setGeometry(QRect(642, 510, 35, 35));
        northButton = new QPushButton(centralWidget);
        northButton->setObjectName(QStringLiteral("northButton"));
        northButton->setGeometry(QRect(593, 460, 35, 35));
        southButton = new QPushButton(centralWidget);
        southButton->setObjectName(QStringLiteral("southButton"));
        southButton->setGeometry(QRect(593, 560, 35, 35));
        compassLogo = new QLabel(centralWidget);
        compassLogo->setObjectName(QStringLiteral("compassLogo"));
        compassLogo->setGeometry(QRect(580, 498, 60, 60));
        compassLogo->setPixmap(QPixmap(QString::fromUtf8("../../Downloads/compass-2.png")));
        compassLogo->setScaledContents(true);
        inventory = new QListView(centralWidget);
        inventory->setObjectName(QStringLiteral("inventory"));
        inventory->setGeometry(QRect(949, 30, 240, 390));
        gameMap = new QTextEdit(centralWidget);
        gameMap->setObjectName(QStringLiteral("gameMap"));
        gameMap->setGeometry(QRect(949, 440, 240, 160));
        gameHistory = new QTextEdit(centralWidget);
        gameHistory->setObjectName(QStringLiteral("gameHistory"));
        gameHistory->setGeometry(QRect(10, 440, 260, 160));
        mainGameWindow = new QTextEdit(centralWidget);
        mainGameWindow->setObjectName(QStringLiteral("mainGameWindow"));
        mainGameWindow->setGeometry(QRect(290, 29, 641, 391));
        histroyLabel = new QLabel(centralWidget);
        histroyLabel->setObjectName(QStringLiteral("histroyLabel"));
        histroyLabel->setGeometry(QRect(11, 420, 260, 20));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(false);
        font1.setWeight(50);
        histroyLabel->setFont(font1);
        histroyLabel->setAlignment(Qt::AlignCenter);
        inventoryLabel = new QLabel(centralWidget);
        inventoryLabel->setObjectName(QStringLiteral("inventoryLabel"));
        inventoryLabel->setGeometry(QRect(950, 10, 240, 20));
        inventoryLabel->setFont(font1);
        inventoryLabel->setAlignment(Qt::AlignCenter);
        MainWindow->setCentralWidget(centralWidget);
        compassLogo->raise();
        eastButton->raise();
        northButton->raise();
        westButton->raise();
        southButton->raise();
        inventory->raise();
        gameMap->raise();
        gameHistory->raise();
        mainGameWindow->raise();
        histroyLabel->raise();
        inventoryLabel->raise();
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        mainToolBar->setEnabled(true);
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        mainToolBar->addSeparator();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Zork", Q_NULLPTR));
        westButton->setText(QApplication::translate("MainWindow", "W", Q_NULLPTR));
        eastButton->setText(QApplication::translate("MainWindow", "E", Q_NULLPTR));
        northButton->setText(QApplication::translate("MainWindow", "N", Q_NULLPTR));
        southButton->setText(QApplication::translate("MainWindow", "S", Q_NULLPTR));
        compassLogo->setText(QString());
        histroyLabel->setText(QApplication::translate("MainWindow", "History", Q_NULLPTR));
        inventoryLabel->setText(QApplication::translate("MainWindow", "Item Inventory", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
