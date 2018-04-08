#include "settings.h"
#include "ui_settings.h"

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

void settings::on_debugCB_clicked()
{
   // Activates teleport
}

void settings::on_musicCB_clicked()
{
    // Toggles game music
}

void settings::on_soundfxCB_clicked()
{
    // Toggles game sound fx
}
