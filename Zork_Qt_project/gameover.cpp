#include "gameover.h"
#include "ui_gameover.h"

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
