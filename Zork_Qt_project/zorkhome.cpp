#include "zorkhome.h"
#include "ui_zorkhome.h"
#include "settings.h"
#include <QPixmap>
#include <QtCore>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QMessageBox>
#include <QDesktopWidget>

using namespace std;

zorkHome::zorkHome(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::zorkHome)
{
    ui->setupUi(this);

    QPixmap zork (":/images/zorkLogo.png");
    QPixmap csis(":/images/CSIS.png");
    ui->zorkLogo->setPixmap(zork);
    ui->csisLogo->setPixmap(csis);
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Game Background music
    QMediaPlaylist *gameMusic = new QMediaPlaylist();
    gameMusic->addMedia(QUrl("qrc:/sounds/Power Glove - Power Core.mp3"));
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
    MainWindow *w = new MainWindow();
    w->move(QApplication::desktop()->screen()->rect().center() - w->rect().center());
    w->show();
}

void zorkHome::on_exitButton_clicked()
{
    QMessageBox confirmExit;
    confirmExit.setWindowTitle("Exit Zork");
    confirmExit.setText("Are you sure you want to quit Zork?");
    confirmExit.setStyleSheet("color : white; background : rgb(79, 87, 88)");
    confirmExit.setIcon(QMessageBox::Question);
    confirmExit.setStandardButtons(QMessageBox::Cancel | QMessageBox::Close);
    confirmExit.setDefaultButton(QMessageBox::Cancel);
    int ret = confirmExit.exec();

    switch (ret) {
        case QMessageBox::Cancel:
            break;
        case QMessageBox::Close:
            close();
        break;
    }
}

void zorkHome::on_settingsButton_clicked()
{
    settings s;
    s.setModal(true);
    s.exec();
}

void zorkHome::on_leaderboardButton_clicked()
{
    leaderboard l;
    l.readFile();
    l.exec();
}
