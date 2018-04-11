/********************************************************************************
** Form generated from reading UI file 'zorkhome.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
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
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(zorkHome->sizePolicy().hasHeightForWidth());
        zorkHome->setSizePolicy(sizePolicy);
        zorkHome->setMinimumSize(QSize(520, 260));
        zorkHome->setMaximumSize(QSize(520, 260));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/zorkIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
        zorkHome->setWindowIcon(icon);
        zorkHome->setAutoFillBackground(false);
        zorkHome->setStyleSheet(QStringLiteral("background-color: rgb(79, 87, 88);"));
        zorkHome->setSizeGripEnabled(false);
        newGameButton = new QPushButton(zorkHome);
        newGameButton->setObjectName(QStringLiteral("newGameButton"));
        newGameButton->setGeometry(QRect(300, 40, 200, 40));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(79, 87, 88, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        QBrush brush2(QColor(190, 190, 190, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        newGameButton->setPalette(palette);
        QFont font;
        font.setFamily(QStringLiteral("Montserrat"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        newGameButton->setFont(font);
        newGameButton->setMouseTracking(false);
        exitButton = new QPushButton(zorkHome);
        exitButton->setObjectName(QStringLiteral("exitButton"));
        exitButton->setGeometry(QRect(410, 180, 91, 40));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        exitButton->setPalette(palette1);
        exitButton->setFont(font);
        settingsButton = new QToolButton(zorkHome);
        settingsButton->setObjectName(QStringLiteral("settingsButton"));
        settingsButton->setGeometry(QRect(300, 180, 101, 40));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        settingsButton->setPalette(palette2);
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
        leaderboardButton->setPalette(palette3);
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
        label_2->setGeometry(QRect(40, 140, 210, 20));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette4.setBrush(QPalette::Active, QPalette::Text, brush);
        palette4.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette4.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette4.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette4.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        label_2->setPalette(palette4);
        QFont font1;
        font1.setFamily(QStringLiteral("Montserrat"));
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignCenter);
        zorkLogo = new QLabel(zorkHome);
        zorkLogo->setObjectName(QStringLiteral("zorkLogo"));
        zorkLogo->setGeometry(QRect(30, 0, 250, 110));
        zorkLogo->setFrameShape(QFrame::NoFrame);
        zorkLogo->setPixmap(QPixmap(QString::fromUtf8(":/images/zorkLogo.png")));
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
