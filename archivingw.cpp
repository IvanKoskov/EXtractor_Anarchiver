#include "archivingw.h"
#include "ui_archivingw.h"
#include <QFile>
#include <QFileInfo>
#include <QTableWidgetItem>
#include <QTableWidget>
#include <QStringList>
#include <QDir>
#include <QStandardPaths>
#include <QDebug>
#include <QFileDialog>
#include <zip.h>
#include <QProcess>

QString path;

void createFolderIfNotExists() {
    // Get the user's home directory
    QString homeDir = QStandardPaths::writableLocation(QStandardPaths::HomeLocation);
    path = homeDir + "/extractorltdl/archiveex/";
    QDir dir;

    // Check if the folder already exists
    if (!dir.exists(path)) {
        // Create the folder
        if (dir.mkpath(path)) {
            qDebug() << "Folder created:" << path;
        } else {
            qDebug() << "Failed to create folder:" << path;
        }
    } else {
        qDebug() << "Folder already exists:" << path;
    }
}

archivingw::archivingw(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::archivingw)
{
    ui->setupUi(this);



    QStringList archiveTypes = {
        "ZIP",
        "TAR",
        "GZIP",
        "BZIP2",
        "XZ",
        "ZSTD",
        "ISO9660 (same as ISO)",
        "ISO",   // Added ISO
        "7ZIP",
        "AR",
        "CPIO",
        "LZ4",
        "LZIP",
        "Z",
        "TAR.Z",
        "TAR.GZ",
        "TAR.BZ2",
        "TAR.XZ",
        "RAR"
    };





    ui->comboBox->addItems(archiveTypes);









    createFolderIfNotExists(); // Ensure folder exists before populating
    populateList();
    ui->label_6->setVisible(false);
}

archivingw::~archivingw()
{
    delete ui;
}

void archivingw::populateList() {
    QDir archiveDir(path);
    QStringList files = archiveDir.entryList(QDir::Files);  // Get only files

    // Debugging output
    qDebug() << "Files found:" << files;

    // Resize the table to fit the number of files
    ui->tableWidget->setRowCount(files.size());
    ui->tableWidget->setColumnCount(2);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "File Name" << "Size (Bytes)");

    for (int row = 0; row < files.size(); ++row) {
        QFileInfo fileInfo(archiveDir.filePath(files[row]));
        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(fileInfo.fileName()));
        ui->tableWidget->setItem(row, 1, new QTableWidgetItem(QString::number(fileInfo.size())));
    }

    // If no files found, display a message in the UI
    if (files.isEmpty()) {
        ui->tableWidget->setRowCount(1);
        ui->tableWidget->setItem(0, 0, new QTableWidgetItem("No files found"));
        ui->tableWidget->setItem(0, 1, new QTableWidgetItem(""));
    }
}

