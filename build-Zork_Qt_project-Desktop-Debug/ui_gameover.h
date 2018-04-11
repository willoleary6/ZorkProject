/********************************************************************************
** Form generated from reading UI file 'gameover.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEOVER_H
#define UI_GAMEOVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_gameOver
{
public:
    QPushButton *mainMenuButton;
    QPushButton *leaderboardButton;
    QPushButton *playAgainButton;
    QLabel *winLoseLabel;
    QLabel *winLoseHeading;
    QLabel *winLoseText;
    QLabel *playerLabel;
    QLabel *playerTime;
    QLineEdit *playerName;
    QPushButton *saveButton;
    QLabel *scoreSaved;

    void setupUi(QDialog *gameOver)
    {
        if (gameOver->objectName().isEmpty())
            gameOver->setObjectName(QStringLiteral("gameOver"));
        gameOver->resize(500, 380);
        QFont font;
        font.setFamily(QStringLiteral("Montserrat"));
        gameOver->setFont(font);
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/zorkIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
        gameOver->setWindowIcon(icon);
        gameOver->setStyleSheet(QLatin1String("background-color: rgb(79, 87, 88);\n"
"color: rgb(255, 255, 255);"));
        mainMenuButton = new QPushButton(gameOver);
        mainMenuButton->setObjectName(QStringLiteral("mainMenuButton"));
        mainMenuButton->setGeometry(QRect(330, 310, 140, 40));
        QFont font1;
        font1.setFamily(QStringLiteral("Montserrat"));
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setWeight(75);
        mainMenuButton->setFont(font1);
        leaderboardButton = new QPushButton(gameOver);
        leaderboardButton->setObjectName(QStringLiteral("leaderboardButton"));
        leaderboardButton->setGeometry(QRect(180, 310, 140, 40));
        leaderboardButton->setFont(font1);
        playAgainButton = new QPushButton(gameOver);
        playAgainButton->setObjectName(QStringLiteral("playAgainButton"));
        playAgainButton->setGeometry(QRect(30, 310, 140, 40));
        playAgainButton->setFont(font1);
        winLoseLabel = new QLabel(gameOver);
        winLoseLabel->setObjectName(QStringLiteral("winLoseLabel"));
        winLoseLabel->setGeometry(QRect(80, 10, 350, 81));
        QFont font2;
        font2.setFamily(QStringLiteral("Montserrat"));
        font2.setPointSize(40);
        font2.setBold(true);
        font2.setWeight(75);
        winLoseLabel->setFont(font2);
        winLoseLabel->setAlignment(Qt::AlignCenter);
        winLoseHeading = new QLabel(gameOver);
        winLoseHeading->setObjectName(QStringLiteral("winLoseHeading"));
        winLoseHeading->setGeometry(QRect(80, 80, 350, 21));
        QFont font3;
        font3.setFamily(QStringLiteral("Montserrat"));
        font3.setPointSize(14);
        font3.setBold(false);
        font3.setWeight(50);
        winLoseHeading->setFont(font3);
        winLoseHeading->setAlignment(Qt::AlignCenter);
        winLoseText = new QLabel(gameOver);
        winLoseText->setObjectName(QStringLiteral("winLoseText"));
        winLoseText->setGeometry(QRect(60, 110, 390, 100));
        winLoseText->setFont(font);
        winLoseText->setAlignment(Qt::AlignCenter);
        winLoseText->setWordWrap(true);
        playerLabel = new QLabel(gameOver);
        playerLabel->setObjectName(QStringLiteral("playerLabel"));
        playerLabel->setGeometry(QRect(150, 250, 130, 21));
        playerLabel->setFont(font1);
        playerTime = new QLabel(gameOver);
        playerTime->setObjectName(QStringLiteral("playerTime"));
        playerTime->setGeometry(QRect(280, 250, 70, 21));
        QFont font4;
        font4.setFamily(QStringLiteral("Montserrat"));
        font4.setPointSize(14);
        playerTime->setFont(font4);
        playerTime->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        playerName = new QLineEdit(gameOver);
        playerName->setObjectName(QStringLiteral("playerName"));
        playerName->setGeometry(QRect(50, 220, 270, 30));
        QFont font5;
        font5.setFamily(QStringLiteral("Montserrat"));
        font5.setPointSize(15);
        font5.setBold(false);
        font5.setItalic(false);
        font5.setWeight(50);
        playerName->setFont(font5);
        playerName->setStyleSheet(QStringLiteral("background-color: rgb(46, 52, 54);"));
        playerName->setMaxLength(16);
        playerName->setAlignment(Qt::AlignCenter);
        saveButton = new QPushButton(gameOver);
        saveButton->setObjectName(QStringLiteral("saveButton"));
        saveButton->setGeometry(QRect(330, 220, 120, 30));
        QFont font6;
        font6.setFamily(QStringLiteral("Montserrat"));
        font6.setBold(true);
        font6.setWeight(75);
        saveButton->setFont(font6);
        scoreSaved = new QLabel(gameOver);
        scoreSaved->setObjectName(QStringLiteral("scoreSaved"));
        scoreSaved->setGeometry(QRect(150, 280, 200, 19));
        QFont font7;
        font7.setFamily(QStringLiteral("Montserrat"));
        font7.setItalic(true);
        scoreSaved->setFont(font7);
        scoreSaved->setStyleSheet(QStringLiteral("color: rgb(237, 212, 0);"));
        scoreSaved->setAlignment(Qt::AlignCenter);
        mainMenuButton->raise();
        leaderboardButton->raise();
        playAgainButton->raise();
        winLoseLabel->raise();
        winLoseText->raise();
        playerLabel->raise();
        playerTime->raise();
        winLoseHeading->raise();
        playerName->raise();
        saveButton->raise();
        scoreSaved->raise();

        retranslateUi(gameOver);

        QMetaObject::connectSlotsByName(gameOver);
    } // setupUi

    void retranslateUi(QDialog *gameOver)
    {
        gameOver->setWindowTitle(QApplication::translate("gameOver", "Game Over", Q_NULLPTR));
        mainMenuButton->setText(QApplication::translate("gameOver", "Main Menu", Q_NULLPTR));
        leaderboardButton->setText(QApplication::translate("gameOver", "Leaderboard", Q_NULLPTR));
        playAgainButton->setText(QApplication::translate("gameOver", "Play Again", Q_NULLPTR));
        winLoseLabel->setText(QApplication::translate("gameOver", "Text", Q_NULLPTR));
        winLoseHeading->setText(QApplication::translate("gameOver", "Text", Q_NULLPTR));
        winLoseText->setText(QApplication::translate("gameOver", "Text", Q_NULLPTR));
        playerLabel->setText(QApplication::translate("gameOver", "Your time :", Q_NULLPTR));
        playerTime->setText(QApplication::translate("gameOver", "0:00", Q_NULLPTR));
        playerName->setPlaceholderText(QApplication::translate("gameOver", "Enter Player name here", Q_NULLPTR));
        saveButton->setText(QApplication::translate("gameOver", "Save Score", Q_NULLPTR));
        scoreSaved->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class gameOver: public Ui_gameOver {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEOVER_H
