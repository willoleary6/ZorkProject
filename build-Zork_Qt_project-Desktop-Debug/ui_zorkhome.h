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
    QLabel *label;
    QPushButton *newGameButton;
    QPushButton *exitButton;
    QToolButton *settingsButton;
    QLabel *authors;

    void setupUi(QDialog *zorkHome)
    {
        if (zorkHome->objectName().isEmpty())
            zorkHome->setObjectName(QStringLiteral("zorkHome"));
        zorkHome->resize(400, 300);
        zorkHome->setMinimumSize(QSize(400, 300));
        zorkHome->setMaximumSize(QSize(400, 300));
        QIcon icon;
        icon.addFile(QStringLiteral("../../Downloads/images.png"), QSize(), QIcon::Normal, QIcon::Off);
        zorkHome->setWindowIcon(icon);
        zorkHome->setAutoFillBackground(false);
        zorkHome->setSizeGripEnabled(false);
        label = new QLabel(zorkHome);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 381, 90));
        QFont font;
        font.setFamily(QStringLiteral("Montserrat"));
        font.setPointSize(50);
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        newGameButton = new QPushButton(zorkHome);
        newGameButton->setObjectName(QStringLiteral("newGameButton"));
        newGameButton->setGeometry(QRect(100, 140, 190, 40));
        QFont font1;
        font1.setFamily(QStringLiteral("Montserrat"));
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setWeight(75);
        newGameButton->setFont(font1);
        newGameButton->setMouseTracking(false);
        exitButton = new QPushButton(zorkHome);
        exitButton->setObjectName(QStringLiteral("exitButton"));
        exitButton->setGeometry(QRect(100, 190, 190, 40));
        exitButton->setFont(font1);
        settingsButton = new QToolButton(zorkHome);
        settingsButton->setObjectName(QStringLiteral("settingsButton"));
        settingsButton->setGeometry(QRect(340, 240, 48, 48));
        QFont font2;
        font2.setFamily(QStringLiteral("Montserrat"));
        font2.setPointSize(14);
        settingsButton->setFont(font2);
        QIcon icon1;
        icon1.addFile(QStringLiteral("settings-17-32.png"), QSize(), QIcon::Normal, QIcon::Off);
        settingsButton->setIcon(icon1);
        settingsButton->setIconSize(QSize(32, 32));
        settingsButton->setPopupMode(QToolButton::DelayedPopup);
        settingsButton->setAutoRaise(false);
        settingsButton->setArrowType(Qt::NoArrow);
        authors = new QLabel(zorkHome);
        authors->setObjectName(QStringLiteral("authors"));
        authors->setGeometry(QRect(70, 247, 251, 40));
        QFont font3;
        font3.setFamily(QStringLiteral("Montserrat"));
        font3.setBold(false);
        font3.setItalic(false);
        font3.setUnderline(false);
        font3.setWeight(50);
        font3.setStrikeOut(false);
        font3.setKerning(true);
        authors->setFont(font3);
        authors->setAlignment(Qt::AlignCenter);

        retranslateUi(zorkHome);

        QMetaObject::connectSlotsByName(zorkHome);
    } // setupUi

    void retranslateUi(QDialog *zorkHome)
    {
        zorkHome->setWindowTitle(QApplication::translate("zorkHome", "Zork", Q_NULLPTR));
        label->setText(QApplication::translate("zorkHome", "Zork", Q_NULLPTR));
        newGameButton->setText(QApplication::translate("zorkHome", "New Game", Q_NULLPTR));
        exitButton->setText(QApplication::translate("zorkHome", "Exit", Q_NULLPTR));
        settingsButton->setText(QString());
        authors->setText(QApplication::translate("zorkHome", "2018 \302\251 \n"
"Will O'Leary & Aaron Dunne", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class zorkHome: public Ui_zorkHome {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ZORKHOME_H
