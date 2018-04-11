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

// Read csv file function
void leaderboard::readFile() {
    // Defines the file path that will store all the winning game results.
    QString filename = "/home/pi/Documents/leaderboard.csv";
    QFile csvFile(filename);

    // Checks to see if the file exists. If no file is found, it is created at the csvFile path.
    if (!csvFile.open(QIODevice::ReadOnly)) {
        cout << "No file exists. File has now been created." << endl;
    }
    else {
        int rowCount = 0;
        QTextStream stream(&csvFile);
        QStringList table;

        // While loop that runs until no more data can be read.
        while(!(stream.atEnd())) {
            /*  As the while loop runs, each line of the .csv file is read as a string. Wherever a comma is found
             *  in the string, the line.split() function
             */
            QString line = csvFile.readLine();
            table = line.split(",");
            ui->leadTable->setColumnCount(table.size());
            ui->leadTable->setColumnWidth(0, 200);
            ui->leadTable->setColumnWidth(1, 195);
            ui->leadTable->horizontalHeader()->sortIndicatorOrder();
            ui->leadTable->sortByColumn(1, Qt::AscendingOrder);
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
    QString filename = "/home/pi/Documents/leaderboard.csv";
    QFile csvFile(filename);

    if (!csvFile.open(QIODevice::Append)) {
    }
    else {
        csvFile.open(QIODevice::Append);
        QTextStream stream(&csvFile);
        stream << playerName << "," << timer << "\n";
    }
    csvFile.close();
}

void leaderboard::on_backButton_clicked() {
    close();
}
