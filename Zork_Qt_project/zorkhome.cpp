#include "zorkhome.h"
#include "ui_zorkhome.h"
#include "newGame.h"
#include "settings.h"
#include <QPixmap>
#include <QMediaPlayer>
#include <QMessageBox>
#include <QMediaPlaylist>
#include <QtCore>

zorkHome::zorkHome(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::zorkHome)
{
    ui->setupUi(this);


    button = new QMediaPlayer();
    button->setMedia(QUrl("qrc:/sounds/buttonClick.mp3"));
    button->setVolume(50);
    // Looking at efficient ways to duplicate across whole game


    QPixmap zork (":/zorkLogo.png");
    QPixmap csis(":/CSIS.png");
    ui->zorkLogo->setPixmap(zork);
    ui->csisLogo->setPixmap(csis);
}

zorkHome::~zorkHome()
{
    delete ui;
}

void zorkHome::on_newGameButton_clicked()
{
    button->play();
    close();
    newGame ng;
    ng.setModal(true);
    ng.exec();
}

void zorkHome::on_exitButton_clicked()
{
    button->play();
    // Popup for Exit button
    QMessageBox ex;
    ex.setText("Are you sure you wish to exit Zork?");
    ex.setWindowTitle("Exit Zork");
    ex.setStandardButtons(QMessageBox::Close | QMessageBox::Cancel);
    ex.setDefaultButton(QMessageBox::Cancel);
    int ret = ex.exec();

    switch (ret) {
        case QMessageBox::Cancel:
            button->play();
            break;
        case QMessageBox::Close:
            close();
            break;
    }
}

void zorkHome::on_settingsButton_clicked()
{
    button->play();
    settings s;
    s.setModal(true);
    s.exec();
}

void zorkHome::on_leaderboardButton_clicked()
{
    button->play();
}
