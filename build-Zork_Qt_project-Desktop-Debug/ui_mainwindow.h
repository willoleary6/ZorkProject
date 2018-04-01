/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.4
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
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionClose;
    QAction *actionUndo_Last_Move;
    QAction *actionNew_Game;
    QAction *actionSettings;
    QAction *actionAbout;
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
    QLabel *gameLogLabel;
    QLabel *inventoryLabel;
    QLabel *itemInRoomLabel;
    QListView *listView;
    QLabel *userInGame;
    QProgressBar *noiseBar;
    QLabel *noiseLabel;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuHelp;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setWindowModality(Qt::WindowModal);
        MainWindow->resize(1200, 680);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(1200, 680));
        QFont font;
        font.setFamily(QStringLiteral("Montserrat"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        MainWindow->setFont(font);
        QIcon icon;
        icon.addFile(QStringLiteral("../../Downloads/images.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setLayoutDirection(Qt::LeftToRight);
        MainWindow->setStyleSheet(QStringLiteral("background-color: rgb(46, 52, 54);"));
        actionClose = new QAction(MainWindow);
        actionClose->setObjectName(QStringLiteral("actionClose"));
        actionUndo_Last_Move = new QAction(MainWindow);
        actionUndo_Last_Move->setObjectName(QStringLiteral("actionUndo_Last_Move"));
        actionNew_Game = new QAction(MainWindow);
        actionNew_Game->setObjectName(QStringLiteral("actionNew_Game"));
        actionSettings = new QAction(MainWindow);
        actionSettings->setObjectName(QStringLiteral("actionSettings"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        westButton = new QPushButton(centralWidget);
        westButton->setObjectName(QStringLiteral("westButton"));
        westButton->setGeometry(QRect(280, 500, 40, 40));
        QFont font1;
        font1.setFamily(QStringLiteral("Montserrat"));
        font1.setPointSize(18);
        font1.setBold(true);
        font1.setWeight(75);
        westButton->setFont(font1);
        eastButton = new QPushButton(centralWidget);
        eastButton->setObjectName(QStringLiteral("eastButton"));
        eastButton->setGeometry(QRect(400, 500, 40, 40));
        eastButton->setFont(font1);
        northButton = new QPushButton(centralWidget);
        northButton->setObjectName(QStringLiteral("northButton"));
        northButton->setGeometry(QRect(340, 440, 40, 40));
        northButton->setFont(font1);
        northButton->setStyleSheet(QStringLiteral("font-color: #666666;"));
        southButton = new QPushButton(centralWidget);
        southButton->setObjectName(QStringLiteral("southButton"));
        southButton->setGeometry(QRect(340, 560, 40, 40));
        southButton->setFont(font1);
        compassLogo = new QLabel(centralWidget);
        compassLogo->setObjectName(QStringLiteral("compassLogo"));
        compassLogo->setGeometry(QRect(320, 480, 80, 80));
        compassLogo->setPixmap(QPixmap(QString::fromUtf8("../../Downloads/compass-2.png")));
        compassLogo->setScaledContents(true);
        inventory = new QListView(centralWidget);
        inventory->setObjectName(QStringLiteral("inventory"));
        inventory->setGeometry(QRect(940, 20, 250, 400));
        inventory->setStyleSheet(QLatin1String("background-color: rgb(35, 39, 41);\n"
"border-style: solid;\n"
"border-width: 2px;\n"
"border-color: rgb(0, 0, 0);\n"
"border-radius: 10px;"));
        gameMap = new QTextEdit(centralWidget);
        gameMap->setObjectName(QStringLiteral("gameMap"));
        gameMap->setGeometry(QRect(940, 440, 250, 160));
        gameMap->setStyleSheet(QLatin1String("background-color: rgb(35, 39, 41);\n"
"border-style: solid;\n"
"border-width: 2px;\n"
"border-color: rgb(0, 0, 0);\n"
"border-radius: 10px;"));
        gameHistory = new QTextEdit(centralWidget);
        gameHistory->setObjectName(QStringLiteral("gameHistory"));
        gameHistory->setGeometry(QRect(10, 440, 250, 160));
        gameHistory->setStyleSheet(QLatin1String("background-color: rgb(35, 39, 41);\n"
"border-style: solid;\n"
"border-width: 2px;\n"
"border-color: rgb(0, 0, 0);\n"
"border-radius: 10px;"));
        mainGameWindow = new QTextEdit(centralWidget);
        mainGameWindow->setObjectName(QStringLiteral("mainGameWindow"));
        mainGameWindow->setGeometry(QRect(280, 20, 640, 400));
        QFont font2;
        font2.setKerning(true);
        mainGameWindow->setFont(font2);
        mainGameWindow->setStyleSheet(QLatin1String("background-color: rgb(35, 39, 41);\n"
"border-style: solid;\n"
"border-width: 2px;\n"
"border-color: rgb(0, 0, 0);\n"
"border-radius: 10px;"));
        gameLogLabel = new QLabel(centralWidget);
        gameLogLabel->setObjectName(QStringLiteral("gameLogLabel"));
        gameLogLabel->setGeometry(QRect(11, 420, 260, 20));
        QFont font3;
        font3.setFamily(QStringLiteral("Montserrat"));
        font3.setPointSize(12);
        font3.setBold(false);
        font3.setWeight(50);
        gameLogLabel->setFont(font3);
        gameLogLabel->setAlignment(Qt::AlignCenter);
        inventoryLabel = new QLabel(centralWidget);
        inventoryLabel->setObjectName(QStringLiteral("inventoryLabel"));
        inventoryLabel->setGeometry(QRect(940, 0, 250, 20));
        inventoryLabel->setFont(font3);
        inventoryLabel->setAlignment(Qt::AlignCenter);
        itemInRoomLabel = new QLabel(centralWidget);
        itemInRoomLabel->setObjectName(QStringLiteral("itemInRoomLabel"));
        itemInRoomLabel->setGeometry(QRect(10, 0, 250, 20));
        itemInRoomLabel->setFont(font3);
        itemInRoomLabel->setAlignment(Qt::AlignCenter);
        listView = new QListView(centralWidget);
        listView->setObjectName(QStringLiteral("listView"));
        listView->setGeometry(QRect(10, 20, 250, 400));
        listView->setStyleSheet(QLatin1String("background-color: rgb(35, 39, 41);\n"
"border-style: solid;\n"
"border-width: 2px;\n"
"border-color: rgb(0, 0, 0);\n"
"border-radius: 10px;"));
        userInGame = new QLabel(centralWidget);
        userInGame->setObjectName(QStringLiteral("userInGame"));
        userInGame->setGeometry(QRect(460, 420, 280, 20));
        QFont font4;
        font4.setFamily(QStringLiteral("Montserrat"));
        font4.setPointSize(12);
        font4.setBold(false);
        font4.setItalic(true);
        font4.setWeight(50);
        font4.setKerning(true);
        userInGame->setFont(font4);
        userInGame->setAlignment(Qt::AlignCenter);
        noiseBar = new QProgressBar(centralWidget);
        noiseBar->setObjectName(QStringLiteral("noiseBar"));
        noiseBar->setGeometry(QRect(720, 580, 200, 20));
        noiseBar->setValue(40);
        noiseBar->setTextVisible(false);
        noiseLabel = new QLabel(centralWidget);
        noiseLabel->setObjectName(QStringLiteral("noiseLabel"));
        noiseLabel->setGeometry(QRect(720, 560, 200, 20));
        QFont font5;
        font5.setFamily(QStringLiteral("Montserrat"));
        font5.setPointSize(12);
        noiseLabel->setFont(font5);
        noiseLabel->setAlignment(Qt::AlignCenter);
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
        gameLogLabel->raise();
        inventoryLabel->raise();
        itemInRoomLabel->raise();
        listView->raise();
        userInGame->raise();
        noiseBar->raise();
        noiseLabel->raise();
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        mainToolBar->setEnabled(false);
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        statusBar->setEnabled(true);
        MainWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1200, 24));
        QFont font6;
        font6.setFamily(QStringLiteral("Montserrat"));
        font6.setPointSize(11);
        font6.setBold(false);
        font6.setWeight(50);
        menuBar->setFont(font6);
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        MainWindow->setMenuBar(menuBar);

        mainToolBar->addSeparator();
        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionNew_Game);
        menuFile->addAction(actionSettings);
        menuFile->addSeparator();
        menuFile->addAction(actionClose);
        menuEdit->addAction(actionUndo_Last_Move);
        menuHelp->addAction(actionAbout);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Zork", Q_NULLPTR));
        actionClose->setText(QApplication::translate("MainWindow", "Close", Q_NULLPTR));
        actionUndo_Last_Move->setText(QApplication::translate("MainWindow", "Undo Last Move", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionUndo_Last_Move->setShortcut(QApplication::translate("MainWindow", "Ctrl+Z", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionNew_Game->setText(QApplication::translate("MainWindow", "New Game", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionNew_Game->setShortcut(QApplication::translate("MainWindow", "Ctrl+N", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionSettings->setText(QApplication::translate("MainWindow", "Settings", Q_NULLPTR));
        actionAbout->setText(QApplication::translate("MainWindow", "About...", Q_NULLPTR));
        westButton->setText(QApplication::translate("MainWindow", "W", Q_NULLPTR));
        eastButton->setText(QApplication::translate("MainWindow", "E", Q_NULLPTR));
        northButton->setText(QApplication::translate("MainWindow", "N", Q_NULLPTR));
        southButton->setText(QApplication::translate("MainWindow", "S", Q_NULLPTR));
        compassLogo->setText(QString());
        gameLogLabel->setText(QApplication::translate("MainWindow", "Log", Q_NULLPTR));
        inventoryLabel->setText(QApplication::translate("MainWindow", "Item Inventory", Q_NULLPTR));
        itemInRoomLabel->setText(QApplication::translate("MainWindow", "Currenet Room Items", Q_NULLPTR));
        userInGame->setText(QApplication::translate("MainWindow", "**player name goes here**", Q_NULLPTR));
        noiseLabel->setText(QApplication::translate("MainWindow", "Nosie-O-Meter", Q_NULLPTR));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", Q_NULLPTR));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Edit", Q_NULLPTR));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
