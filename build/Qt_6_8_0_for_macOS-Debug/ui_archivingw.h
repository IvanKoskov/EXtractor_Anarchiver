/********************************************************************************
** Form generated from reading UI file 'archivingw.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ARCHIVINGW_H
#define UI_ARCHIVINGW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_archivingw
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QTableWidget *tableWidget;
    QLabel *label_2;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label_3;
    QLineEdit *passwordin;
    QLabel *label_4;
    QComboBox *comboBox;
    QPushButton *pushButton_3;
    QLabel *label_6;
    QLabel *label_5;

    void setupUi(QDialog *archivingw)
    {
        if (archivingw->objectName().isEmpty())
            archivingw->setObjectName("archivingw");
        archivingw->resize(528, 411);
        verticalLayoutWidget = new QWidget(archivingw);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(10, 10, 261, 281));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName("label");
        QFont font;
        font.setPointSize(25);
        font.setBold(true);
        label->setFont(font);

        verticalLayout->addWidget(label);

        tableWidget = new QTableWidget(verticalLayoutWidget);
        tableWidget->setObjectName("tableWidget");

        verticalLayout->addWidget(tableWidget);

        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName("label_2");
        QFont font1;
        font1.setPointSize(10);
        label_2->setFont(font1);

        verticalLayout->addWidget(label_2);

        verticalLayoutWidget_2 = new QWidget(archivingw);
        verticalLayoutWidget_2->setObjectName("verticalLayoutWidget_2");
        verticalLayoutWidget_2->setGeometry(QRect(280, 50, 125, 241));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(verticalLayoutWidget_2);
        pushButton->setObjectName("pushButton");

        verticalLayout_2->addWidget(pushButton);

        pushButton_2 = new QPushButton(verticalLayoutWidget_2);
        pushButton_2->setObjectName("pushButton_2");

        verticalLayout_2->addWidget(pushButton_2);

        label_3 = new QLabel(verticalLayoutWidget_2);
        label_3->setObjectName("label_3");

        verticalLayout_2->addWidget(label_3);

        passwordin = new QLineEdit(verticalLayoutWidget_2);
        passwordin->setObjectName("passwordin");

        verticalLayout_2->addWidget(passwordin);

        label_4 = new QLabel(verticalLayoutWidget_2);
        label_4->setObjectName("label_4");

        verticalLayout_2->addWidget(label_4);

        comboBox = new QComboBox(verticalLayoutWidget_2);
        comboBox->setObjectName("comboBox");
        comboBox->setFont(font1);

        verticalLayout_2->addWidget(comboBox);

        pushButton_3 = new QPushButton(verticalLayoutWidget_2);
        pushButton_3->setObjectName("pushButton_3");

        verticalLayout_2->addWidget(pushButton_3);

        label_6 = new QLabel(verticalLayoutWidget_2);
        label_6->setObjectName("label_6");
        label_6->setFont(font1);

        verticalLayout_2->addWidget(label_6);

        label_5 = new QLabel(archivingw);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(280, 10, 121, 31));
        label_5->setFont(font);

        retranslateUi(archivingw);

        QMetaObject::connectSlotsByName(archivingw);
    } // setupUi

    void retranslateUi(QDialog *archivingw)
    {
        archivingw->setWindowTitle(QCoreApplication::translate("archivingw", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("archivingw", "Import", nullptr));
        label_2->setText(QCoreApplication::translate("archivingw", "Support interaction", nullptr));
        pushButton->setText(QCoreApplication::translate("archivingw", "add files(s)", nullptr));
        pushButton_2->setText(QCoreApplication::translate("archivingw", "remove file(s)", nullptr));
        label_3->setText(QCoreApplication::translate("archivingw", "Password setting", nullptr));
        label_4->setText(QCoreApplication::translate("archivingw", "Select format", nullptr));
        pushButton_3->setText(QCoreApplication::translate("archivingw", "Start", nullptr));
        label_6->setText(QCoreApplication::translate("archivingw", "it can take some time..", nullptr));
        label_5->setText(QCoreApplication::translate("archivingw", "Settings", nullptr));
    } // retranslateUi

};

namespace Ui {
    class archivingw: public Ui_archivingw {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ARCHIVINGW_H
