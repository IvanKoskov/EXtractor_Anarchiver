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
#include <zlib.h>
#include <archive.h>
#include <archive_entry.h>

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
        qDebug() << "Selected File Path:" << selectedFilePath;
    } else {
        qDebug() << "No file selected!";
    }

}


void extracting::on_pushButton_clicked()
{
    savepath = ui->comboBox->currentText();


    qDebug() << "Selected Path:" << savepath;
}





#include <QProcess>
#include <QDebug>
#include <QFileInfo>
#include <QFile>
#include <QTextStream>

void extracting::extractArchive(const QString &selectedFilePath, const QString &savePath) {
    qDebug() << "Extracting file from:" << selectedFilePath << "to" << savePath;

    QFileInfo fileInfo(selectedFilePath);
    QString fileExtension = fileInfo.suffix().toLower();
    QString command;
    QString extractedFilePath = savePath + "/" + fileInfo.baseName(); // Default file name

    // Handle zip files
    if (fileExtension == "zip") {
        command = QString("unzip \"%1\" -d \"%2\"").arg(selectedFilePath, savePath);
    }
    // Handle rar files
    else if (fileExtension == "rar") {
        command = QString("/opt/homebrew/bin/unar \"%1\" -o \"%2\"").arg(selectedFilePath, savePath);
    }
    // Handle tar files (including tar.gz, tar.bz2, tar.xz)
    else if (fileExtension == "tar") {
        command = QString("tar -xvf \"%1\" -C \"%2\"").arg(selectedFilePath, savePath);  // for tar.gz, tar.bz2, tar.xz, etc.
    } else if (fileExtension == "gz") {
        command = QString("tar -xzvf \"%1\" -C \"%2\"").arg(selectedFilePath, savePath);  // for .tar.gz
    } else if (fileExtension == "bz2") {
        command = QString("tar -xjvf \"%1\" -C \"%2\"").arg(selectedFilePath, savePath);  // for .tar.bz2
    } else if (fileExtension == "xz") {
        command = QString("tar -xJvf \"%1\" -C \"%2\"").arg(selectedFilePath, savePath);  // for .tar.xz
    }
    // Handle gzip (non-tar) files
    else if (fileExtension == "gz") {
        command = QString("gzip -d \"%1\" -c > \"%2\"").arg(selectedFilePath, extractedFilePath);
    }
    // Handle bzip2 files
    else if (fileExtension == "bz2") {
        command = QString("bzip2 -d \"%1\" -c > \"%2\"").arg(selectedFilePath, extractedFilePath);
    }
    // Handle XZ files
    else if (fileExtension == "xz") {
        command = QString("xz -d \"%1\" -c > \"%2\"").arg(selectedFilePath, extractedFilePath);
    }
    // Handle ZST (Zstandard) files
    else if (fileExtension == "zst") {
        command = QString("/opt/homebrew/bin/zstd -d \"%1\" -o \"%2\"").arg(selectedFilePath, extractedFilePath);
    }
    else {
        qDebug() << "Unsupported file format for extraction!";
        return;
    }

    qDebug() << "Command to execute: " << command;

    // Start the extraction process using QProcess
    QProcess *process = new QProcess(this);
    process->setWorkingDirectory(savePath);  // Set the working directory to the save path

    // Execute the command
    process->start("zsh", QStringList() << "-c" << command);

    if (!process->waitForStarted()) {
        qDebug() << "Failed to start extraction process:" << process->errorString();
        return;
    }

    // Wait for the process to finish
    process->waitForFinished();

    // Check the process exit code to determine success/failure
    if (process->exitStatus() == QProcess::CrashExit) {
        qDebug() << "Process crashed!";
    } else {
        qDebug() << "Process finished with exit code:" << process->exitCode();
        qDebug() << process->readAllStandardOutput();
        qDebug() << process->readAllStandardError();
    }

    // After extraction, check the file type to ensure it's correctly identified
    QString detectCommand = QString("file --mime-type -b \"%1\"").arg(extractedFilePath);
    QProcess detectProcess;
    detectProcess.start("bash", QStringList() << "-c" << detectCommand);
    detectProcess.waitForFinished();

    QString mimeType = detectProcess.readAllStandardOutput().trimmed();
    qDebug() << "Detected MIME type: " << mimeType;

    // Based on MIME type, rename the file to have the correct extension
    if (mimeType.startsWith("image/jpeg")) {
        extractedFilePath += ".jpeg";
    } else if (mimeType.startsWith("image/png")) {
        extractedFilePath += ".png";
    } else if (mimeType.startsWith("text/plain")) {
        extractedFilePath += ".txt";
    } else if (mimeType.startsWith("application/pdf")) {
        extractedFilePath += ".pdf";
    } else {
        qDebug() << "Unsupported MIME type!";
        return;
    }

    // Rename the file to the correct extension
    if (QFile::rename(extractedFilePath, savePath + "/" + fileInfo.baseName() + "." + mimeType.split('/').last())) {
        qDebug() << "Extraction successful, saved as: " << extractedFilePath;
    } else {
        qDebug() << "Failed to rename the extracted file!";
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

