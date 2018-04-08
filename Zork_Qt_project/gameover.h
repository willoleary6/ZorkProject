#ifndef GAMEOVER_H
#define GAMEOVER_H

#include "mainwindow.h"
#include <QDialog>

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

private:
    Ui::gameOver *ui;
};

#endif // GAMEOVER_H
