#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "newGame.h"
#include "settings.h"
#include <QMessageBox>
#include <QPixmap>
#include <QImage>
#include <QtCore>
#include <QString>
#include <QToolButton>
#include <QTextStream>

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
void MainWindow::initialiseUI(){
        game->getMap();
        game->printWelcome();
        ValidButtons();
        buildInventoryAndRoom();
        //connect(ui->roomItems, SIGNAL(itemClicked(QListWidgetItem*)),this,SLOT(on_roomItems_itemClicked(QListWidgetItem *item)));
}
void MainWindow::showTime(){
    //function that sets the value of the digital clock on the UI
    ui->countdown->show();
    if(minutes == 0 && seconds == 0){
        timer->stop();
        //PUT SHUTDOWN COMMAND HERE
        hide();
        close();
    }else if(seconds == 0){
        --minutes;
        seconds = 59;
    }else{
        seconds--;
    }
    ui->countdown->setDecMode();
    ui->countdown->setDigitCount(15);
    ui->countdown->display(QString::number(minutes) +" : "+ QString::number(seconds));
}

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

int MainWindow::getNumberOfSpaces(string text){
     int spaceCount = 0;
     for(int i =0; i < text.length(); i++){
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

void MainWindow::on_actionClose_triggered() {
    close();
}

void MainWindow::on_actionSettings_triggered() {
    settings s;
    s.setModal(true);
    s.exec();
}

void MainWindow::on_actionAbout_triggered() {
    QImage ulLogo(":/images/ul_White.png");
    QImage image = ulLogo.scaled(150, 150, Qt::KeepAspectRatio);

    QMessageBox about;
    about.setIconPixmap(QPixmap::fromImage(image));
    about.setText("Zork");
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

void MainWindow::on_escapeButton_clicked() {
    this->close();
}
