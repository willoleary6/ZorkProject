#include "zorkhome.h"
#include "ui_zorkhome.h"
#include "newGame.h"
#include <QtCore>

zorkHome::zorkHome(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::zorkHome)
{
    ui->setupUi(this);
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

}
