#include "gameover.h"
#include "ui_gameover.h"
#include <QDesktopWidget>
#include <QMessageBox>

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

//  Function for player winning the game
void gameOver::gameWon(QString timer) {
    //  Should the player win the game, the following objects are modifed and presented.
    QPixmap winL(":/images/ThumbUpLeft.png");
    QPixmap winR(":/images/ThumbUpRight.png");

    ui->winLoseLabel->setText("Success!");
    ui->image1->setPixmap(winL);
    ui->image2->setPixmap(winR);
    ui->winLoseHeading->setText("You have escaped the house");
    ui->winLoseText->setText("You have managed to find your escape form the kidnapper's house can now rush to your freedom (or in your case, a few pints at the Stables with the lads). And in good time too!");
    ui->playerTime->setText(timer);
    ui->saveButton->show();
}

//  Function for player losing the game
void gameOver::gameLost() {
    //  Should the player lose the game, the following objects are modifed and presented
    QPixmap lose(":/images/redX.png");

    ui->winLoseLabel->setText("Caught!");
    ui->image1->setPixmap(lose);
    ui->image2->setPixmap(lose);
    ui->winLoseHeading->setText("You failed to make it out in time");
    ui->winLoseText->setText("Tough luck. The kidnapper has found you after trying to escape ad it is now likely that you will never make it out alive. Ah well, you had a good run. T'was nice knowing ya.");
    ui->playerName->hide();
    ui->saveButton->hide();
    ui->playerLabel->hide();
    ui->playerTime->hide();
}

//  Play Again button
void gameOver::on_playAgainButton_clicked() {
    //  Closes the dialog and creates a new game
    this->close();
    w = new MainWindow();
    w->move(QApplication::desktop()->screen()->rect().center() - w->rect().center());
    w->show();
}

//  Leaderboard button
void gameOver::on_leaderboardButton_clicked() {
    //  Displays the leaderboard
    leaderboard l;
    l.readFile();
    l.exec();
}

//  Main Menu button
void gameOver::on_mainMenuButton_clicked() {
    //  Closes the dialog and returns the player to the Zork main menu
    this->close();
    zorkHome z;
    z.exec();
}

//  Save Score button
void gameOver::on_saveButton_clicked() {
    /*
     *  Only visible if the player wins the game. The player is required to provide a
     *  username in the provided text field to save their time to the leaderboard. The
     *  player then saves the chosen username along with the time to the .csv file.
     */

    QString player, playerTime;
    player = ui->playerName->text();        //  Copys player's username to QString player
    playerTime = ui->playerTime->text();    //  Copys player's time to QString playerTime

    //  Checks if player is empty. If so, an error message is shown
    if (player.isEmpty()) {
        QMessageBox::warning(this, "Error", "Please enter a username to continue");
    }
    else {
        //  Writes the player name and time to the leaderboard.csv file, then notifies the player.
        leaderboard l;
        l.writeFile(player, playerTime);
        ui->scoreSaved->setText("Score saved successfully");
    }
}
