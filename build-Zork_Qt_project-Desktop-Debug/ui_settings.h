/********************************************************************************
** Form generated from reading UI file 'settings.ui'
**
** Created by: Qt User Interface Compiler version 5.9.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGS_H
#define UI_SETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_settings
{
public:
    QLabel *authors;
    QLabel *label;
    QCheckBox *musicCB;
    QCheckBox *soundfxCB;
    QPushButton *backButton;
    QLabel *zork;
    QCheckBox *debugCB;

    void setupUi(QDialog *settings)
    {
        if (settings->objectName().isEmpty())
            settings->setObjectName(QStringLiteral("settings"));
        settings->resize(290, 340);
        QIcon icon;
        icon.addFile(QStringLiteral(":/zorkIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
        settings->setWindowIcon(icon);
        settings->setStyleSheet(QStringLiteral("background-color: rgb(46, 52, 54);"));
        authors = new QLabel(settings);
        authors->setObjectName(QStringLiteral("authors"));
        authors->setGeometry(QRect(10, 110, 270, 70));
        QFont font;
        font.setFamily(QStringLiteral("Montserrat"));
        font.setBold(false);
        font.setItalic(false);
        font.setUnderline(false);
        font.setWeight(50);
        font.setStrikeOut(false);
        font.setKerning(true);
        authors->setFont(font);
        authors->setAlignment(Qt::AlignCenter);
        label = new QLabel(settings);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 10, 220, 90));
        QFont font1;
        font1.setFamily(QStringLiteral("Montserrat"));
        font1.setPointSize(40);
        font1.setBold(true);
        font1.setItalic(true);
        font1.setWeight(75);
        label->setFont(font1);
        label->setAlignment(Qt::AlignCenter);
        musicCB = new QCheckBox(settings);
        musicCB->setObjectName(QStringLiteral("musicCB"));
        musicCB->setGeometry(QRect(60, 220, 160, 26));
        QFont font2;
        font2.setFamily(QStringLiteral("Montserrat"));
        font2.setPointSize(14);
        musicCB->setFont(font2);
        musicCB->setCheckable(true);
        musicCB->setChecked(true);
        musicCB->setTristate(false);
        soundfxCB = new QCheckBox(settings);
        soundfxCB->setObjectName(QStringLiteral("soundfxCB"));
        soundfxCB->setGeometry(QRect(60, 250, 170, 26));
        soundfxCB->setFont(font2);
        soundfxCB->setChecked(true);
        soundfxCB->setTristate(false);
        backButton = new QPushButton(settings);
        backButton->setObjectName(QStringLiteral("backButton"));
        backButton->setGeometry(QRect(100, 290, 90, 40));
        QFont font3;
        font3.setFamily(QStringLiteral("Montserrat"));
        font3.setPointSize(14);
        font3.setBold(true);
        font3.setWeight(75);
        backButton->setFont(font3);
        zork = new QLabel(settings);
        zork->setObjectName(QStringLiteral("zork"));
        zork->setGeometry(QRect(30, 10, 230, 90));
        zork->setPixmap(QPixmap(QString::fromUtf8("../../Downloads/zorkLogo.png")));
        zork->setScaledContents(true);
        debugCB = new QCheckBox(settings);
        debugCB->setObjectName(QStringLiteral("debugCB"));
        debugCB->setGeometry(QRect(60, 190, 160, 26));
        debugCB->setFont(font2);
        debugCB->setTristate(false);

        retranslateUi(settings);

        QMetaObject::connectSlotsByName(settings);
    } // setupUi

    void retranslateUi(QDialog *settings)
    {
        settings->setWindowTitle(QApplication::translate("settings", "Zork - Settings", Q_NULLPTR));
        authors->setText(QApplication::translate("settings", "2018 \302\251 University of Limerick\n"
"\n"
"Will O'Leary (15155528) \n"
"Aaron Dunne (15148602)", Q_NULLPTR));
        label->setText(QApplication::translate("settings", "Zork", Q_NULLPTR));
        musicCB->setText(QApplication::translate("settings", "Music", Q_NULLPTR));
        soundfxCB->setText(QApplication::translate("settings", "Sound FX", Q_NULLPTR));
        backButton->setText(QApplication::translate("settings", "Back", Q_NULLPTR));
        zork->setText(QString());
        debugCB->setText(QApplication::translate("settings", "Debug Mode", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class settings: public Ui_settings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGS_H
