#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "settings.h"
#include <QMessageBox>
#include <QPixmap>
#include <QImage>
#include <QtCore>
#include <QString>
#include <QToolButton>
#include <QTextStream>
#include <QDesktopWidget>

//main constructor
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
    {
        ui->setupUi(this);
        try{
            game = new ZorkUL(this);
        }catch(const exception e){
            cout << "failed" << endl;
        }
        ui->countdown->hide();
        minutes = 2;
        seconds = 0;
        timer = new QTimer(this);
        connect(timer,SIGNAL(timeout()),this,SLOT(showTime()));
        timer->start(1000);

        initialiseUI();

    }

//initialising the mainwindow
void MainWindow::initialiseUI(){
        game->getMap();
        game->printWelcome();
        ValidButtons();
        buildInventoryAndRoom();
}

void MainWindow::showTime(){
    //function that sets the value of the digital clock on the UI
    ui->countdown->show();
    if(minutes == 0 && seconds == 0){
        // Game stops when timer hits 0:00
        timer->stop();
        false;
        close();
        gameOver go;
        go.gameLost();
        go.exec();
        hide();
        close();
    }else if(seconds == 0){
        --minutes;
        seconds = 59;
    }else{
        seconds--;
    }
    ui->countdown->setDecMode();
    ui->countdown->setDigitCount(5);
    if (seconds < 10)
        ui->countdown->display(QString::number(minutes) +":0"+ QString::number(seconds));
    else
        ui->countdown->display(QString::number(minutes) +":"+ QString::number(seconds));
}
//populate the room items and users inventory
void MainWindow::buildInventoryAndRoom(){
    vector <string> itemNames;
    vector <string> validCommands;
    QList<QTreeWidgetItem*> items;
    QTreeWidgetItem *currentItem;
    for(int k =0; k <2; k++){
        if(k==0){
            itemNames = game->getCurrentItemNames(k);
            ui->inventory->clear();
        }else{
            itemNames = game->getCurrentItemNames(k);
            ui->roomItems->clear();
        }
        for(int i =0; i < itemNames.size(); i++){
            currentItem = new QTreeWidgetItem((QTreeWidget*)0, QStringList(QString(QString::fromStdString(itemNames[i]))));
            validCommands = game->getItemValidCommands(itemNames[i],k);
            for(int j = 0; j < validCommands.size(); j++){
                if(getNumberOfSpaces(validCommands[j]) > 0){
                     currentItem->addChild(new QTreeWidgetItem((QTreeWidget*)0, QStringList(QString(QString::fromStdString(validCommands[j])))));
                }else{
                     currentItem->addChild(new QTreeWidgetItem((QTreeWidget*)0, QStringList(QString(QString::fromStdString(validCommands[j]+" "+itemNames[i])))));
                }
            }
            items.append(currentItem);
      }
      if(k==0){
         ui->inventory->insertTopLevelItems(0,items);
      }else{
         ui->roomItems->insertTopLevelItems(0,items);
      }
   }
}
//find out if the command being passed has more than one word
int MainWindow::getNumberOfSpaces(string text) {
     int spaceCount = 0;
     for(int i =0; i < text.length(); i++) {
         if(text.at(i) == ' '){
             spaceCount++;
         }
     }
     return spaceCount;
}

MainWindow::~MainWindow() {
    delete game;
    delete ui;
}

void MainWindow::updateMainWindow(QString gameWindowText) {
    ui->mainGameWindow->clear();
    ui->mainGameWindow->append(gameWindowText);
}

void MainWindow::appendMainWindow(QString gameWindowText) {
    ui->mainGameWindow->append(gameWindowText);
}

void MainWindow::updateMap(QString map) {
    ui->gameMap->clear();
    ui->gameMap->append(map);
}

void MainWindow::updateLog(QString log) {
    ui->gameHistory->append(log);
}


// Settings action from Menu bar
void MainWindow::on_actionSettings_triggered() {
    // Displays settings
    settings s;
    s.setModal(true);
    s.exec();
}

// About action in the Menu bar
void MainWindow::on_actionAbout_triggered() {
    QImage ulLogo(":/images/ul_White.png");
    QImage image = ulLogo.scaled(200, 200, Qt::KeepAspectRatio);

    // Message dialog displays information about the application and authors
    QMessageBox about;
    about.setIconPixmap(QPixmap::fromImage(image));
    about.setText("Zork");
    about.setStyleSheet("color : white; background : rgb(46, 52, 54)");
    about.setWindowTitle("About Zork");
    about.setInformativeText("2018 © University of Limerick.\n\nWilliam O'Leary (15155528)\nAaron Dunne (15148602)");
    about.show();
    about.exec();
}

void MainWindow::ValidButtons() {
    map<string, Room*> exits = game->getCurrentRoomExits();
    if(exits["north"] != NULL){
        unlockButton(ui->northButton);
    }else{
        lockButton(ui->northButton);
    }

    if(exits["west"] != NULL){
        unlockButton(ui->westButton);
    }else{
        lockButton(ui->westButton);
    }

    if(exits["south"] != NULL){
        unlockButton(ui->southButton);
    }else{
        lockButton(ui->southButton);
    }

    if(exits["east"] != NULL){
        unlockButton(ui->eastButton);
    }else{
        lockButton(ui->eastButton);
    }

    if(exits["upstairs"] != NULL){
        unlockButton(ui->upstairsButton);
    }else{
        lockButton(ui->upstairsButton);
    }

    if(exits["downstairs"] != NULL){
        unlockButton(ui->downstairsButton);
    }else{
        lockButton(ui->downstairsButton);
    }

    if(game->isExit()){
        ui->escapeButton->show();
    }else{
        ui->escapeButton->hide();
    }
}

