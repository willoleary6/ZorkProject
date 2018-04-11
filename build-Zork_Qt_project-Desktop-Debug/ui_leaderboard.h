/********************************************************************************
** Form generated from reading UI file 'leaderboard.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LEADERBOARD_H
#define UI_LEADERBOARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_leaderboard
{
public:
    QTableWidget *leadTable;
    QLabel *playerName;
    QLabel *playerTime;
    QLabel *zorkLogo;
    QLabel *leaderboardLabel;
    QPushButton *backButton;

    void setupUi(QDialog *leaderboard)
    {
        if (leaderboard->objectName().isEmpty())
            leaderboard->setObjectName(QStringLiteral("leaderboard"));
        leaderboard->resize(500, 710);
        leaderboard->setMinimumSize(QSize(500, 710));
        leaderboard->setMaximumSize(QSize(500, 710));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/zorkIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
        leaderboard->setWindowIcon(icon);
        leaderboard->setStyleSheet(QStringLiteral("background-color: rgb(79, 87, 88);"));
        leadTable = new QTableWidget(leaderboard);
        leadTable->setObjectName(QStringLiteral("leadTable"));
        leadTable->setGeometry(QRect(50, 150, 400, 500));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(35, 39, 41, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        QBrush brush2(QColor(46, 52, 54, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush2);
        leadTable->setPalette(palette);
        QFont font;
        font.setFamily(QStringLiteral("Montserrat"));
        font.setPointSize(14);
        font.setBold(false);
        font.setWeight(50);
        leadTable->setFont(font);
        leadTable->setStyleSheet(QLatin1String("background-color: rgb(35, 39, 41);\n"
"alternate-background-color: rgb(46, 52, 54);\n"
"border-style: solid;\n"
"border-width: 2px;\n"
"border-color: rgb(0, 0, 0);\n"
"border-radius: 10px;\n"
"color: rgb(255, 255, 255);"));
        leadTable->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        leadTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        leadTable->setAlternatingRowColors(true);
        leadTable->setSelectionMode(QAbstractItemView::NoSelection);
        leadTable->setSelectionBehavior(QAbstractItemView::SelectColumns);
        leadTable->setShowGrid(false);
        leadTable->setSortingEnabled(true);
        leadTable->setColumnCount(0);
        leadTable->horizontalHeader()->setVisible(false);
        leadTable->horizontalHeader()->setCascadingSectionResizes(false);
        leadTable->horizontalHeader()->setHighlightSections(false);
        leadTable->verticalHeader()->setVisible(false);
        leadTable->verticalHeader()->setHighlightSections(false);
        leadTable->verticalHeader()->setProperty("showSortIndicator", QVariant(false));
        playerName = new QLabel(leaderboard);
        playerName->setObjectName(QStringLiteral("playerName"));
        playerName->setGeometry(QRect(50, 120, 200, 30));
        QFont font1;
        font1.setFamily(QStringLiteral("Montserrat"));
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setWeight(75);
        playerName->setFont(font1);
        playerName->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        playerName->setAlignment(Qt::AlignCenter);
        playerTime = new QLabel(leaderboard);
        playerTime->setObjectName(QStringLiteral("playerTime"));
        playerTime->setGeometry(QRect(250, 120, 200, 30));
        playerTime->setFont(font1);
        playerTime->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        playerTime->setAlignment(Qt::AlignCenter);
        zorkLogo = new QLabel(leaderboard);
        zorkLogo->setObjectName(QStringLiteral("zorkLogo"));
        zorkLogo->setGeometry(QRect(20, 20, 140, 70));
        zorkLogo->setPixmap(QPixmap(QString::fromUtf8(":/images/zorkLogo.png")));
        zorkLogo->setScaledContents(true);
        leaderboardLabel = new QLabel(leaderboard);
        leaderboardLabel->setObjectName(QStringLiteral("leaderboardLabel"));
        leaderboardLabel->setGeometry(QRect(150, 20, 330, 70));
        QFont font2;
        font2.setFamily(QStringLiteral("Montserrat"));
        font2.setPointSize(26);
        font2.setBold(true);
        font2.setWeight(75);
        leaderboardLabel->setFont(font2);
        leaderboardLabel->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        leaderboardLabel->setAlignment(Qt::AlignCenter);
        leaderboardLabel->setWordWrap(true);
        backButton = new QPushButton(leaderboard);
        backButton->setObjectName(QStringLiteral("backButton"));
        backButton->setGeometry(QRect(180, 660, 140, 40));
        backButton->setFont(font1);
        backButton->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        leadTable->raise();
        playerName->raise();
        playerTime->raise();
        leaderboardLabel->raise();
        backButton->raise();
        zorkLogo->raise();

        retranslateUi(leaderboard);

        QMetaObject::connectSlotsByName(leaderboard);
    } // setupUi

    void retranslateUi(QDialog *leaderboard)
    {
        leaderboard->setWindowTitle(QApplication::translate("leaderboard", "Zork - Leaderboard", Q_NULLPTR));
        playerName->setText(QApplication::translate("leaderboard", "Player Name", Q_NULLPTR));
        playerTime->setText(QApplication::translate("leaderboard", "Player Time", Q_NULLPTR));
        zorkLogo->setText(QString());
        leaderboardLabel->setText(QApplication::translate("leaderboard", "Game Leaderboard", Q_NULLPTR));
        backButton->setText(QApplication::translate("leaderboard", "Back", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class leaderboard: public Ui_leaderboard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LEADERBOARD_H
