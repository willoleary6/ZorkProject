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

        initialiseUI();

    }
void MainWindow::initialiseUI(){
        game->getMap();
        game->printWelcome();
        ValidButtons();
        buildRoomList();
        //connect(ui->roomItems, SIGNAL(itemClicked(QListWidgetItem*)),this,SLOT(on_roomItems_itemClicked(QListWidgetItem *item)));
}
void MainWindow::buildRoomList(){
    ui->roomItems->clear();
    vector <string> itemsInRoom = game->getCurrentRoomItemNames();
    vector <string> validCommands;
    QList<QTreeWidgetItem*> items;
    QTreeWidgetItem *currentItem;
    for(int i =0; i < itemsInRoom.size(); i++){
         //new QTreeWidgetItem(ui->roomItems,0);
        currentItem = new QTreeWidgetItem((QTreeWidget*)0, QStringList(QString(QString::fromStdString(itemsInRoom[i]).arg(i))));
        validCommands = game->getItemValidCommands(itemsInRoom[i]);
        for(int j = 0; j < validCommands.size(); j++){
            currentItem->addChild(new QTreeWidgetItem((QTreeWidget*)0, QStringList(QString(QString::fromStdString(validCommands[j]).arg(0)))));
        }
        //currentItem->addChild(new QTreeWidgetItem((QTreeWidget*)0, QStringList(QString(QString::fromStdString("test").arg(0)))));
        items.append(currentItem);
        //ui->roomItems->addTopLevelItem(new QTreeWidgetItem(QString::fromStdString(itemsInRoom[i]),0));

    }
    ui->roomItems->insertTopLevelItems(0,items);
    /*QTreeWidgetItem *test = new QTreeWidgetItem();
    QList<QVariant> dataList;
    dataList.append("first");
    dataList.append("Second");
    QVariant data(dataList);
    test->setData(0,Qt::UserRole,data);*/
    //QListWidgetItem *test = new QListWidgetItem();
    //test->setText("Test");
    //
    //ui->roomItems->addItem(test);
   // ui->roomItems->
}


MainWindow::~MainWindow()
{
    cout << "test" << endl;
    delete ui;
}
void MainWindow::updateMap(QString map){
    ui->gameMap->clear();
    ui->gameMap->append(map);
}
void MainWindow::updateLog(QString log){
    ui->gameHistory->append(log);
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
void MainWindow::ValidButtons(){
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
}
void MainWindow::lockButton(QPushButton *button){
    button->setEnabled(false);
    button->hide();
}
void MainWindow::unlockButton(QPushButton *button){
    button->setEnabled(true);
    button->show();
}

void MainWindow::on_northButton_clicked(){
    game->goRoom("north");
    ValidButtons();
    buildRoomList();
}

void MainWindow::on_upstairsButton_clicked(){
    game->goRoom("upstairs");
    ValidButtons();
    buildRoomList();
}

void MainWindow::on_downstairsButton_clicked(){
    game->goRoom("downstairs");
    ValidButtons();
    buildRoomList();
}

void MainWindow::on_westButton_clicked(){
     game->goRoom("west");
     ValidButtons();
     buildRoomList();
}

void MainWindow::on_eastButton_clicked(){
     game->goRoom("east");
     ValidButtons();
     buildRoomList();
}

void MainWindow::on_southButton_clicked(){
     game->goRoom("south");
     ValidButtons();
     buildRoomList();
}





/*void MainWindow::on_roomItems_itemClicked(QListWidgetItem *item)
{
    //QTextStream out(stdout);
    //out << item->text() << endl;

}*/

void MainWindow::on_roomItems_itemClicked(QTreeWidgetItem *item, int column)
{
    QTextStream out(stdout);
    out << item->text(column) << endl;
    //item->addChild();*/
}
