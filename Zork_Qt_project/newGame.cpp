#include "newGame.h"
#include "ui_newGame.h"
#include "zorkhome.h"
#include "mainwindow.h"
#include "ZorkUL.h"
#include <QMessageBox>
#include <QPixmap>
#include <QDesktopWidget>

newGame::newGame(QWidget *parent) :


    QDialog(parent),
    ui(new Ui::newGame)
{
    ui->setupUi(this);
    currentParent = parent;

    QPixmap zork(":/zorkLogo.png");
    ui->zorkLogo->setPixmap(zork);
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
        cout << "test" << endl;
        MainWindow *w = new MainWindow(this);
        w->move(QApplication::desktop()->screen()->rect().center() - w->rect().center());
        w->show();
        //MainWindow w();
        //w.show();
        //ZorkUL zork;
    }
}

void newGame::on_mainMenuButton_clicked() {
    close();
    zorkHome m;
    m.setModal(true);
    m.exec();
}
