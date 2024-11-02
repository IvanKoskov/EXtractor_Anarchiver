#include "mainwindow.h"
#include <iostream>
#include <QApplication>
#include <QStandardPaths>
#include <QMessageBox>
#include <QDir>
#include <QFile>
#include <QStandardPaths>



void createAndDeleteTempFile() {
    // Get the desktop path
    QString desktopPath = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
    QString filePath = desktopPath + "/temp_file.txt";

    // Create and open the file
    QFile tempFile(filePath);
    if (tempFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&tempFile);
        out << "This is a temporary file created for demonstration purposes.";
        tempFile.close();
        qDebug() << "File created at:" << filePath;
    } else {
        qDebug() << "Failed to create file:" << tempFile.errorString();
        return;
    }

    // Delete the file
    if (QFile::remove(filePath)) {
        qDebug() << "File deleted successfully.";
    } else {
        qDebug() << "Failed to delete file:" << tempFile.errorString();
    }
}





int main(int argc, char *argv[])
{

    createAndDeleteTempFile();
    QApplication app(argc, argv);
    app.setWindowIcon(QIcon(":/rec/HEIF Imagecustom.icns"));
    MainWindow w;
    w.setWindowTitle("EXtractor universal!");
    w.setFixedSize(400, 300);
    w.show();
    return app.exec();
}
