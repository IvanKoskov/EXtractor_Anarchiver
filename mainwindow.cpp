#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "greeting.h"
#include "ui_greeting.h"
#include <QDir>
#include <QFile>
#include <QFileInfo>
#include <QFileDialog>
#include <QDesktopServices>
#include "extracting.h"
#include "ui_extracting.h"
#include "archivingw.h"
#include "ui_archivingw.h"
//those are all default in framework so lets keep it simple al right?

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    bool showWelcomeScreen = checkAndCreateFolder();
    if (showWelcomeScreen) {
        greeting greeted;
        greeted.setModal(true);
        greeted.setFixedSize(400, 600);
        greeted.setWindowTitle("Welcome to EXtractor-Anarchiver!");
        greeted.resize(300, 200);
        greeted.exec();
    }

    QLabel *backgroundcold = new QLabel(this);
    QPixmap background(":/rec/backbode2.svg");
    backgroundcold->setPixmap(background);
    backgroundcold->setScaledContents(true);
    backgroundcold->setGeometry(0, 0, this->width(), this->height()); // Cover the entire dialog

    // Lower the label to ensure it stays behind other widgets
    backgroundcold->lower();





    QPixmap pixsup(":/rec/perfect-heart-shape22.png");
    if (pixsup.isNull()) {
        qDebug() << "Failed to load image!";
    } else {
        ui->support->setPixmap(pixsup.scaled(60, 60, Qt::KeepAspectRatio));
    }

    QPixmap pixhel(":/rec/techsupp.png");
    if (pixhel.isNull()) {
        qDebug() << "Failed to load image!";
    } else {
        ui->techhel->setPixmap(pixhel.scaled(60, 60, Qt::KeepAspectRatio));
    }


}

MainWindow::~MainWindow()
{
    delete ui;
}


bool MainWindow::checkAndCreateFolder() {
    // Define the path to the directory and file
    QString dirPath = QDir::homePath() + "/whatishere";
    QString filePath = dirPath + "/info.txt";

    // Create the directory if it doesn't exist
    QDir dir;
    if (!dir.exists(dirPath)) {
        dir.mkpath(dirPath);
        // Create the file and write some initial content
        QFile file(filePath);
        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream out(&file);
            out << "Welcome to the application!\nThis file is created on first launch.";
            file.close();
        }
        return true; // Show welcome screen
    }

    // Check if the file exists
    QFileInfo fileInfo(filePath);
    if (!fileInfo.exists()) {
        // Create the file if it does not exist
        QFile file(filePath);
        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream out(&file);
            out << "Welcome to the application!\nThis file is created on first launch.";
            file.close();
        }
        return true; // Show welcome screen
    }

    return false; // Skip welcome screen
}

void MainWindow::on_pushButton_clicked()
{
QDesktopServices::openUrl(QUrl("https://ivankoskov.github.io/donations-/"));
}


void MainWindow::on_pushButton_2_clicked()
{
QDesktopServices::openUrl(QUrl("https://t.me/Evan_Matthew"));
}


void MainWindow::on_pushButton_3_clicked()
{
    extracting extracted;
    extracted.setModal(true);
    extracted.setFixedSize(250, 200);
    extracted.setWindowTitle("Preferences");
    extracted.show();
    extracted.exec();
}


void MainWindow::on_pushButton_4_clicked()
{
    archivingw arching;
    arching.setModal(true);
    arching.setFixedSize(415, 300);
    arching.setWindowTitle("Archiving files");
    arching.show();
    arching.exec();

}

