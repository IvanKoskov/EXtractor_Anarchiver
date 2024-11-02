/********************************************************************************
** Form generated from reading UI file 'greeting.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GREETING_H
#define UI_GREETING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_greeting
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QPushButton *pushButton;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QPushButton *pushButton_3;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_13;
    QCheckBox *checkBox;
    QLabel *label_12;

    void setupUi(QDialog *greeting)
    {
        if (greeting->objectName().isEmpty())
            greeting->setObjectName("greeting");
        greeting->resize(492, 630);
        QFont font;
        font.setBold(false);
        greeting->setFont(font);
        verticalLayoutWidget = new QWidget(greeting);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(10, 10, 382, 91));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName("label");
        QFont font1;
        font1.setPointSize(30);
        font1.setBold(true);
        label->setFont(font1);

        verticalLayout->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName("label_2");
        QFont font2;
        font2.setPointSize(11);
        font2.setBold(false);
        label_2->setFont(font2);

        horizontalLayout->addWidget(label_2);

        pushButton = new QPushButton(verticalLayoutWidget);
        pushButton->setObjectName("pushButton");
        pushButton->setFocusPolicy(Qt::FocusPolicy::ClickFocus);

        horizontalLayout->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout);

        verticalLayoutWidget_2 = new QWidget(greeting);
        verticalLayoutWidget_2->setObjectName("verticalLayoutWidget_2");
        verticalLayoutWidget_2->setGeometry(QRect(10, 110, 257, 360));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(verticalLayoutWidget_2);
        label_3->setObjectName("label_3");
        QFont font3;
        font3.setPointSize(25);
        font3.setBold(true);
        label_3->setFont(font3);

        verticalLayout_2->addWidget(label_3);

        label_4 = new QLabel(verticalLayoutWidget_2);
        label_4->setObjectName("label_4");
        label_4->setFont(font);

        verticalLayout_2->addWidget(label_4);

        label_5 = new QLabel(verticalLayoutWidget_2);
        label_5->setObjectName("label_5");

        verticalLayout_2->addWidget(label_5);

        label_6 = new QLabel(verticalLayoutWidget_2);
        label_6->setObjectName("label_6");

        verticalLayout_2->addWidget(label_6);

        label_7 = new QLabel(verticalLayoutWidget_2);
        label_7->setObjectName("label_7");

        verticalLayout_2->addWidget(label_7);

        pushButton_3 = new QPushButton(verticalLayoutWidget_2);
        pushButton_3->setObjectName("pushButton_3");
        QFont font4;
        font4.setBold(true);
        pushButton_3->setFont(font4);

        verticalLayout_2->addWidget(pushButton_3);

        label_8 = new QLabel(verticalLayoutWidget_2);
        label_8->setObjectName("label_8");
        QFont font5;
        font5.setPointSize(23);
        font5.setBold(true);
        label_8->setFont(font5);

        verticalLayout_2->addWidget(label_8);

        label_9 = new QLabel(verticalLayoutWidget_2);
        label_9->setObjectName("label_9");

        verticalLayout_2->addWidget(label_9);

        label_10 = new QLabel(verticalLayoutWidget_2);
        label_10->setObjectName("label_10");

        verticalLayout_2->addWidget(label_10);

        label_11 = new QLabel(verticalLayoutWidget_2);
        label_11->setObjectName("label_11");

        verticalLayout_2->addWidget(label_11);

        label_13 = new QLabel(verticalLayoutWidget_2);
        label_13->setObjectName("label_13");

        verticalLayout_2->addWidget(label_13);

        checkBox = new QCheckBox(verticalLayoutWidget_2);
        checkBox->setObjectName("checkBox");

        verticalLayout_2->addWidget(checkBox);

        label_12 = new QLabel(greeting);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(337, 5, 61, 61));

        retranslateUi(greeting);

        QMetaObject::connectSlotsByName(greeting);
    } // setupUi

    void retranslateUi(QDialog *greeting)
    {
        greeting->setWindowTitle(QCoreApplication::translate("greeting", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("greeting", "Welcome to EXtractor!", nullptr));
        label_2->setText(QCoreApplication::translate("greeting", "It is a free open source alternative for the app", nullptr));
        pushButton->setText(QCoreApplication::translate("greeting", "by qing qing yu", nullptr));
        label_3->setText(QCoreApplication::translate("greeting", "You can:", nullptr));
        label_4->setText(QCoreApplication::translate("greeting", "\342\200\242Unarchive files easily", nullptr));
        label_5->setText(QCoreApplication::translate("greeting", "\342\200\242Archive files and set a password", nullptr));
        label_6->setText(QCoreApplication::translate("greeting", "\342\200\242Includes paid features from qing qing yu", nullptr));
        label_7->setText(QCoreApplication::translate("greeting", "\342\200\242Can be set as a default in your system", nullptr));
        pushButton_3->setText(QCoreApplication::translate("greeting", "GItHub Open Sourced", nullptr));
        label_8->setText(QCoreApplication::translate("greeting", "Inspired by:", nullptr));
        label_9->setText(QCoreApplication::translate("greeting", "\342\200\242RAR Extractor - Unarchiver", nullptr));
        label_10->setText(QCoreApplication::translate("greeting", "\342\200\242EXtractor tries to deliever same features", nullptr));
        label_11->setText(QCoreApplication::translate("greeting", "\342\200\242with even more free functionality.", nullptr));
        label_13->setText(QCoreApplication::translate("greeting", "\342\200\242it is a single developer)", nullptr));
        checkBox->setText(QCoreApplication::translate("greeting", "Continue", nullptr));
        label_12->setText(QCoreApplication::translate("greeting", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class greeting: public Ui_greeting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GREETING_H
