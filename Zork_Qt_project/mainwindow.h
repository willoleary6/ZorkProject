#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ZorkUL.h"
#include "gameover.h"
#include <map>
#include <QTreeWidgetItem>
#include <string>
#include <QTimer>
#include <QPushButton>

class ZorkUL;
class gameOver;
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
    void updateMainWindow(QString gameWindowText);
    void appendMainWindow(QString gameWindowText);
private:
    void initialiseUI();
    ZorkUL *game;
    gameOver *go;
    int minutes;
    int seconds;
    QTimer *timer;
    void lockButton(QPushButton *button);
    void unlockButton(QPushButton *button);
    void ValidButtons();
    void buildInventoryAndRoom();
    int getNumberOfSpaces(std::string text);

public slots:


private slots:

    void showTime();
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

    void on_escapeButton_clicked();

    void on_actionNew_Game_triggered();

    void on_actionQuit_Game_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
