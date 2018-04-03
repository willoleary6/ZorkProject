#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "newGame.h"
#include "settings.h"
#include <QMessageBox>
#include <QPixmap>
#include <QImage>
#include <QtCore>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
    {
        ui->setupUi(this);
        ZorkUL *game = new ZorkUL();
        //game->play();
        delete game;
        //cout << "finish" << endl;
        //game.play();
        //updateMap();
    }

MainWindow::~MainWindow()
{
    cout << "test" << endl;
    delete ui;
}
void MainWindow::updateMap(){
    ui->gameMap->clear();
    ui->gameMap->append("");
}

void MainWindow::on_actionClose_triggered()
{
    close();
}

void MainWindow::on_actionSettings_triggered()
{
    settings s;
    s.setModal(true);
    s.exec();
}

void MainWindow::on_actionAbout_triggered()
{
    QImage ulLogo(":/ul_White.png");
    QImage image = ulLogo.scaled(150, 150, Qt::KeepAspectRatio);

    QMessageBox about;
    about.setIconPixmap(QPixmap::fromImage(image));
    about.setText("Zork");
    about.setWindowTitle("About Zork");
    about.setInformativeText("2018 © University of Limerick.\n\nWilliam O'Leary (15155528)\nAaron Dunne (15148602)");
    about.show();
    about.exec();

}
