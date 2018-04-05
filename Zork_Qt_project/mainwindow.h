#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "newGame.h"
#include "ZorkUL.h"
#include <map>
#include <QTreeWidgetItem>

class ZorkUL;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
     void updateMap(QString map);
     void updateLog(QString log);
private:
    void initialiseUI();
    ZorkUL *game;
    void lockButton(QPushButton *button);
    void unlockButton(QPushButton *button);
    void ValidButtons();
    void buildRoomList();
    void buildInventory();
    void buildInventoryAndRoom();

public slots:


private slots:


    void on_actionClose_triggered();

    void on_actionSettings_triggered();

    void on_actionAbout_triggered();

    void on_northButton_clicked();

    void on_upstairsButton_clicked();

    void on_downstairsButton_clicked();

    void on_westButton_clicked();

    void on_eastButton_clicked();

    void on_southButton_clicked();

    //void on_roomItems_itemClicked(QListWidgetItem *item);

    void on_roomItems_itemClicked(QTreeWidgetItem *item, int column);

    void on_inventory_itemClicked(QTreeWidgetItem *item, int column);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
