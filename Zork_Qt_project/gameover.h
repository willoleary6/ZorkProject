#ifndef GAMEOVER_H
#define GAMEOVER_H

#include "mainwindow.h"
#include "zorkhome.h"
#include <QDialog>

class zorkHome;
class MainWindow;
namespace Ui {
class gameOver;
}

class gameOver : public QDialog
{
    Q_OBJECT

public:
    explicit gameOver(QWidget *parent = 0);
    ~gameOver();
    void setMainWindow(MainWindow *pa);
    void gameWon(QString timer);
    void gameLost();

private slots:
    void on_playAgainButton_clicked();

    void on_leaderboardButton_clicked();

    void on_mainMenuButton_clicked();

private:
    Ui::gameOver *ui;
    MainWindow *w;
    //void gameWon(QString timer);
    //void gameLost();
};

#endif // GAMEOVER_H
