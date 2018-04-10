#include "leaderboard.h"
#include "ui_leaderboard.h"

leaderboard::leaderboard(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::leaderboard)
{
    ui->setupUi(this);
}

leaderboard::~leaderboard()
{
    delete ui;
}

void leaderboard::readFile() {
    QString filename = "/home/pi/Documents/zork/zorkProject/Zork_Qt_project/leaderboard.csv";
    QFile csvFile(filename);

    if (!csvFile.open(QIODevice::ReadOnly)) {
        cout << "No file exists" << endl;
    }
    else {
        int rowCount = 0;
        QTextStream stream(&csvFile);
        QStringList table;

        while(!(stream.atEnd())) {

            QString line = csvFile.readLine();
            table = line.split(", ");
            ui->leadTable->setColumnCount(table.size());
            ui->leadTable->setColumnWidth(0, 200);
            ui->leadTable->setColumnWidth(1, 200);
            ui->leadTable->insertRow(rowCount);

            for (int i = 0; i < table.size(); i++) {
                QTableWidgetItem *test = new QTableWidgetItem(table.at(i));
                test->setTextAlignment(Qt::AlignCenter);
                ui->leadTable->setItem(rowCount, i, test);
            }
            rowCount++;
        }
    }
    csvFile.close();
}

void leaderboard::writeFile(QString playerName, QString timer) {
    QString filename = "/home/pi/Documents/zork/zorkProject/Zork_Qt_project/leaderboard.csv";
    QFile csvFile(filename);

    if (!csvFile.open(QIODevice::Append)) {
        cout << "No file exists" << endl;
    }
    else {
        QTextStream stream(&csvFile);
        stream << playerName << ", "  << timer << endl;
    }
    csvFile.close();
}

void leaderboard::on_backButton_clicked() {
    close();
}
