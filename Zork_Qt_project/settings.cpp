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
    // Checked by default. Mutes bg music if unchecked
}

void settings::on_debugCB_clicked()
{
    // Unchecked by default. Activates teleport if checked
}

void settings::on_soundfxCB_clicked()
{
    // Checked by default. Mutes sound fx if unchecked
}
