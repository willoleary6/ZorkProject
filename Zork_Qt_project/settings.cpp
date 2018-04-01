#include "settings.h"
#include "ui_settings.h"
#include "zorkhome.h"
#include <QMediaPlayer>

settings::settings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::settings)
{
    ui->setupUi(this);
}

settings::~settings()
{
    delete ui;
}

void settings::on_backButton_clicked()
{
    close();
}

void settings::on_musicCB_clicked()
{

}
