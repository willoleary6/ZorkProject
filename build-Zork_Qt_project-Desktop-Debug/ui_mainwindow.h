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
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionExit;
    QAction *actionNew_Game;
    QAction *actionSettings;
    QAction *actionAbout;
    QAction *actionQuit_Game;
    QWidget *centralWidget;
    QPushButton *westButton;
    QPushButton *eastButton;
    QPushButton *northButton;
    QPushButton *southButton;
    QLabel *compassLogo;
    QTextEdit *gameMap;
    QTextEdit *gameHistory;
    QTextEdit *mainGameWindow;
    QLabel *gameLogLabel;
    QTreeWidget *roomItems;
    QPushButton *upstairsButton;
    QPushButton *downstairsButton;
    QTreeWidget *inventory;
    QPushButton *escapeButton;
    QLCDNumber *countdown;
    QLabel *gameLogLabel_2;
    QLabel *gameLogLabel_3;
    QLabel *label;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *menuFile;
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
        icon.addFile(QStringLiteral(":/images/zorkIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setLayoutDirection(Qt::LeftToRight);
        MainWindow->setStyleSheet(QStringLiteral("background-color: rgb(79, 87, 88);"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionNew_Game = new QAction(MainWindow);
        actionNew_Game->setObjectName(QStringLiteral("actionNew_Game"));
        actionSettings = new QAction(MainWindow);
        actionSettings->setObjectName(QStringLiteral("actionSettings"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        actionQuit_Game = new QAction(MainWindow);
        actionQuit_Game->setObjectName(QStringLiteral("actionQuit_Game"));
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
        westButton->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        eastButton = new QPushButton(centralWidget);
        eastButton->setObjectName(QStringLiteral("eastButton"));
        eastButton->setGeometry(QRect(400, 500, 40, 40));
        eastButton->setFont(font1);
        eastButton->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        northButton = new QPushButton(centralWidget);
        northButton->setObjectName(QStringLiteral("northButton"));
        northButton->setGeometry(QRect(340, 440, 40, 40));
        northButton->setFont(font1);
        northButton->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        southButton = new QPushButton(centralWidget);
        southButton->setObjectName(QStringLiteral("southButton"));
        southButton->setGeometry(QRect(340, 560, 40, 40));
        southButton->setFont(font1);
        southButton->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        compassLogo = new QLabel(centralWidget);
        compassLogo->setObjectName(QStringLiteral("compassLogo"));
        compassLogo->setGeometry(QRect(320, 480, 80, 80));
        compassLogo->setPixmap(QPixmap(QString::fromUtf8(":/images/compass.png")));
        compassLogo->setScaledContents(true);
        gameMap = new QTextEdit(centralWidget);
        gameMap->setObjectName(QStringLiteral("gameMap"));
        gameMap->setGeometry(QRect(709, 440, 481, 171));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(gameMap->sizePolicy().hasHeightForWidth());
        gameMap->setSizePolicy(sizePolicy1);
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(35, 39, 41, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Light, brush);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush);
        QBrush brush2(QColor(127, 127, 127, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush2);
        QBrush brush3(QColor(170, 170, 170, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush3);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush);
        QBrush brush4(QColor(0, 0, 0, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush4);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush);
        QBrush brush5(QColor(255, 255, 220, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush5);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush4);
        gameMap->setPalette(palette);
        gameMap->setStyleSheet(QLatin1String("background-color: rgb(35, 39, 41);\n"
"border-style: solid;\n"
"border-width: 2px;\n"
"border-color: rgb(0, 0, 0);\n"
"border-radius: 10px;"));
        gameMap->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        gameMap->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        gameMap->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        gameMap->setReadOnly(true);
        gameHistory = new QTextEdit(centralWidget);
        gameHistory->setObjectName(QStringLiteral("gameHistory"));
        gameHistory->setGeometry(QRect(10, 440, 250, 171));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush4);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Light, brush);
        palette1.setBrush(QPalette::Active, QPalette::Midlight, brush);
        palette1.setBrush(QPalette::Active, QPalette::Dark, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Mid, brush3);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        palette1.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush4);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Shadow, brush4);
        palette1.setBrush(QPalette::Active, QPalette::AlternateBase, brush);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipBase, brush5);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipText, brush4);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush4);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Light, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Midlight, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Dark, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Mid, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush4);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Shadow, brush4);
        palette1.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush5);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Light, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Midlight, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Dark, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Mid, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Shadow, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush5);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush4);
        gameHistory->setPalette(palette1);
        gameHistory->setStyleSheet(QLatin1String("background-color: rgb(35, 39, 41);\n"
"border-style: solid;\n"
"border-width: 2px;\n"
"border-color: rgb(0, 0, 0);\n"
"border-radius: 10px;"));
        gameHistory->setReadOnly(true);
        mainGameWindow = new QTextEdit(centralWidget);
        mainGameWindow->setObjectName(QStringLiteral("mainGameWindow"));
        mainGameWindow->setGeometry(QRect(280, 20, 640, 400));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        QBrush brush6(QColor(190, 190, 190, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush6);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush6);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        mainGameWindow->setPalette(palette2);
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
        font3.setBold(true);
        font3.setWeight(75);
        gameLogLabel->setFont(font3);
        gameLogLabel->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        gameLogLabel->setAlignment(Qt::AlignCenter);
        roomItems = new QTreeWidget(centralWidget);
        QFont font4;
        font4.setFamily(QStringLiteral("Piboto Light"));
        font4.setPointSize(13);
        font4.setBold(true);
        font4.setWeight(75);
        font4.setKerning(false);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setTextAlignment(0, Qt::AlignCenter);
        __qtreewidgetitem->setFont(0, font4);
        __qtreewidgetitem->setBackground(0, QColor(79, 87, 88));
        roomItems->setHeaderItem(__qtreewidgetitem);
        roomItems->setObjectName(QStringLiteral("roomItems"));
        roomItems->setGeometry(QRect(10, 20, 250, 400));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette3.setBrush(QPalette::Active, QPalette::Light, brush);
        palette3.setBrush(QPalette::Active, QPalette::Midlight, brush);
        palette3.setBrush(QPalette::Active, QPalette::Dark, brush2);
        palette3.setBrush(QPalette::Active, QPalette::Mid, brush3);
        palette3.setBrush(QPalette::Active, QPalette::Text, brush);
        palette3.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette3.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette3.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette3.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette3.setBrush(QPalette::Active, QPalette::Shadow, brush4);
        palette3.setBrush(QPalette::Active, QPalette::AlternateBase, brush);
        palette3.setBrush(QPalette::Active, QPalette::ToolTipBase, brush5);
        palette3.setBrush(QPalette::Active, QPalette::ToolTipText, brush4);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Light, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Midlight, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Dark, brush2);
        palette3.setBrush(QPalette::Inactive, QPalette::Mid, brush3);
        palette3.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Shadow, brush4);
        palette3.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush5);
        palette3.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush4);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Light, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::Midlight, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::Dark, brush2);
        palette3.setBrush(QPalette::Disabled, QPalette::Mid, brush3);
        palette3.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Shadow, brush4);
        palette3.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush5);
        palette3.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush4);
        roomItems->setPalette(palette3);
        roomItems->setStyleSheet(QLatin1String("background-color: rgb(35, 39, 41);\n"
"border-style: solid;\n"
"border-width: 2px;\n"
"border-color: rgb(0, 0, 0);\n"
"border-radius: 10px;\n"
"color: rgb(255, 255, 255);"));
        roomItems->header()->setVisible(false);
        upstairsButton = new QPushButton(centralWidget);
        upstairsButton->setObjectName(QStringLiteral("upstairsButton"));
        upstairsButton->setGeometry(QRect(400, 440, 40, 40));
        upstairsButton->setFont(font1);
        upstairsButton->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        downstairsButton = new QPushButton(centralWidget);
        downstairsButton->setObjectName(QStringLiteral("downstairsButton"));
        downstairsButton->setGeometry(QRect(280, 560, 40, 40));
        downstairsButton->setFont(font1);
        downstairsButton->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        inventory = new QTreeWidget(centralWidget);
        QFont font5;
        font5.setFamily(QStringLiteral("Piboto Light"));
        font5.setPointSize(13);
        font5.setBold(true);
        font5.setWeight(75);
        QTreeWidgetItem *__qtreewidgetitem1 = new QTreeWidgetItem();
        __qtreewidgetitem1->setTextAlignment(0, Qt::AlignCenter);
        __qtreewidgetitem1->setFont(0, font5);
        __qtreewidgetitem1->setBackground(0, QColor(79, 87, 88));
        inventory->setHeaderItem(__qtreewidgetitem1);
        inventory->setObjectName(QStringLiteral("inventory"));
        inventory->setGeometry(QRect(940, 20, 250, 400));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette4.setBrush(QPalette::Active, QPalette::Light, brush);
        palette4.setBrush(QPalette::Active, QPalette::Midlight, brush);
        palette4.setBrush(QPalette::Active, QPalette::Dark, brush2);
        palette4.setBrush(QPalette::Active, QPalette::Mid, brush3);
        palette4.setBrush(QPalette::Active, QPalette::Text, brush);
        palette4.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette4.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette4.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette4.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette4.setBrush(QPalette::Active, QPalette::Shadow, brush4);
        palette4.setBrush(QPalette::Active, QPalette::AlternateBase, brush);
        palette4.setBrush(QPalette::Active, QPalette::ToolTipBase, brush5);
        palette4.setBrush(QPalette::Active, QPalette::ToolTipText, brush4);
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::Light, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Midlight, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Dark, brush2);
        palette4.setBrush(QPalette::Inactive, QPalette::Mid, brush3);
        palette4.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::Shadow, brush4);
        palette4.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush5);
        palette4.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush4);
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::Light, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::Midlight, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::Dark, brush2);
        palette4.setBrush(QPalette::Disabled, QPalette::Mid, brush3);
        palette4.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::Shadow, brush4);
        palette4.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush5);
        palette4.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush4);
        inventory->setPalette(palette4);
        inventory->setStyleSheet(QLatin1String("background-color: rgb(35, 39, 41);\n"
"border-style: solid;\n"
"border-width: 2px;\n"
"border-color: rgb(0, 0, 0);\n"
"border-radius: 10px;\n"
"color: rgb(255, 255, 255);"));
        inventory->header()->setVisible(false);
        escapeButton = new QPushButton(centralWidget);
        escapeButton->setObjectName(QStringLiteral("escapeButton"));
        escapeButton->setGeometry(QRect(490, 560, 171, 41));
        escapeButton->setFont(font1);
        escapeButton->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        countdown = new QLCDNumber(centralWidget);
        countdown->setObjectName(QStringLiteral("countdown"));
        countdown->setGeometry(QRect(580, 440, 111, 51));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(countdown->sizePolicy().hasHeightForWidth());
        countdown->setSizePolicy(sizePolicy2);
        countdown->setMinimumSize(QSize(0, 50));
        QFont font6;
        font6.setPointSize(30);
        font6.setBold(true);
        font6.setWeight(75);
        countdown->setFont(font6);
        countdown->setStyleSheet(QLatin1String("background-color: rgb(35, 39, 41);\n"
"border-style: solid;\n"
"border-width: 2px;\n"
"border-color: rgb(0, 0, 0);\n"
"border-radius: 10px;\n"
"color: rgb(255, 255, 255);"));
        gameLogLabel_2 = new QLabel(centralWidget);
        gameLogLabel_2->setObjectName(QStringLiteral("gameLogLabel_2"));
        gameLogLabel_2->setGeometry(QRect(900, 420, 100, 20));
        sizePolicy.setHeightForWidth(gameLogLabel_2->sizePolicy().hasHeightForWidth());
        gameLogLabel_2->setSizePolicy(sizePolicy);
        gameLogLabel_2->setFont(font3);
        gameLogLabel_2->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        gameLogLabel_2->setAlignment(Qt::AlignCenter);
        gameLogLabel_3 = new QLabel(centralWidget);
        gameLogLabel_3->setObjectName(QStringLiteral("gameLogLabel_3"));
        gameLogLabel_3->setGeometry(QRect(460, 0, 260, 20));
        gameLogLabel_3->setFont(font3);
        gameLogLabel_3->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        gameLogLabel_3->setAlignment(Qt::AlignCenter);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(510, 440, 69, 51));
        QFont font7;
        font7.setFamily(QStringLiteral("DejaVu Sans Condensed"));
        font7.setBold(true);
        font7.setWeight(75);
        label->setFont(font7);
        label->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
