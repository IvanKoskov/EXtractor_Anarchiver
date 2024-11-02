#ifndef ARCHIVINGW_H
#define ARCHIVINGW_H

#include <QDialog>

namespace Ui {
class archivingw;
}

class archivingw : public QDialog
{
    Q_OBJECT

public:
    explicit archivingw(QWidget *parent = nullptr);
    ~archivingw();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::archivingw *ui;
    void populateList();
    void selectAndCopyFile();
};

#endif // ARCHIVINGW_H
