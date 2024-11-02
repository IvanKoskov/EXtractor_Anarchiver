#include "extracting.h"
#include "ui_extracting.h"
#include <QPixmap> //render pics
#include <QStandardPaths> //to access the file system paths
#include <QFileDialog>
#include <iostream> //this one is for archiving libs and cpp and c core functionality
#include <QDir> //for directories
#include <QFileInfo>
#include <zip.h>
#include <QProcess>
extracting::extracting(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::extracting)
{
    ui->setupUi(this);









    QPixmap pixbac(":/rec/greycol222.jpeg");
    if (pixbac.isNull()) {
        qDebug() << "Failed to load image!";
    } else {
        ui->label->setPixmap(pixbac);
    }

    QStringList systemFolders = {
        QStandardPaths::writableLocation(QStandardPaths::DesktopLocation),
        QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation),
        QStandardPaths::writableLocation(QStandardPaths::MusicLocation),
        QStandardPaths::writableLocation(QStandardPaths::PicturesLocation),
        QStandardPaths::writableLocation(QStandardPaths::MoviesLocation)
    };

    // Check if the list is populated
    qDebug() << "System folders:" << systemFolders;

    ui->comboBox->addItems(systemFolders);



}

extracting::~extracting()
{
    delete ui;
}






void extracting::on_pushButton_2_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("All Files (*)"));

    if (!fileName.isEmpty()) {
        selectedFilePath = fileName;
        qDebug() << "Selected File Path:" << selectedFilePath; // Debug output
    } else {
        qDebug() << "No file selected!";
    }

}


void extracting::on_pushButton_clicked()
{
    savepath = ui->comboBox->currentText();


    qDebug() << "Selected Path:" << savepath;
}






void extracting::extractArchive(const QString &selectedFilePath, const QString &savePath) {
    qDebug() << "Extracting archive:" << selectedFilePath << "to" << savePath;

    // Ensure savePath is a valid directory
    QDir dir(savePath);
    if (!dir.exists()) {
        qDebug() << "Output directory does not exist.";
        return;
    }

    QString fileFormat;
    if (selectedFilePath.endsWith(".zip", Qt::CaseInsensitive)) {
        fileFormat = "ZIP";
    } else if (selectedFilePath.endsWith(".tar", Qt::CaseInsensitive) ||
               selectedFilePath.endsWith(".tar.gz", Qt::CaseInsensitive) ||
               selectedFilePath.endsWith(".tgz", Qt::CaseInsensitive)) {
        fileFormat = "TAR";
    } else if (selectedFilePath.endsWith(".gz", Qt::CaseInsensitive)) {
        fileFormat = "GZ";
    } else if (selectedFilePath.endsWith(".bz2", Qt::CaseInsensitive)) {
        fileFormat = "BZ2";
    } else {
        qDebug() << "Unsupported file format.";
        return;
    }

    QString command;
    if (fileFormat == "ZIP") {
        command = QString("unzip -o '%1' -d '%2'").arg(selectedFilePath, savePath);
    } else if (fileFormat == "TAR") {
        command = QString("tar -xvf '%1' -C '%2'").arg(selectedFilePath, savePath);
    } else if (fileFormat == "GZ") {
        command = QString("gunzip -c '%1' > '%2/%3'").arg(selectedFilePath, savePath, QFileInfo(selectedFilePath).baseName());
    } else if (fileFormat == "BZ2") {
        command = QString("bunzip2 -c '%1' > '%2/%3'").arg(selectedFilePath, savePath, QFileInfo(selectedFilePath).baseName());
    }

    // Start the terminal process using `zsh` to execute the command
    QProcess *process = new QProcess(this);
    process->start("zsh", QStringList() << "-c" << command); // Use zsh or bash

    // Handle output and errors
    connect(process, &QProcess::readyReadStandardOutput, [process]() {
        qDebug() << process->readAllStandardOutput();
    });
    connect(process, &QProcess::readyReadStandardError, [process]() {
        qDebug() << process->readAllStandardError();
    });

    // Optionally wait for the process to finish and check exit status
    process->waitForFinished();
    int exitCode = process->exitCode();
    if (exitCode != 0) {
        qDebug() << "Extraction failed with exit code:" << exitCode;
    }
}












void extracting::on_pushButton_3_clicked()
{
    ui->pushButton_3->setVisible(false);
    ui->pushButton->setVisible(false);


    qDebug() << "ComboBox item count:" << ui->comboBox->count(); // Check item count

    savepath = ui->comboBox->currentText();

    if (savepath.isEmpty()) {
        qDebug() << "No path selected!";
    } else {
        qDebug() << "Selected Path:" << savepath;
    }




    extractArchive(selectedFilePath, savepath);
    this->close();
}

