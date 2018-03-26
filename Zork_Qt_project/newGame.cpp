#include "newGame.h"
#include "ui_newGame.h"
#include "zorkhome.h"
#include "mainwindow.h"
#include "ZorkUL.h"
#include <QMessageBox>

newGame::newGame(QWidget *parent) :


    QDialog(parent),
    ui(new Ui::newGame)
{
    ui->setupUi(this);
    currentParent = parent;
}

newGame::~newGame() {
    delete ui;
}

void newGame::on_startGameButton_clicked() {
    QString username = ui->usernameEnter->text();

    if (username.isEmpty())
        QMessageBox::information(this, "Error", "Please enter a username to continue", 2);
    else {

        // Call Main window
        close();
        MainWindow w();
        w.show();
        //ZorkUL zork;
    }
}

void newGame::on_mainMenuButton_clicked() {
    close();
    zorkHome m;
    m.setModal(true);
    m.exec();
}
