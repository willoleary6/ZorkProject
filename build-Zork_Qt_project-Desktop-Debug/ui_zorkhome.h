/********************************************************************************
** Form generated from reading UI file 'zorkhome.ui'
**
** Created by: Qt User Interface Compiler version 5.9.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ZORKHOME_H
#define UI_ZORKHOME_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolButton>

QT_BEGIN_NAMESPACE

class Ui_zorkHome
{
public:
    QPushButton *newGameButton;
    QPushButton *exitButton;
    QToolButton *settingsButton;
    QPushButton *leaderboardButton;
    QLabel *csisLogo;
    QLabel *label_2;
    QLabel *zorkLogo;

    void setupUi(QDialog *zorkHome)
    {
        if (zorkHome->objectName().isEmpty())
            zorkHome->setObjectName(QStringLiteral("zorkHome"));
        zorkHome->resize(520, 260);
        zorkHome->setMinimumSize(QSize(400, 0));
        zorkHome->setMaximumSize(QSize(600, 300));
        QIcon icon;
        icon.addFile(QStringLiteral(":/zorkIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
        zorkHome->setWindowIcon(icon);
        zorkHome->setAutoFillBackground(false);
        zorkHome->setStyleSheet(QStringLiteral("background-color: rgb(46, 52, 54);"));
        zorkHome->setSizeGripEnabled(false);
        newGameButton = new QPushButton(zorkHome);
        newGameButton->setObjectName(QStringLiteral("newGameButton"));
        newGameButton->setGeometry(QRect(300, 40, 200, 40));
        QFont font;
        font.setFamily(QStringLiteral("Montserrat"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        newGameButton->setFont(font);
        newGameButton->setMouseTracking(false);
        exitButton = new QPushButton(zorkHome);
        exitButton->setObjectName(QStringLiteral("exitButton"));
        exitButton->setGeometry(QRect(410, 180, 90, 40));
        exitButton->setFont(font);
        settingsButton = new QToolButton(zorkHome);
        settingsButton->setObjectName(QStringLiteral("settingsButton"));
        settingsButton->setGeometry(QRect(300, 180, 90, 40));
        settingsButton->setFont(font);
        settingsButton->setAutoFillBackground(false);
        settingsButton->setStyleSheet(QStringLiteral(""));
        settingsButton->setIconSize(QSize(32, 32));
        settingsButton->setPopupMode(QToolButton::DelayedPopup);
        settingsButton->setAutoRaise(false);
        settingsButton->setArrowType(Qt::NoArrow);
        leaderboardButton = new QPushButton(zorkHome);
        leaderboardButton->setObjectName(QStringLiteral("leaderboardButton"));
        leaderboardButton->setGeometry(QRect(300, 110, 200, 40));
        leaderboardButton->setFont(font);
        leaderboardButton->setMouseTracking(false);
        csisLogo = new QLabel(zorkHome);
        csisLogo->setObjectName(QStringLiteral("csisLogo"));
        csisLogo->setGeometry(QRect(70, 150, 160, 100));
        csisLogo->setPixmap(QPixmap(QString::fromUtf8("CSIS.png")));
        csisLogo->setScaledContents(true);
        csisLogo->setOpenExternalLinks(true);
        label_2 = new QLabel(zorkHome);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(60, 140, 180, 20));
        QFont font1;
        font1.setFamily(QStringLiteral("Montserrat"));
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignCenter);
        zorkLogo = new QLabel(zorkHome);
        zorkLogo->setObjectName(QStringLiteral("zorkLogo"));
        zorkLogo->setGeometry(QRect(30, 0, 250, 110));
        zorkLogo->setFrameShape(QFrame::NoFrame);
        zorkLogo->setPixmap(QPixmap(QString::fromUtf8(":/zorkLogo.png")));
        zorkLogo->setScaledContents(true);
        zorkLogo->setOpenExternalLinks(true);

        retranslateUi(zorkHome);

        QMetaObject::connectSlotsByName(zorkHome);
    } // setupUi

    void retranslateUi(QDialog *zorkHome)
    {
        zorkHome->setWindowTitle(QApplication::translate("zorkHome", "Zork", Q_NULLPTR));
        newGameButton->setText(QApplication::translate("zorkHome", "New Game", Q_NULLPTR));
        exitButton->setText(QApplication::translate("zorkHome", "Exit", Q_NULLPTR));
        settingsButton->setText(QApplication::translate("zorkHome", "Settings", Q_NULLPTR));
        leaderboardButton->setText(QApplication::translate("zorkHome", "Leaderboard", Q_NULLPTR));
        csisLogo->setText(QString());
        label_2->setText(QApplication::translate("zorkHome", "A project as part of the", Q_NULLPTR));
        zorkLogo->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class zorkHome: public Ui_zorkHome {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ZORKHOME_H
