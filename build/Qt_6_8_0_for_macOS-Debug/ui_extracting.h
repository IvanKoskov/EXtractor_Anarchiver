/********************************************************************************
** Form generated from reading UI file 'extracting.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXTRACTING_H
#define UI_EXTRACTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_extracting
{
public:
    QLabel *label;
    QLabel *label_2;
    QComboBox *comboBox;
    QPushButton *pushButton;
    QLabel *label_3;
    QPushButton *pushButton_2;
    QLabel *label_4;
    QPushButton *pushButton_3;

    void setupUi(QDialog *extracting)
    {
        if (extracting->objectName().isEmpty())
            extracting->setObjectName("extracting");
        extracting->resize(400, 300);
        label = new QLabel(extracting);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 10, 231, 231));
        label_2 = new QLabel(extracting);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 20, 81, 16));
        comboBox = new QComboBox(extracting);
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(10, 40, 103, 32));
        pushButton = new QPushButton(extracting);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(120, 40, 51, 32));
        label_3 = new QLabel(extracting);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(20, 70, 151, 16));
        pushButton_2 = new QPushButton(extracting);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(20, 90, 151, 32));
        label_4 = new QLabel(extracting);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(20, 120, 91, 16));
        pushButton_3 = new QPushButton(extracting);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(20, 140, 71, 32));

        retranslateUi(extracting);

        QMetaObject::connectSlotsByName(extracting);
    } // setupUi

    void retranslateUi(QDialog *extracting)
    {
        extracting->setWindowTitle(QCoreApplication::translate("extracting", "Dialog", nullptr));
        label->setText(QString());
        label_2->setText(QCoreApplication::translate("extracting", "Extraction to:", nullptr));
        pushButton->setText(QCoreApplication::translate("extracting", "Apply", nullptr));
        label_3->setText(QCoreApplication::translate("extracting", "choose the saving path", nullptr));
        pushButton_2->setText(QCoreApplication::translate("extracting", "Open finder", nullptr));
        label_4->setText(QCoreApplication::translate("extracting", "choose archive", nullptr));
        pushButton_3->setText(QCoreApplication::translate("extracting", "anarchive", nullptr));
    } // retranslateUi

};

namespace Ui {
    class extracting: public Ui_extracting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXTRACTING_H
