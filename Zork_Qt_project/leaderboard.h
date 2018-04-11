#ifndef LEADERBOARD_H
#define LEADERBOARD_H

#include "gameover.h"
#include <QDialog>
#include <QString>
#include <QIODevice>
#include <QTextStream>
#include <QFile>
#include <QTableWidget>


class gameOver;
namespace Ui {
class leaderboard;
}

class leaderboard : public QDialog
{
    Q_OBJECT

public:
    explicit leaderboard(QWidget *parent = 0);
    ~leaderboard();
    void readFile();
    void writeFile(QString playerName, QString timer);

private slots:
    void on_backButton_clicked();

private:
    Ui::leaderboard *ui;
};

#endif // LEADERBOARD_H
