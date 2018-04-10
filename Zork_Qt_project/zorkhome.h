#ifndef ZORKHOME_H
#define ZORKHOME_H
#include <QDialog>
#include "mainwindow.h"
#include "leaderboard.h"
#include <iostream>
#include <QMediaPlaylist>

class leaderboard;
class MainWindow;
namespace Ui {
class zorkHome;
}

class zorkHome : public QDialog
{
    Q_OBJECT

public:
    explicit zorkHome(QWidget *parent = 0);
    ~zorkHome();

private slots:
    void on_newGameButton_clicked();

    void on_exitButton_clicked();

    void on_settingsButton_clicked();

    void on_leaderboardButton_clicked();

private:
    Ui::zorkHome *ui;
};

#endif // ZORKHOME_H
