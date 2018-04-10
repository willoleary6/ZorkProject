/********************************************************************************
** Form generated from reading UI file 'newGame.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
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
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/zorkIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
        newGame->setWindowIcon(icon);
        newGame->setStyleSheet(QStringLiteral("background-color: rgb(79, 87, 88);"));
        userLabel = new QLabel(newGame);
        userLabel->setObjectName(QStringLiteral("userLabel"));
        userLabel->setGeometry(QRect(90, 120, 230, 20));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(79, 87, 88, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        QBrush brush2(QColor(190, 190, 190, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        userLabel->setPalette(palette);
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
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        startGameButton->setPalette(palette1);
        QFont font2;
        font2.setFamily(QStringLiteral("Montserrat"));
        font2.setPointSize(14);
        font2.setBold(true);
        font2.setWeight(75);
        startGameButton->setFont(font2);
        newGameLabel = new QLabel(newGame);
        newGameLabel->setObjectName(QStringLiteral("newGameLabel"));
        newGameLabel->setGeometry(QRect(90, 93, 231, 20));
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
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        newGameLabel->setPalette(palette2);
        QFont font3;
        font3.setFamily(QStringLiteral("Montserrat"));
        font3.setPointSize(14);
        newGameLabel->setFont(font3);
        newGameLabel->setAlignment(Qt::AlignCenter);
        mainMenuButton = new QPushButton(newGame);
        mainMenuButton->setObjectName(QStringLiteral("mainMenuButton"));
        mainMenuButton->setGeometry(QRect(110, 240, 190, 40));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette3.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette3.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette3.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette3.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        mainMenuButton->setPalette(palette3);
        mainMenuButton->setFont(font2);
        usernameEnter = new QLineEdit(newGame);
        usernameEnter->setObjectName(QStringLiteral("usernameEnter"));
        usernameEnter->setGeometry(QRect(90, 142, 230, 40));
        usernameEnter->setMinimumSize(QSize(230, 40));
        usernameEnter->setMaximumSize(QSize(230, 40));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush3(QColor(35, 39, 41, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette4.setBrush(QPalette::Active, QPalette::Button, brush3);
        palette4.setBrush(QPalette::Active, QPalette::Text, brush);
        palette4.setBrush(QPalette::Active, QPalette::Base, brush3);
        palette4.setBrush(QPalette::Active, QPalette::Window, brush3);
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Button, brush3);
        palette4.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Base, brush3);
        palette4.setBrush(QPalette::Inactive, QPalette::Window, brush3);
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette4.setBrush(QPalette::Disabled, QPalette::Button, brush3);
        palette4.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette4.setBrush(QPalette::Disabled, QPalette::Base, brush3);
        palette4.setBrush(QPalette::Disabled, QPalette::Window, brush3);
        usernameEnter->setPalette(palette4);
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
        usernameEnter->setPlaceholderText(QApplication::translate("newGame", "Username", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class newGame: public Ui_newGame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWGAME_H
