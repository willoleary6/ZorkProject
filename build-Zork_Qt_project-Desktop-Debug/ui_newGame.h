/********************************************************************************
** Form generated from reading UI file 'newGame.ui'
**
** Created by: Qt User Interface Compiler version 5.9.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWGAME_H
#define UI_NEWGAME_H

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

class Ui_newGame
{
public:
    QLabel *userLabel;
    QLabel *zorkLogo;
    QPushButton *startGameButton;
    QLabel *newGameLabel;
    QPushButton *mainMenuButton;
    QLineEdit *usernameEnter;

    void setupUi(QDialog *newGame)
    {
        if (newGame->objectName().isEmpty())
            newGame->setObjectName(QStringLiteral("newGame"));
        newGame->resize(400, 300);
        newGame->setFocusPolicy(Qt::NoFocus);
        newGame->setStyleSheet(QStringLiteral("background-color: rgb(46, 52, 54);"));
        userLabel = new QLabel(newGame);
        userLabel->setObjectName(QStringLiteral("userLabel"));
        userLabel->setGeometry(QRect(90, 120, 230, 20));
        QFont font;
        font.setFamily(QStringLiteral("Montserrat"));
        font.setPointSize(12);
        font.setBold(false);
        font.setWeight(50);
        userLabel->setFont(font);
        userLabel->setContextMenuPolicy(Qt::NoContextMenu);
        userLabel->setLayoutDirection(Qt::LeftToRight);
        userLabel->setTextFormat(Qt::AutoText);
        userLabel->setAlignment(Qt::AlignCenter);
        zorkLogo = new QLabel(newGame);
        zorkLogo->setObjectName(QStringLiteral("zorkLogo"));
        zorkLogo->setGeometry(QRect(90, 0, 230, 100));
        QFont font1;
        font1.setFamily(QStringLiteral("Montserrat"));
        font1.setPointSize(50);
        font1.setBold(true);
        font1.setItalic(true);
        font1.setWeight(75);
        zorkLogo->setFont(font1);
        zorkLogo->setPixmap(QPixmap(QString::fromUtf8(":/zorkLogo.png")));
        zorkLogo->setScaledContents(true);
        zorkLogo->setAlignment(Qt::AlignCenter);
        startGameButton = new QPushButton(newGame);
        startGameButton->setObjectName(QStringLiteral("startGameButton"));
        startGameButton->setGeometry(QRect(110, 190, 190, 40));
        QFont font2;
        font2.setFamily(QStringLiteral("Montserrat"));
        font2.setPointSize(14);
        font2.setBold(true);
        font2.setWeight(75);
        startGameButton->setFont(font2);
        newGameLabel = new QLabel(newGame);
        newGameLabel->setObjectName(QStringLiteral("newGameLabel"));
        newGameLabel->setGeometry(QRect(90, 93, 231, 20));
        QFont font3;
        font3.setFamily(QStringLiteral("Montserrat"));
        font3.setPointSize(14);
        newGameLabel->setFont(font3);
        newGameLabel->setAlignment(Qt::AlignCenter);
        mainMenuButton = new QPushButton(newGame);
        mainMenuButton->setObjectName(QStringLiteral("mainMenuButton"));
        mainMenuButton->setGeometry(QRect(110, 240, 190, 40));
        mainMenuButton->setFont(font2);
        usernameEnter = new QLineEdit(newGame);
        usernameEnter->setObjectName(QStringLiteral("usernameEnter"));
        usernameEnter->setGeometry(QRect(90, 142, 230, 40));
        usernameEnter->setMinimumSize(QSize(230, 40));
        usernameEnter->setMaximumSize(QSize(230, 40));
        usernameEnter->setFont(font3);
        usernameEnter->setLayoutDirection(Qt::LeftToRight);
        usernameEnter->setStyleSheet(QStringLiteral("background-color: rgb(35, 39, 41);"));
        usernameEnter->setAlignment(Qt::AlignCenter);

        retranslateUi(newGame);

        QMetaObject::connectSlotsByName(newGame);
    } // setupUi

    void retranslateUi(QDialog *newGame)
    {
        newGame->setWindowTitle(QApplication::translate("newGame", "Zork - New Game", Q_NULLPTR));
#ifndef QT_NO_WHATSTHIS
        userLabel->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_ACCESSIBILITY
        userLabel->setAccessibleName(QString());
#endif // QT_NO_ACCESSIBILITY
#ifndef QT_NO_ACCESSIBILITY
        userLabel->setAccessibleDescription(QString());
#endif // QT_NO_ACCESSIBILITY
        userLabel->setText(QApplication::translate("newGame", "Enter username:", Q_NULLPTR));
        zorkLogo->setText(QString());
        startGameButton->setText(QApplication::translate("newGame", "Start Game", Q_NULLPTR));
        newGameLabel->setText(QApplication::translate("newGame", "New Game", Q_NULLPTR));
        mainMenuButton->setText(QApplication::translate("newGame", "Main Menu", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class newGame: public Ui_newGame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWGAME_H
