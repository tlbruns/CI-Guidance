/********************************************************************************
** Form generated from reading UI file 'patient_registration.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PATIENT_REGISTRATION_H
#define UI_PATIENT_REGISTRATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_PatientRegistration
{
public:
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox_header;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label_5;
    QLabel *label_6;
    QGroupBox *groupBox_mk1;
    QGridLayout *gridLayout_2;
    QPushButton *button_mk1_collection;
    QProgressBar *progressBar_mk1;
    QFormLayout *formLayout;
    QLabel *label_2;
    QLabel *label_mk1_x;
    QLabel *label_3;
    QLabel *label_mk1_y;
    QLabel *label_4;
    QLabel *label_mk1_z;
    QLabel *label_mk1_msg;
    QGroupBox *groupBox_mk2;
    QGridLayout *gridLayout_3;
    QPushButton *button_mk2_collection;
    QProgressBar *progressBar_mk2;
    QFormLayout *formLayout_2;
    QLabel *label_7;
    QLabel *label_mk2_x;
    QLabel *label_8;
    QLabel *label_mk2_y;
    QLabel *label_9;
    QLabel *label_mk2_z;
    QLabel *label_mk2_msg;
    QGroupBox *groupBox_mk3;
    QGridLayout *gridLayout_4;
    QPushButton *button_mk3_collection;
    QProgressBar *progressBar_mk3;
    QFormLayout *formLayout_3;
    QLabel *label_10;
    QLabel *label_mk3_x;
    QLabel *label_11;
    QLabel *label_mk3_y;
    QLabel *label_12;
    QLabel *label_mk3_z;
    QLabel *label_mk3_msg;
    QGroupBox *groupBox_skull;
    QGridLayout *gridLayout_5;
    QPushButton *button_skull_collection;
    QProgressBar *progressBar_skull;
    QLabel *label_skull_msg;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_registration_msg;
    QLabel *label_registration_check;
    QHBoxLayout *horizontalLayout;
    QPushButton *button_cancel;
    QSpacerItem *horizontalSpacer;
    QPushButton *button_finish;

    void setupUi(QDialog *PatientRegistration)
    {
        if (PatientRegistration->objectName().isEmpty())
            PatientRegistration->setObjectName(QStringLiteral("PatientRegistration"));
        PatientRegistration->setWindowModality(Qt::ApplicationModal);
        PatientRegistration->resize(709, 1292);
        verticalLayout_3 = new QVBoxLayout(PatientRegistration);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        groupBox_header = new QGroupBox(PatientRegistration);
        groupBox_header->setObjectName(QStringLiteral("groupBox_header"));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        font.setUnderline(false);
        font.setWeight(75);
        groupBox_header->setFont(font);
        groupBox_header->setAlignment(Qt::AlignCenter);
        gridLayout = new QGridLayout(groupBox_header);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_5 = new QLabel(groupBox_header);
        label_5->setObjectName(QStringLiteral("label_5"));
        QFont font1;
        font1.setPointSize(11);
        font1.setBold(false);
        font1.setUnderline(true);
        font1.setWeight(50);
        label_5->setFont(font1);

        verticalLayout->addWidget(label_5);

        label_6 = new QLabel(groupBox_header);
        label_6->setObjectName(QStringLiteral("label_6"));
        QFont font2;
        font2.setPointSize(9);
        font2.setBold(false);
        font2.setWeight(50);
        label_6->setFont(font2);
        label_6->setAlignment(Qt::AlignJustify|Qt::AlignTop);
        label_6->setWordWrap(true);

        verticalLayout->addWidget(label_6);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        verticalLayout_3->addWidget(groupBox_header);

        groupBox_mk1 = new QGroupBox(PatientRegistration);
        groupBox_mk1->setObjectName(QStringLiteral("groupBox_mk1"));
        QFont font3;
        font3.setPointSize(10);
        font3.setBold(true);
        font3.setUnderline(false);
        font3.setWeight(75);
        groupBox_mk1->setFont(font3);
        gridLayout_2 = new QGridLayout(groupBox_mk1);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        button_mk1_collection = new QPushButton(groupBox_mk1);
        button_mk1_collection->setObjectName(QStringLiteral("button_mk1_collection"));
        QFont font4;
        font4.setPointSize(8);
        font4.setBold(false);
        font4.setWeight(50);
        button_mk1_collection->setFont(font4);

        gridLayout_2->addWidget(button_mk1_collection, 0, 0, 1, 1);

        progressBar_mk1 = new QProgressBar(groupBox_mk1);
        progressBar_mk1->setObjectName(QStringLiteral("progressBar_mk1"));
        QFont font5;
        font5.setFamily(QStringLiteral("Lucida Console"));
        font5.setBold(false);
        font5.setItalic(false);
        font5.setWeight(50);
        progressBar_mk1->setFont(font5);
        progressBar_mk1->setMaximum(200);
        progressBar_mk1->setValue(0);
        progressBar_mk1->setAlignment(Qt::AlignCenter);
        progressBar_mk1->setInvertedAppearance(false);
        progressBar_mk1->setTextDirection(QProgressBar::TopToBottom);

        gridLayout_2->addWidget(progressBar_mk1, 0, 1, 1, 1);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label_2 = new QLabel(groupBox_mk1);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(30, 0));
        label_2->setFont(font4);
        label_2->setTextFormat(Qt::RichText);

        formLayout->setWidget(0, QFormLayout::LabelRole, label_2);

        label_mk1_x = new QLabel(groupBox_mk1);
        label_mk1_x->setObjectName(QStringLiteral("label_mk1_x"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_mk1_x->sizePolicy().hasHeightForWidth());
        label_mk1_x->setSizePolicy(sizePolicy);
        label_mk1_x->setMinimumSize(QSize(0, 0));
        QFont font6;
        font6.setFamily(QStringLiteral("Lucida Console"));
        font6.setPointSize(8);
        font6.setBold(false);
        font6.setWeight(50);
        label_mk1_x->setFont(font6);
        label_mk1_x->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout->setWidget(0, QFormLayout::FieldRole, label_mk1_x);

        label_3 = new QLabel(groupBox_mk1);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font4);
        label_3->setTextFormat(Qt::RichText);

        formLayout->setWidget(1, QFormLayout::LabelRole, label_3);

        label_mk1_y = new QLabel(groupBox_mk1);
        label_mk1_y->setObjectName(QStringLiteral("label_mk1_y"));
        label_mk1_y->setMinimumSize(QSize(0, 0));
        label_mk1_y->setFont(font6);
        label_mk1_y->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout->setWidget(1, QFormLayout::FieldRole, label_mk1_y);

        label_4 = new QLabel(groupBox_mk1);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font4);

        formLayout->setWidget(2, QFormLayout::LabelRole, label_4);

        label_mk1_z = new QLabel(groupBox_mk1);
        label_mk1_z->setObjectName(QStringLiteral("label_mk1_z"));
        label_mk1_z->setMinimumSize(QSize(0, 0));
        label_mk1_z->setFont(font6);
        label_mk1_z->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout->setWidget(2, QFormLayout::FieldRole, label_mk1_z);


        gridLayout_2->addLayout(formLayout, 1, 0, 1, 1);

        label_mk1_msg = new QLabel(groupBox_mk1);
        label_mk1_msg->setObjectName(QStringLiteral("label_mk1_msg"));
        QFont font7;
        font7.setBold(false);
        font7.setWeight(50);
        label_mk1_msg->setFont(font7);
        label_mk1_msg->setAlignment(Qt::AlignHCenter|Qt::AlignTop);

        gridLayout_2->addWidget(label_mk1_msg, 1, 1, 1, 1);


        verticalLayout_3->addWidget(groupBox_mk1);

        groupBox_mk2 = new QGroupBox(PatientRegistration);
        groupBox_mk2->setObjectName(QStringLiteral("groupBox_mk2"));
        groupBox_mk2->setFont(font3);
        gridLayout_3 = new QGridLayout(groupBox_mk2);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        button_mk2_collection = new QPushButton(groupBox_mk2);
        button_mk2_collection->setObjectName(QStringLiteral("button_mk2_collection"));
        button_mk2_collection->setFont(font4);

        gridLayout_3->addWidget(button_mk2_collection, 0, 0, 1, 1);

        progressBar_mk2 = new QProgressBar(groupBox_mk2);
        progressBar_mk2->setObjectName(QStringLiteral("progressBar_mk2"));
        progressBar_mk2->setFont(font5);
        progressBar_mk2->setMaximum(200);
        progressBar_mk2->setValue(0);
        progressBar_mk2->setAlignment(Qt::AlignCenter);
        progressBar_mk2->setInvertedAppearance(false);
        progressBar_mk2->setTextDirection(QProgressBar::TopToBottom);

        gridLayout_3->addWidget(progressBar_mk2, 0, 1, 1, 1);

        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        label_7 = new QLabel(groupBox_mk2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setMinimumSize(QSize(30, 0));
        label_7->setFont(font4);
        label_7->setTextFormat(Qt::RichText);

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_7);

        label_mk2_x = new QLabel(groupBox_mk2);
        label_mk2_x->setObjectName(QStringLiteral("label_mk2_x"));
        sizePolicy.setHeightForWidth(label_mk2_x->sizePolicy().hasHeightForWidth());
        label_mk2_x->setSizePolicy(sizePolicy);
        label_mk2_x->setMinimumSize(QSize(0, 0));
        label_mk2_x->setFont(font6);
        label_mk2_x->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, label_mk2_x);

        label_8 = new QLabel(groupBox_mk2);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setFont(font4);
        label_8->setTextFormat(Qt::RichText);

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_8);

        label_mk2_y = new QLabel(groupBox_mk2);
        label_mk2_y->setObjectName(QStringLiteral("label_mk2_y"));
        label_mk2_y->setMinimumSize(QSize(0, 0));
        label_mk2_y->setFont(font6);
        label_mk2_y->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout_2->setWidget(1, QFormLayout::FieldRole, label_mk2_y);

        label_9 = new QLabel(groupBox_mk2);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setFont(font4);

        formLayout_2->setWidget(2, QFormLayout::LabelRole, label_9);

        label_mk2_z = new QLabel(groupBox_mk2);
        label_mk2_z->setObjectName(QStringLiteral("label_mk2_z"));
        label_mk2_z->setMinimumSize(QSize(0, 0));
        label_mk2_z->setFont(font6);
        label_mk2_z->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout_2->setWidget(2, QFormLayout::FieldRole, label_mk2_z);


        gridLayout_3->addLayout(formLayout_2, 1, 0, 1, 1);

        label_mk2_msg = new QLabel(groupBox_mk2);
        label_mk2_msg->setObjectName(QStringLiteral("label_mk2_msg"));
        label_mk2_msg->setFont(font7);
        label_mk2_msg->setAlignment(Qt::AlignHCenter|Qt::AlignTop);

        gridLayout_3->addWidget(label_mk2_msg, 1, 1, 1, 1);


        verticalLayout_3->addWidget(groupBox_mk2);

        groupBox_mk3 = new QGroupBox(PatientRegistration);
        groupBox_mk3->setObjectName(QStringLiteral("groupBox_mk3"));
        groupBox_mk3->setFont(font3);
        gridLayout_4 = new QGridLayout(groupBox_mk3);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        button_mk3_collection = new QPushButton(groupBox_mk3);
        button_mk3_collection->setObjectName(QStringLiteral("button_mk3_collection"));
        button_mk3_collection->setFont(font4);

        gridLayout_4->addWidget(button_mk3_collection, 0, 0, 1, 1);

        progressBar_mk3 = new QProgressBar(groupBox_mk3);
        progressBar_mk3->setObjectName(QStringLiteral("progressBar_mk3"));
        progressBar_mk3->setFont(font5);
        progressBar_mk3->setMaximum(200);
        progressBar_mk3->setValue(0);
        progressBar_mk3->setAlignment(Qt::AlignCenter);
        progressBar_mk3->setInvertedAppearance(false);
        progressBar_mk3->setTextDirection(QProgressBar::TopToBottom);

        gridLayout_4->addWidget(progressBar_mk3, 0, 1, 1, 1);

        formLayout_3 = new QFormLayout();
        formLayout_3->setObjectName(QStringLiteral("formLayout_3"));
        label_10 = new QLabel(groupBox_mk3);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setMinimumSize(QSize(30, 0));
        label_10->setFont(font4);
        label_10->setTextFormat(Qt::RichText);

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label_10);

        label_mk3_x = new QLabel(groupBox_mk3);
        label_mk3_x->setObjectName(QStringLiteral("label_mk3_x"));
        sizePolicy.setHeightForWidth(label_mk3_x->sizePolicy().hasHeightForWidth());
        label_mk3_x->setSizePolicy(sizePolicy);
        label_mk3_x->setMinimumSize(QSize(0, 0));
        label_mk3_x->setFont(font6);
        label_mk3_x->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout_3->setWidget(0, QFormLayout::FieldRole, label_mk3_x);

        label_11 = new QLabel(groupBox_mk3);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setFont(font4);
        label_11->setTextFormat(Qt::RichText);

        formLayout_3->setWidget(1, QFormLayout::LabelRole, label_11);

        label_mk3_y = new QLabel(groupBox_mk3);
        label_mk3_y->setObjectName(QStringLiteral("label_mk3_y"));
        label_mk3_y->setMinimumSize(QSize(0, 0));
        label_mk3_y->setFont(font6);
        label_mk3_y->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout_3->setWidget(1, QFormLayout::FieldRole, label_mk3_y);

        label_12 = new QLabel(groupBox_mk3);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setFont(font4);

        formLayout_3->setWidget(2, QFormLayout::LabelRole, label_12);

        label_mk3_z = new QLabel(groupBox_mk3);
        label_mk3_z->setObjectName(QStringLiteral("label_mk3_z"));
        label_mk3_z->setMinimumSize(QSize(0, 0));
        label_mk3_z->setFont(font6);
        label_mk3_z->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout_3->setWidget(2, QFormLayout::FieldRole, label_mk3_z);


        gridLayout_4->addLayout(formLayout_3, 1, 0, 1, 1);

        label_mk3_msg = new QLabel(groupBox_mk3);
        label_mk3_msg->setObjectName(QStringLiteral("label_mk3_msg"));
        label_mk3_msg->setFont(font7);
        label_mk3_msg->setAlignment(Qt::AlignHCenter|Qt::AlignTop);

        gridLayout_4->addWidget(label_mk3_msg, 1, 1, 1, 1);


        verticalLayout_3->addWidget(groupBox_mk3);

        groupBox_skull = new QGroupBox(PatientRegistration);
        groupBox_skull->setObjectName(QStringLiteral("groupBox_skull"));
        groupBox_skull->setFont(font3);
        gridLayout_5 = new QGridLayout(groupBox_skull);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        button_skull_collection = new QPushButton(groupBox_skull);
        button_skull_collection->setObjectName(QStringLiteral("button_skull_collection"));
        button_skull_collection->setFont(font4);

        gridLayout_5->addWidget(button_skull_collection, 0, 0, 1, 1);

        progressBar_skull = new QProgressBar(groupBox_skull);
        progressBar_skull->setObjectName(QStringLiteral("progressBar_skull"));
        progressBar_skull->setFont(font5);
        progressBar_skull->setMaximum(200);
        progressBar_skull->setValue(0);
        progressBar_skull->setAlignment(Qt::AlignCenter);
        progressBar_skull->setInvertedAppearance(false);
        progressBar_skull->setTextDirection(QProgressBar::TopToBottom);

        gridLayout_5->addWidget(progressBar_skull, 0, 1, 1, 1);

        label_skull_msg = new QLabel(groupBox_skull);
        label_skull_msg->setObjectName(QStringLiteral("label_skull_msg"));
        label_skull_msg->setFont(font7);
        label_skull_msg->setAlignment(Qt::AlignHCenter|Qt::AlignTop);

        gridLayout_5->addWidget(label_skull_msg, 1, 1, 1, 1);


        verticalLayout_3->addWidget(groupBox_skull);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_registration_msg = new QLabel(PatientRegistration);
        label_registration_msg->setObjectName(QStringLiteral("label_registration_msg"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(1);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_registration_msg->sizePolicy().hasHeightForWidth());
        label_registration_msg->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(label_registration_msg);

        label_registration_check = new QLabel(PatientRegistration);
        label_registration_check->setObjectName(QStringLiteral("label_registration_check"));
        label_registration_check->setMinimumSize(QSize(50, 0));

        horizontalLayout_2->addWidget(label_registration_check);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        button_cancel = new QPushButton(PatientRegistration);
        button_cancel->setObjectName(QStringLiteral("button_cancel"));

        horizontalLayout->addWidget(button_cancel);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        button_finish = new QPushButton(PatientRegistration);
        button_finish->setObjectName(QStringLiteral("button_finish"));
        button_finish->setCheckable(false);
        button_finish->setFlat(false);

        horizontalLayout->addWidget(button_finish);


        verticalLayout_2->addLayout(horizontalLayout);


        verticalLayout_3->addLayout(verticalLayout_2);


        retranslateUi(PatientRegistration);
        QObject::connect(button_cancel, SIGNAL(clicked()), PatientRegistration, SLOT(close()));

        button_finish->setDefault(false);


        QMetaObject::connectSlotsByName(PatientRegistration);
    } // setupUi

    void retranslateUi(QDialog *PatientRegistration)
    {
        PatientRegistration->setWindowTitle(QApplication::translate("PatientRegistration", "Dialog", nullptr));
        groupBox_header->setTitle(QApplication::translate("PatientRegistration", "Patient Registration", nullptr));
        label_5->setText(QApplication::translate("PatientRegistration", "Instructions:", nullptr));
        label_6->setText(QApplication::translate("PatientRegistration", "Place the probe on each marker and press \"Start Collection\" to begin sampling after a 3 second delay. A fit check will be performed once all markers have been registered. If it fails, you must repeat before saving.", nullptr));
        groupBox_mk1->setTitle(QApplication::translate("PatientRegistration", "Marker 1", nullptr));
        button_mk1_collection->setText(QApplication::translate("PatientRegistration", "Start Collection", nullptr));
        progressBar_mk1->setFormat(QApplication::translate("PatientRegistration", "%v/%m", nullptr));
        label_2->setText(QApplication::translate("PatientRegistration", "<b>x</b>", nullptr));
        label_mk1_x->setText(QApplication::translate("PatientRegistration", "-0000.00", nullptr));
        label_3->setText(QApplication::translate("PatientRegistration", "<b>y</b>", nullptr));
        label_mk1_y->setText(QApplication::translate("PatientRegistration", "-0000.00", nullptr));
        label_4->setText(QApplication::translate("PatientRegistration", "<b>z</b>", nullptr));
        label_mk1_z->setText(QApplication::translate("PatientRegistration", "-0000.00", nullptr));
        label_mk1_msg->setText(QString());
        groupBox_mk2->setTitle(QApplication::translate("PatientRegistration", "Marker 2", nullptr));
        button_mk2_collection->setText(QApplication::translate("PatientRegistration", "Start Collection", nullptr));
        progressBar_mk2->setFormat(QApplication::translate("PatientRegistration", "%v/%m", nullptr));
        label_7->setText(QApplication::translate("PatientRegistration", "<b>x</b>", nullptr));
        label_mk2_x->setText(QApplication::translate("PatientRegistration", "-0000.00", nullptr));
        label_8->setText(QApplication::translate("PatientRegistration", "<b>y</b>", nullptr));
        label_mk2_y->setText(QApplication::translate("PatientRegistration", "-0000.00", nullptr));
        label_9->setText(QApplication::translate("PatientRegistration", "<b>z</b>", nullptr));
        label_mk2_z->setText(QApplication::translate("PatientRegistration", "-0000.00", nullptr));
        label_mk2_msg->setText(QString());
        groupBox_mk3->setTitle(QApplication::translate("PatientRegistration", "Marker 3", nullptr));
        button_mk3_collection->setText(QApplication::translate("PatientRegistration", "Start Collection", nullptr));
        progressBar_mk3->setFormat(QApplication::translate("PatientRegistration", "%v/%m", nullptr));
        label_10->setText(QApplication::translate("PatientRegistration", "<b>x</b>", nullptr));
        label_mk3_x->setText(QApplication::translate("PatientRegistration", "-0000.00", nullptr));
        label_11->setText(QApplication::translate("PatientRegistration", "<b>y</b>", nullptr));
        label_mk3_y->setText(QApplication::translate("PatientRegistration", "-0000.00", nullptr));
        label_12->setText(QApplication::translate("PatientRegistration", "<b>z</b>", nullptr));
        label_mk3_z->setText(QApplication::translate("PatientRegistration", "-0000.00", nullptr));
        label_mk3_msg->setText(QString());
        groupBox_skull->setTitle(QApplication::translate("PatientRegistration", "Skull Markers", nullptr));
        button_skull_collection->setText(QApplication::translate("PatientRegistration", "Start Collection", nullptr));
        progressBar_skull->setFormat(QApplication::translate("PatientRegistration", "%v/%m", nullptr));
        label_skull_msg->setText(QString());
        label_registration_msg->setText(QString());
        label_registration_check->setText(QString());
        button_cancel->setText(QApplication::translate("PatientRegistration", "Cancel", nullptr));
        button_finish->setText(QApplication::translate("PatientRegistration", "Register", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PatientRegistration: public Ui_PatientRegistration {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PATIENT_REGISTRATION_H
