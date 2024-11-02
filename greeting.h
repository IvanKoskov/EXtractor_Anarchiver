#ifndef GREETING_H
#define GREETING_H

#include <QDialog>

namespace Ui {
class greeting;
}

class greeting : public QDialog
{
    Q_OBJECT

public:
    explicit greeting(QWidget *parent = nullptr);
    ~greeting();



private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();



    void on_checkBox_clicked(bool checked);

private:
    Ui::greeting *ui;
    void promptForFullDiskAccess();

};

#endif // GREETING_H