void MainWindow::lockButton(QPushButton *button){
    button->setEnabled(false);
    button->setStyleSheet("background-color: #474746");
    //button->hide();
}

void MainWindow::unlockButton(QPushButton *button){
    button->setEnabled(true);
    button->setStyleSheet("background-color: #83847f");
    //button->show();
}

void MainWindow::on_northButton_clicked(){
    game->goRoom("north");
    ValidButtons();
    buildInventoryAndRoom();
}

void MainWindow::on_upstairsButton_clicked(){
    game->goRoom("upstairs");
    ValidButtons();
    buildInventoryAndRoom();
}

void MainWindow::on_downstairsButton_clicked(){
    game->goRoom("downstairs");
    ValidButtons();
    buildInventoryAndRoom();
}

void MainWindow::on_westButton_clicked(){
     game->goRoom("west");
     ValidButtons();
     buildInventoryAndRoom();
}

void MainWindow::on_eastButton_clicked(){
     game->goRoom("east");
     ValidButtons();
     buildInventoryAndRoom();
}

void MainWindow::on_southButton_clicked(){
     game->goRoom("south");
     ValidButtons();
     buildInventoryAndRoom();
}

/*void MainWindow::on_roomItems_itemClicked(QListWidgetItem *item)
{
    //QTextStream out(stdout);
    //out << item->text() << endl;

}*/

void MainWindow::on_roomItems_itemClicked(QTreeWidgetItem *item, int column) {
    //QTextStream out(stdout);
    //out << item->text(column) << endl;
    game->runCommand(item->text(column).toUtf8().constData());
    buildInventoryAndRoom();
    //item->addChild();*/
}

void MainWindow::on_inventory_itemClicked(QTreeWidgetItem *item, int column) {
    game->runCommand(item->text(column).toUtf8().constData());
    buildInventoryAndRoom();
}

// Escape Button
void MainWindow::on_escapeButton_clicked() {
    timer->stop();
    // Players time is calculated
    minutes = 1 - minutes;
    seconds = 60 - seconds;
    close();
    gameOver go;

    // Checks if the seconds in the final time is < 10. If so, a "0" is add after the colon.
    if (seconds < 10)
        go.gameWon(QString::number(minutes) +":0"+ QString::number(seconds));
    else
        go.gameWon(QString::number(minutes) +":"+ QString::number(seconds));
    go.exec();
}

// New Game action in the Menu bar
void MainWindow::on_actionNew_Game_triggered() {
    // Dialog prompts to confirm the player wishes to stop the current game and start a new one
    QMessageBox confirmNewGame;
    confirmNewGame.setWindowTitle("Zork - Start New Game");
    confirmNewGame.setText("<b>You are currently in the middle of a game.</b>");
    confirmNewGame.setInformativeText("Are you sure you wish to start a new game?");
    confirmNewGame.setStyleSheet("color : white; background : rgb(79, 87, 88)");
    confirmNewGame.setIcon(QMessageBox::Question);
    confirmNewGame.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    confirmNewGame.setDefaultButton(QMessageBox::No);
    int ret = confirmNewGame.exec();

    switch (ret) {
        case QMessageBox::No:
            break;
        case QMessageBox::Yes:
            timer->stop();
            this->close();
            MainWindow *w = new MainWindow();
            w->move(QApplication::desktop()->screen()->rect().center() - w->rect().center());
            w->show();
            break;
    }
}

// Quit game action in the Menu bar
void MainWindow::on_actionQuit_Game_triggered() {
    // Dialog prompts to confirm player wishes to quit the game in progress and return to the main menu
    QMessageBox confirmQuitGame;
    confirmQuitGame.setWindowTitle("Zork - Quit Game");
    confirmQuitGame.setText("<b>You are currently in the middle of a game.</b>");
    confirmQuitGame.setInformativeText("Are you sure you wish to end the game and return to the main menu?");
    confirmQuitGame.setStyleSheet("color : white; background : rgb(79, 87, 88)");
    confirmQuitGame.setIcon(QMessageBox::Question);
    confirmQuitGame.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    confirmQuitGame.setDefaultButton(QMessageBox::No);

    int ret = confirmQuitGame.exec();

    switch (ret) {
        case QMessageBox::No:
            break;
        case QMessageBox::Yes:
            timer->stop();
            this->close();
            zorkHome h;
            h.exec();
            break;
    }
}

// Exit action in the Menu bar
void MainWindow::on_actionExit_triggered() {
    // Dialog prompts to confirm application exit by player
    QMessageBox confirmExit;
    confirmExit.setWindowTitle("Exit Zork");
    confirmExit.setText("Are you sure you want to quit Zork?");
    confirmExit.setStyleSheet("color : white; background : rgb(79, 87, 88)");
    confirmExit.setIcon(QMessageBox::Question);
    confirmExit.setStandardButtons(QMessageBox::Cancel | QMessageBox::Yes);
    confirmExit.setDefaultButton(QMessageBox::Cancel);
    int ret = confirmExit.exec();

    switch (ret) {
        case QMessageBox::Cancel:
            break;
        case QMessageBox::Yes:
            close();
        break;
    }
}
