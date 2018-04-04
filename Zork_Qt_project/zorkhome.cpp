#include "zorkhome.h"
#include "ui_zorkhome.h"
#include "newGame.h"
#include "settings.h"
#include <QPixmap>
#include <QtCore>
#include <QMediaPlayer>
#include <QMediaPlaylist>

using namespace std;

zorkHome::zorkHome(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::zorkHome)
{
    ui->setupUi(this);

    QPixmap zork (":/zorkLogo.png");
    QPixmap csis(":/CSIS.png");
    ui->zorkLogo->setPixmap(zork);
    ui->csisLogo->setPixmap(csis);
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Game Background music
    QMediaPlaylist *gameMusic = new QMediaPlaylist();
    gameMusic->addMedia(QUrl("qrc:/sounds/gameMusic_Power Core.mp3"));
    gameMusic->setPlaybackMode(QMediaPlaylist::Loop);

    QMediaPlayer *soundtrack = new QMediaPlayer();
    soundtrack->setPlaylist(gameMusic);
    soundtrack->setVolume(50);
    soundtrack->play();

    // UI
    zorkHome n;
    n.show();
    return a.exec();
}
zorkHome::~zorkHome()
{
    delete ui;
}

void zorkHome::on_newGameButton_clicked()
{
    close();
    newGame ng;
    ng.setModal(true);
    ng.exec();
}

void zorkHome::on_exitButton_clicked()
{
    close();
}

void zorkHome::on_settingsButton_clicked()
{
    settings s;
    s.setModal(true);
    s.exec();
}

void zorkHome::on_leaderboardButton_clicked()
{

}