""));
        label->setAlignment(Qt::AlignCenter);
        label->setWordWrap(true);
        MainWindow->setCentralWidget(centralWidget);
        compassLogo->raise();
        eastButton->raise();
        northButton->raise();
        westButton->raise();
        southButton->raise();
        gameMap->raise();
        gameHistory->raise();
        mainGameWindow->raise();
        gameLogLabel->raise();
        roomItems->raise();
        upstairsButton->raise();
        downstairsButton->raise();
        inventory->raise();
        escapeButton->raise();
        countdown->raise();
        gameLogLabel_2->raise();
        gameLogLabel_3->raise();
        label->raise();
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
        menuBar->setGeometry(QRect(0, 0, 1200, 23));
        QFont font8;
        font8.setFamily(QStringLiteral("Montserrat"));
        font8.setPointSize(11);
        font8.setBold(false);
        font8.setWeight(50);
        menuBar->setFont(font8);
        menuBar->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        MainWindow->setMenuBar(menuBar);

        mainToolBar->addSeparator();
        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionNew_Game);
        menuFile->addAction(actionQuit_Game);
        menuFile->addAction(actionSettings);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuHelp->addAction(actionAbout);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Zork", Q_NULLPTR));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", Q_NULLPTR));
        actionNew_Game->setText(QApplication::translate("MainWindow", "New Game", Q_NULLPTR));
        actionNew_Game->setShortcut(QApplication::translate("MainWindow", "Ctrl+N", Q_NULLPTR));
        actionSettings->setText(QApplication::translate("MainWindow", "Settings", Q_NULLPTR));
        actionSettings->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", Q_NULLPTR));
        actionAbout->setText(QApplication::translate("MainWindow", "About...", Q_NULLPTR));
        actionQuit_Game->setText(QApplication::translate("MainWindow", "Quit Game", Q_NULLPTR));
        actionQuit_Game->setShortcut(QApplication::translate("MainWindow", "Ctrl+C", Q_NULLPTR));
        westButton->setText(QApplication::translate("MainWindow", "W", Q_NULLPTR));
        eastButton->setText(QApplication::translate("MainWindow", "E", Q_NULLPTR));
        northButton->setText(QApplication::translate("MainWindow", "N", Q_NULLPTR));
        southButton->setText(QApplication::translate("MainWindow", "S", Q_NULLPTR));
        compassLogo->setText(QString());
        gameLogLabel->setText(QApplication::translate("MainWindow", "Log", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem = roomItems->headerItem();
        ___qtreewidgetitem->setText(0, QApplication::translate("MainWindow", "Room Items", Q_NULLPTR));
        upstairsButton->setText(QApplication::translate("MainWindow", "\342\206\221", Q_NULLPTR));
        downstairsButton->setText(QApplication::translate("MainWindow", "\342\206\223", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem1 = inventory->headerItem();
        ___qtreewidgetitem1->setText(0, QApplication::translate("MainWindow", "Inventory", Q_NULLPTR));
        escapeButton->setText(QApplication::translate("MainWindow", "Escape!", Q_NULLPTR));
        gameLogLabel_2->setText(QApplication::translate("MainWindow", "Map", Q_NULLPTR));
        gameLogLabel_3->setText(QApplication::translate("MainWindow", "Display", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Time Left", Q_NULLPTR));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", Q_NULLPTR));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
