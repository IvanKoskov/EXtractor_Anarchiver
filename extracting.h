#ifndef EXTRACTING_H
#define EXTRACTING_H

#include <QDialog>

namespace Ui {
class extracting;
}

class extracting : public QDialog
{
    Q_OBJECT

public:
    explicit extracting(QWidget *parent = nullptr);
    ~extracting();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::extracting *ui;
     QString selectedFilePath;
    QString savepath;
     void extractArchive(const QString &selectedFilePath, const QString &savePath);
};

#endif // EXTRACTING_H
