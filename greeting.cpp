#include "greeting.h"
#include "ui_greeting.h"
#include <QMessageBox>
#include <QPixmap>
#include <QDesktopServices>
#include <QUrl>
#include <QGraphicsBlurEffect>
#include <QPixmap>
#include <QWidget>
#include <QLabel>
#include <QPainter>
#include <QtMath>
#include <QColor>
#include <QImage>







greeting::greeting(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::greeting)
{
    ui->setupUi(this);
    QLabel *backgroundLabel = new QLabel(this);
    QPixmap background(":/rec/istockphoto2.jpg");
    backgroundLabel->setPixmap(background);
    backgroundLabel->setScaledContents(true);
    backgroundLabel->setGeometry(0, 0, this->width(), this->height()); // Cover the entire dialog

    // Lower the label to ensure it stays behind other widgets
    backgroundLabel->lower();
    connect(ui->pushButton, &QPushButton::clicked, this, &greeting::on_pushButton_clicked);


    promptForFullDiskAccess();

    QPixmap pixpix(":/rec/archivecon2.png");
    if (pixpix.isNull()) {
        qDebug() << "Failed to load image!";
    } else {
        ui->label_12->setPixmap(pixpix.scaled(60, 60, Qt::KeepAspectRatio));
    }



}

greeting::~greeting()
{
    delete ui;
}
//it would be the best choice because my app will need to get files and work with them.
void greeting::promptForFullDiskAccess() {
    QMessageBox msgBox;
    QPixmap icon(":/rec/download-icon-png-43822.png");  // Load your custom icon
    msgBox.setIconPixmap(icon);  // Set the custom icon
    msgBox.setWindowTitle("Full Disk Access Required");
    msgBox.setText("This application requires full disk access to function properly.\n\n"
                   "Please grant it in:\n"
                   "System Preferences > Security & Privacy > Privacy > Full Disk Access.\n"
                   "Then add this application.");
    msgBox.exec();  // Display the message box
}



void greeting::on_pushButton_clicked()
{
    QDesktopServices::openUrl(QUrl("https://apps.apple.com/th/app/rar-extractor-unarchiver/id646295438"));
}


void greeting::on_pushButton_3_clicked()
{
    //link to the page of this app
  QDesktopServices::openUrl(QUrl("https://github.com/IvanKoskov/EXtractor_Anarchiver"));
}



void greeting::on_checkBox_clicked(bool checked) {
    // Checkbox clicked? If it's checked, time to dip.
    if (checked) {
        this->close();
    }
}

