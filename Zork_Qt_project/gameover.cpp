#include "gameover.h"
#include "ui_gameover.h"
#include <QDesktopWidget>

gameOver::gameOver(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gameOver)
{
    ui->setupUi(this);
    
}

gameOver::~gameOver()
{
    delete ui;
}

void gameOver::gameWon(QString timer) {
    ui->winLoseLabel->setText("Success!");
    ui->winLoseHeading->setText("You have escaped the house");
    ui->winLoseText->setText("You have managed to find your escape form the kidnapper's house can now rush to your freedom (or in your case, a few pints at the Stables with the lads). And in good time too!");
    ui->playerTime->setText(timer);
    //ui->bestTime->setText();
}

void gameOver::gameLost() {
    ui->winLoseLabel->setText("Caught!");
    ui->winLoseHeading->setText("You failed to make it out in time");
    ui->winLoseText->setText("Tough luck. The kidnapper has found you after trying to escape ad it is now likely that you will never make it out alive. T'was nice knowing ya.");
    ui->playerLabel->hide();
    ui->playerTime->hide();
    ui->bestLabel->hide();
    ui->bestTime->hide();
    //ui->bestTime->setText();
}

void gameOver::on_playAgainButton_clicked()
{
    this->close();
    MainWindow *w = new MainWindow();
    w->move(QApplication::desktop()->screen()->rect().center() - w->rect().center());
    w->show();
}

void gameOver::on_leaderboardButton_clicked()
{

}

void gameOver::on_mainMenuButton_clicked()
{
    this->close();
    zorkHome z;
    z.exec();
}