void archivingw::on_pushButton_3_clicked()
{
    ui->pushButton_3->setVisible(false);
    qDebug() << "Button clicked. Hiding button...";
    ui->label_6->setVisible(true);
    int currentRow = ui->tableWidget->currentRow();

    if (currentRow < 0) {
        qDebug() << "No file selected by user.";
        ui->pushButton_3->setVisible(true);
        ui->label_6->setVisible(false);
        return;
    }

    QString fileName = ui->tableWidget->item(currentRow, 0)->text();
    QString userHomePath = QDir::homePath();
    QString fullPath = QDir(userHomePath).filePath("extractorltdl/archiveex/" + fileName);
    QString outputArchive = QDir(QStandardPaths::writableLocation(QStandardPaths::DesktopLocation)).filePath("2_" + fileName);

    QString password = ui->passwordin->text();
    QString fileFormat = ui->comboBox->currentText();

    QString command;
    if (fileFormat == "ZIP") {
        command = QString("zip %1 %2 %3").arg(password.isEmpty() ? "" : QString("-P %1").arg(password), outputArchive + ".zip", fullPath);
    } else if (fileFormat == "RAR") {
        command = QString("rar a %1 %2").arg(outputArchive + ".rar", fullPath);
    } else if (fileFormat == "GZIP") {
        command = QString("gzip -k -c %1 > %2").arg(fullPath, outputArchive + ".gz");
    } else if (fileFormat == "BZIP2") {
        command = QString("bzip2 -k -c %1 > %2").arg(fullPath, outputArchive + ".bz2");
    } else if (fileFormat == "XZ") {
        command = QString("xz -k -c %1 > %2").arg(fullPath, outputArchive + ".xz");
    } else if (fileFormat == "ZSTD") {
        command = QString("zstd -k -o %2 %1").arg(fullPath, outputArchive + ".zst");
    } else if (fileFormat == "ISO") {
        command = QString("hdiutil makehybrid -o %1 %2").arg(outputArchive + ".iso", fullPath);

    } else if (fileFormat == "7ZIP") {
        command = QString("7z a %1 %2").arg(outputArchive + ".7z", fullPath);
    } else if (fileFormat == "AR") {
        command = QString("ar rcs %1 %2").arg(outputArchive + ".a", fullPath);
    } else if (fileFormat == "CPIO") {
        command = QString("find %2 | cpio -o > %1").arg(outputArchive + ".cpio", fullPath);
    } else if (fileFormat == "LZ4") {
        command = QString("lz4 %2 %1").arg(outputArchive + ".lz4", fullPath);
    } else if (fileFormat == "LZIP") {
        command = QString("lzip -k -o %2 %1").arg(fullPath, outputArchive + ".lz");
    } else if (fileFormat == "Z") {
        command = QString("compress -c %1 > %2").arg(fullPath, outputArchive + ".Z");
    } else if (fileFormat == "TAR.Z") {
        command = QString("tar -czf %1 %2").arg(outputArchive + ".tar.Z", fullPath);
    } else if (fileFormat == "TAR.GZ") {
        command = QString("tar -czf %1 %2").arg(outputArchive + ".tar.gz", fullPath);
    } else if (fileFormat == "TAR.BZ2") {
        command = QString("tar -cjf %1 %2").arg(outputArchive + ".tar.bz2", fullPath);
    } else if (fileFormat == "TAR.XZ") {
        command = QString("tar -cJf %1 %2").arg(outputArchive + ".tar.xz", fullPath);
    }

    qDebug() << "Command to execute:" << command;

    QProcess *process = new QProcess(this);
    QStringList arguments;
    arguments << "-c" << command;

    QProcessEnvironment env = QProcessEnvironment::systemEnvironment();
    env.insert("PATH", "/opt/homebrew/bin:" + env.value("PATH"));
    process->setProcessEnvironment(env);

    process->start("zsh", arguments);

    if (!process->waitForStarted()) {
        qDebug() << "Failed to start process:" << process->errorString();
        ui->pushButton_3->setVisible(true);
        ui->label_6->setVisible(false);
        return;
    }

    process->waitForFinished();

    if (process->exitStatus() == QProcess::CrashExit) {
        qDebug() << "Process crashed.";
    } else {
        qDebug() << "Process finished with exit code:" << process->exitCode();
        qDebug() << process->readAllStandardOutput();
        qDebug() << process->readAllStandardError();
    }

    ui->pushButton_3->setVisible(true);
    ui->label_6->setVisible(false);
}




void archivingw::selectAndCopyFile() {
    // Open the file dialog to select a file
    QString selectedFile = QFileDialog::getOpenFileName(this, "Select a File", QString(), "All Files (*.*)");

    // Check if the user selected a file
    if (!selectedFile.isEmpty()) {
        // Define the destination path
        QString fileName = QFileInfo(selectedFile).fileName();
        QString destinationPath = QDir(path).filePath(fileName);

        // Copy the file to the destination
        if (QFile::copy(selectedFile, destinationPath)) {
            qDebug() << "File copied to:" << destinationPath;
        } else {
            qDebug() << "Failed to copy file to:" << destinationPath;
        }
    } else {
        qDebug() << "No file selected.";
    }

    populateList();
}







void archivingw::on_pushButton_clicked()
{
selectAndCopyFile();
}


void archivingw::on_pushButton_2_clicked()
{
    int currentRow = ui->tableWidget->currentRow();

    // No file selected? Major oof.
    if (currentRow < 0) {
        qDebug() << "No file selected, fam.";
        return;
    }

    QString fileName = ui->tableWidget->item(currentRow, 0)->text();
    QString filePath = QDir(path).filePath(fileName);

    // Let’s try to delete it!
    if (QFile::remove(filePath)) {
        qDebug() << "Deleted file:" << filePath;
        populateList(); // Refresh that list, ya know?
    } else {
        qDebug() << "Couldn’t delete that file, bruh.";
    }
}


