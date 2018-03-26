#ifndef NEWGAME_H
#define NEWGAME_H

#include <QDialog>

namespace Ui {
class newGame;
}

class newGame : public QDialog
{
    Q_OBJECT

public:
    explicit newGame(QWidget *parent = 0);
    ~newGame();

private slots:
    void on_mainMenuButton_clicked();

    void on_startGameButton_clicked();

private:
    Ui::newGame *ui;
    QWidget *currentParent;
};

#endif // NEWGAME_H
