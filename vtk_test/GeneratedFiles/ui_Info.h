/********************************************************************************
** Form generated from reading UI file 'Info.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INFO_H
#define UI_INFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Info
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *probeBox;
    QHBoxLayout *horizontalLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QLabel *label_probe_x;
    QLabel *label_2;
    QLabel *label_probe_y;
    QLabel *label_3;
    QLabel *label_probe_z;
    QPushButton *button_centerProbe;
    QSpacerItem *horizontalSpacer;
    QGroupBox *CIToolBox;
    QHBoxLayout *horizontalLayout_2;
    QFormLayout *formLayout_2;
    QLabel *label_4;
    QLabel *label_ci_x;
    QLabel *label_5;
    QLabel *label_ci_y;
    QLabel *label_6;
    QLabel *label_ci_z;
    QPushButton *button_centerCItool;
    QSpacerItem *horizontalSpacer_2;
    QGroupBox *MagnetBox;
    QHBoxLayout *horizontalLayout_3;
    QFormLayout *formLayout_3;
    QLabel *label_7;
    QLabel *label_mag_x;
    QLabel *label_8;
    QLabel *label_mag_y;
    QLabel *label_9;
    QLabel *label_mag_z;
    QSpacerItem *horizontalSpacer_3;
    QCheckBox *checkBox_LiveTarget;
    QLabel *label_FRE;
    QGroupBox *ErrorBox_position;
    QGridLayout *gridLayout;
    QLabel *label_ci_err_pos;
    QLabel *label_mag_status;
    QLabel *label_text_CITool_pos;
    QProgressBar *progressBar_CI_err_pos;
    QProgressBar *progressBar_mag_err;
    QLabel *label_ci_status;
    QLabel *label_text_Magnet;
    QLabel *label_mag_err;
    QSpacerItem *verticalSpacer;
    QLabel *label_text_error2_2;
    QLabel *label_text_error2;
    QLabel *label_text_error2_3;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *horizontalSpacer_7;
    QGroupBox *ErrorBox_angle;
    QGridLayout *gridLayout_4;
    QLabel *label_ci_err_ang;
    QProgressBar *progressBar_CI_err_ang;
    QLabel *label_text_error2_4;
    QSpacerItem *horizontalSpacer_6;
    QLabel *label_ci_status_ang;
    QLabel *label_text_error2_5;
    QLabel *label_mag_status_3;
    QLabel *label_text_CITool_ang;
    QSpacerItem *horizontalSpacer_8;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *button_recordData;
    QLabel *label_recordData;
    QSpacerItem *horizontalSpacer_9;
    QHBoxLayout *Logos;
    QLabel *logo_VUeng;
    QLabel *logo_medlab;

    void setupUi(QWidget *Info)
    {
        if (Info->objectName().isEmpty())
            Info->setObjectName(QStringLiteral("Info"));
        Info->resize(455, 1284);
        Info->setMinimumSize(QSize(0, 1284));
        verticalLayout = new QVBoxLayout(Info);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        probeBox = new QGroupBox(Info);
        probeBox->setObjectName(QStringLiteral("probeBox"));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        probeBox->setFont(font);
        horizontalLayout = new QHBoxLayout(probeBox);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label = new QLabel(probeBox);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(30, 0));
        QFont font1;
        font1.setPointSize(8);
        font1.setBold(false);
        font1.setWeight(50);
        label->setFont(font1);
        label->setTextFormat(Qt::RichText);

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        label_probe_x = new QLabel(probeBox);
        label_probe_x->setObjectName(QStringLiteral("label_probe_x"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_probe_x->sizePolicy().hasHeightForWidth());
        label_probe_x->setSizePolicy(sizePolicy);
        label_probe_x->setMinimumSize(QSize(0, 0));
        QFont font2;
        font2.setFamily(QStringLiteral("Lucida Console"));
        font2.setPointSize(8);
        font2.setBold(false);
        font2.setWeight(50);
        label_probe_x->setFont(font2);
        label_probe_x->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout->setWidget(0, QFormLayout::FieldRole, label_probe_x);

        label_2 = new QLabel(probeBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font1);
        label_2->setTextFormat(Qt::RichText);

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        label_probe_y = new QLabel(probeBox);
        label_probe_y->setObjectName(QStringLiteral("label_probe_y"));
        label_probe_y->setMinimumSize(QSize(0, 0));
        label_probe_y->setFont(font2);
        label_probe_y->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout->setWidget(1, QFormLayout::FieldRole, label_probe_y);

        label_3 = new QLabel(probeBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font1);

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        label_probe_z = new QLabel(probeBox);
        label_probe_z->setObjectName(QStringLiteral("label_probe_z"));
        label_probe_z->setMinimumSize(QSize(0, 0));
        label_probe_z->setFont(font2);
        label_probe_z->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout->setWidget(2, QFormLayout::FieldRole, label_probe_z);


        horizontalLayout->addLayout(formLayout);

        button_centerProbe = new QPushButton(probeBox);
        button_centerProbe->setObjectName(QStringLiteral("button_centerProbe"));
        button_centerProbe->setFont(font1);

        horizontalLayout->addWidget(button_centerProbe);

        horizontalSpacer = new QSpacerItem(274, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addWidget(probeBox);

        CIToolBox = new QGroupBox(Info);
        CIToolBox->setObjectName(QStringLiteral("CIToolBox"));
        CIToolBox->setFont(font);
        horizontalLayout_2 = new QHBoxLayout(CIToolBox);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        label_4 = new QLabel(CIToolBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMinimumSize(QSize(30, 0));
        QFont font3;
        font3.setPointSize(8);
        label_4->setFont(font3);
        label_4->setTextFormat(Qt::RichText);

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_4);

        label_ci_x = new QLabel(CIToolBox);
        label_ci_x->setObjectName(QStringLiteral("label_ci_x"));
        label_ci_x->setMinimumSize(QSize(0, 0));
        label_ci_x->setFont(font2);
        label_ci_x->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, label_ci_x);

        label_5 = new QLabel(CIToolBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font3);
        label_5->setTextFormat(Qt::RichText);

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_5);

        label_ci_y = new QLabel(CIToolBox);
        label_ci_y->setObjectName(QStringLiteral("label_ci_y"));
        label_ci_y->setFont(font2);
        label_ci_y->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout_2->setWidget(1, QFormLayout::FieldRole, label_ci_y);

        label_6 = new QLabel(CIToolBox);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font3);

        formLayout_2->setWidget(2, QFormLayout::LabelRole, label_6);

        label_ci_z = new QLabel(CIToolBox);
        label_ci_z->setObjectName(QStringLiteral("label_ci_z"));
        label_ci_z->setFont(font2);
        label_ci_z->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout_2->setWidget(2, QFormLayout::FieldRole, label_ci_z);


        horizontalLayout_2->addLayout(formLayout_2);

        button_centerCItool = new QPushButton(CIToolBox);
        button_centerCItool->setObjectName(QStringLiteral("button_centerCItool"));
        button_centerCItool->setFont(font1);

        horizontalLayout_2->addWidget(button_centerCItool);

        horizontalSpacer_2 = new QSpacerItem(342, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout->addWidget(CIToolBox);

        MagnetBox = new QGroupBox(Info);
        MagnetBox->setObjectName(QStringLiteral("MagnetBox"));
        MagnetBox->setFont(font);
        horizontalLayout_3 = new QHBoxLayout(MagnetBox);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        formLayout_3 = new QFormLayout();
        formLayout_3->setObjectName(QStringLiteral("formLayout_3"));
        label_7 = new QLabel(MagnetBox);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setMinimumSize(QSize(30, 0));
        label_7->setFont(font3);
        label_7->setTextFormat(Qt::RichText);

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label_7);

        label_mag_x = new QLabel(MagnetBox);
        label_mag_x->setObjectName(QStringLiteral("label_mag_x"));
        label_mag_x->setFont(font2);

        formLayout_3->setWidget(0, QFormLayout::FieldRole, label_mag_x);

        label_8 = new QLabel(MagnetBox);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setFont(font3);
        label_8->setTextFormat(Qt::RichText);

        formLayout_3->setWidget(1, QFormLayout::LabelRole, label_8);

        label_mag_y = new QLabel(MagnetBox);
        label_mag_y->setObjectName(QStringLiteral("label_mag_y"));
        label_mag_y->setFont(font2);

        formLayout_3->setWidget(1, QFormLayout::FieldRole, label_mag_y);

        label_9 = new QLabel(MagnetBox);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setFont(font3);

        formLayout_3->setWidget(2, QFormLayout::LabelRole, label_9);

        label_mag_z = new QLabel(MagnetBox);
        label_mag_z->setObjectName(QStringLiteral("label_mag_z"));
        label_mag_z->setFont(font2);

        formLayout_3->setWidget(2, QFormLayout::FieldRole, label_mag_z);


        horizontalLayout_3->addLayout(formLayout_3);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);


        verticalLayout->addWidget(MagnetBox);

        checkBox_LiveTarget = new QCheckBox(Info);
        checkBox_LiveTarget->setObjectName(QStringLiteral("checkBox_LiveTarget"));
        QFont font4;
        font4.setPointSize(9);
        checkBox_LiveTarget->setFont(font4);
        checkBox_LiveTarget->setCheckable(false);
        checkBox_LiveTarget->setChecked(false);

        verticalLayout->addWidget(checkBox_LiveTarget);

        label_FRE = new QLabel(Info);
        label_FRE->setObjectName(QStringLiteral("label_FRE"));
        label_FRE->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_FRE->sizePolicy().hasHeightForWidth());
        label_FRE->setSizePolicy(sizePolicy1);
        label_FRE->setFont(font4);

        verticalLayout->addWidget(label_FRE);

        ErrorBox_position = new QGroupBox(Info);
        ErrorBox_position->setObjectName(QStringLiteral("ErrorBox_position"));
        ErrorBox_position->setFont(font);
        gridLayout = new QGridLayout(ErrorBox_position);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_ci_err_pos = new QLabel(ErrorBox_position);
        label_ci_err_pos->setObjectName(QStringLiteral("label_ci_err_pos"));
        label_ci_err_pos->setFont(font2);
        label_ci_err_pos->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_ci_err_pos, 0, 3, 1, 1);

        label_mag_status = new QLabel(ErrorBox_position);
        label_mag_status->setObjectName(QStringLiteral("label_mag_status"));
        label_mag_status->setFont(font1);
        label_mag_status->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_mag_status, 3, 6, 1, 1);

        label_text_CITool_pos = new QLabel(ErrorBox_position);
        label_text_CITool_pos->setObjectName(QStringLiteral("label_text_CITool_pos"));
        label_text_CITool_pos->setFont(font3);

        gridLayout->addWidget(label_text_CITool_pos, 0, 0, 1, 1);

        progressBar_CI_err_pos = new QProgressBar(ErrorBox_position);
        progressBar_CI_err_pos->setObjectName(QStringLiteral("progressBar_CI_err_pos"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(progressBar_CI_err_pos->sizePolicy().hasHeightForWidth());
        progressBar_CI_err_pos->setSizePolicy(sizePolicy2);
        progressBar_CI_err_pos->setFont(font3);
        progressBar_CI_err_pos->setValue(0);
        progressBar_CI_err_pos->setTextVisible(false);

        gridLayout->addWidget(progressBar_CI_err_pos, 1, 0, 1, 7);

        progressBar_mag_err = new QProgressBar(ErrorBox_position);
        progressBar_mag_err->setObjectName(QStringLiteral("progressBar_mag_err"));
        progressBar_mag_err->setFont(font3);
        progressBar_mag_err->setValue(0);
        progressBar_mag_err->setTextVisible(false);
        progressBar_mag_err->setInvertedAppearance(false);
        progressBar_mag_err->setTextDirection(QProgressBar::BottomToTop);

        gridLayout->addWidget(progressBar_mag_err, 4, 0, 1, 7);

        label_ci_status = new QLabel(ErrorBox_position);
        label_ci_status->setObjectName(QStringLiteral("label_ci_status"));
        label_ci_status->setFont(font1);
        label_ci_status->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_ci_status, 0, 6, 1, 1);

        label_text_Magnet = new QLabel(ErrorBox_position);
        label_text_Magnet->setObjectName(QStringLiteral("label_text_Magnet"));
        label_text_Magnet->setFont(font3);

        gridLayout->addWidget(label_text_Magnet, 3, 0, 1, 1);

        label_mag_err = new QLabel(ErrorBox_position);
        label_mag_err->setObjectName(QStringLiteral("label_mag_err"));
        label_mag_err->setFont(font2);
        label_mag_err->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_mag_err, 3, 3, 1, 1);

        verticalSpacer = new QSpacerItem(20, 25, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer, 2, 0, 1, 7);

        label_text_error2_2 = new QLabel(ErrorBox_position);
        label_text_error2_2->setObjectName(QStringLiteral("label_text_error2_2"));
        QFont font5;
        font5.setPointSize(8);
        font5.setBold(false);
        font5.setItalic(false);
        font5.setWeight(50);
        label_text_error2_2->setFont(font5);
        label_text_error2_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_text_error2_2, 0, 2, 1, 1);

        label_text_error2 = new QLabel(ErrorBox_position);
        label_text_error2->setObjectName(QStringLiteral("label_text_error2"));
        label_text_error2->setFont(font1);
        label_text_error2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_text_error2, 3, 2, 1, 1);

        label_text_error2_3 = new QLabel(ErrorBox_position);
        label_text_error2_3->setObjectName(QStringLiteral("label_text_error2_3"));
        label_text_error2_3->setFont(font5);
        label_text_error2_3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_text_error2_3, 0, 4, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 0, 1, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 3, 1, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_7, 0, 5, 1, 1);


        verticalLayout->addWidget(ErrorBox_position);

        ErrorBox_angle = new QGroupBox(Info);
        ErrorBox_angle->setObjectName(QStringLiteral("ErrorBox_angle"));
        ErrorBox_angle->setFont(font);
        gridLayout_4 = new QGridLayout(ErrorBox_angle);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        label_ci_err_ang = new QLabel(ErrorBox_angle);
        label_ci_err_ang->setObjectName(QStringLiteral("label_ci_err_ang"));
        label_ci_err_ang->setFont(font2);
        label_ci_err_ang->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_ci_err_ang, 0, 3, 1, 1);

        progressBar_CI_err_ang = new QProgressBar(ErrorBox_angle);
        progressBar_CI_err_ang->setObjectName(QStringLiteral("progressBar_CI_err_ang"));
        sizePolicy2.setHeightForWidth(progressBar_CI_err_ang->sizePolicy().hasHeightForWidth());
        progressBar_CI_err_ang->setSizePolicy(sizePolicy2);
        progressBar_CI_err_ang->setFont(font3);
        progressBar_CI_err_ang->setValue(0);
        progressBar_CI_err_ang->setTextVisible(false);

        gridLayout_4->addWidget(progressBar_CI_err_ang, 1, 0, 1, 7);

        label_text_error2_4 = new QLabel(ErrorBox_angle);
        label_text_error2_4->setObjectName(QStringLiteral("label_text_error2_4"));
        label_text_error2_4->setFont(font5);
        label_text_error2_4->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_4->addWidget(label_text_error2_4, 0, 4, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_6, 0, 1, 1, 1);

        label_ci_status_ang = new QLabel(ErrorBox_angle);
        label_ci_status_ang->setObjectName(QStringLiteral("label_ci_status_ang"));
        label_ci_status_ang->setFont(font1);
        label_ci_status_ang->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(label_ci_status_ang, 0, 6, 1, 1);

        label_text_error2_5 = new QLabel(ErrorBox_angle);
        label_text_error2_5->setObjectName(QStringLiteral("label_text_error2_5"));
        label_text_error2_5->setFont(font5);
        label_text_error2_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(label_text_error2_5, 0, 2, 1, 1);

        label_mag_status_3 = new QLabel(ErrorBox_angle);
        label_mag_status_3->setObjectName(QStringLiteral("label_mag_status_3"));
        label_mag_status_3->setFont(font1);
        label_mag_status_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(label_mag_status_3, 2, 6, 1, 1);

        label_text_CITool_ang = new QLabel(ErrorBox_angle);
        label_text_CITool_ang->setObjectName(QStringLiteral("label_text_CITool_ang"));
        label_text_CITool_ang->setFont(font3);

        gridLayout_4->addWidget(label_text_CITool_ang, 0, 0, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_8, 0, 5, 1, 1);


        verticalLayout->addWidget(ErrorBox_angle);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(3);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setSizeConstraint(QLayout::SetMinimumSize);
        button_recordData = new QPushButton(Info);
        button_recordData->setObjectName(QStringLiteral("button_recordData"));
        sizePolicy1.setHeightForWidth(button_recordData->sizePolicy().hasHeightForWidth());
        button_recordData->setSizePolicy(sizePolicy1);

        horizontalLayout_4->addWidget(button_recordData);

        label_recordData = new QLabel(Info);
        label_recordData->setObjectName(QStringLiteral("label_recordData"));

        horizontalLayout_4->addWidget(label_recordData);

        horizontalSpacer_9 = new QSpacerItem(300, 1, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_9);


        verticalLayout->addLayout(horizontalLayout_4);

        Logos = new QHBoxLayout();
        Logos->setSpacing(0);
        Logos->setObjectName(QStringLiteral("Logos"));
        Logos->setContentsMargins(0, -1, -1, -1);
        logo_VUeng = new QLabel(Info);
        logo_VUeng->setObjectName(QStringLiteral("logo_VUeng"));
        logo_VUeng->setEnabled(true);
        logo_VUeng->setPixmap(QPixmap(QString::fromUtf8(":/images/Resources/engineering_logo1_small.tif")));
        logo_VUeng->setAlignment(Qt::AlignBottom|Qt::AlignRight|Qt::AlignTrailing);

        Logos->addWidget(logo_VUeng);

        logo_medlab = new QLabel(Info);
        logo_medlab->setObjectName(QStringLiteral("logo_medlab"));
        logo_medlab->setPixmap(QPixmap(QString::fromUtf8(":/images/Resources/medlab_logo.jpg")));
        logo_medlab->setScaledContents(false);
        logo_medlab->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);
        logo_medlab->setIndent(-1);

        Logos->addWidget(logo_medlab);


        verticalLayout->addLayout(Logos);


        retranslateUi(Info);

        QMetaObject::connectSlotsByName(Info);
    } // setupUi

    void retranslateUi(QWidget *Info)
    {
        Info->setWindowTitle(QApplication::translate("Info", "Form", 0));
        probeBox->setTitle(QApplication::translate("Info", "Probe", 0));
        label->setText(QApplication::translate("Info", "<b>x</b>", 0));
        label_probe_x->setText(QApplication::translate("Info", "-0000.00", 0));
        label_2->setText(QApplication::translate("Info", "<b>y</b>", 0));
        label_probe_y->setText(QApplication::translate("Info", "-0000.00", 0));
        label_3->setText(QApplication::translate("Info", "<b>z</b>", 0));
        label_probe_z->setText(QApplication::translate("Info", "-0000.00", 0));
        button_centerProbe->setText(QApplication::translate("Info", "Center View", 0));
        CIToolBox->setTitle(QApplication::translate("Info", "CI Tool", 0));
        label_4->setText(QApplication::translate("Info", "<b>x</b>", 0));
        label_ci_x->setText(QApplication::translate("Info", "-0000.00", 0));
        label_5->setText(QApplication::translate("Info", "<b>y</b>", 0));
        label_ci_y->setText(QApplication::translate("Info", "-0000.00", 0));
        label_6->setText(QApplication::translate("Info", "<b>z</b>", 0));
        label_ci_z->setText(QApplication::translate("Info", "-0000.00", 0));
        button_centerCItool->setText(QApplication::translate("Info", "Center View", 0));
        MagnetBox->setTitle(QApplication::translate("Info", "Magnet", 0));
        label_7->setText(QApplication::translate("Info", "<b>x</b>", 0));
        label_mag_x->setText(QApplication::translate("Info", "-0000.00", 0));
        label_8->setText(QApplication::translate("Info", "<b>y</b>", 0));
        label_mag_y->setText(QApplication::translate("Info", "-0000.00", 0));
        label_9->setText(QApplication::translate("Info", "<b>z</b>", 0));
        label_mag_z->setText(QApplication::translate("Info", "-0000.00", 0));
        checkBox_LiveTarget->setText(QApplication::translate("Info", "Live Target Tracking", 0));
        label_FRE->setText(QApplication::translate("Info", "FRE = ", 0));
        ErrorBox_position->setTitle(QApplication::translate("Info", "Position Error", 0));
        label_ci_err_pos->setText(QApplication::translate("Info", "000.00", 0));
        label_mag_status->setText(QString());
        label_text_CITool_pos->setText(QApplication::translate("Info", "CI Tool", 0));
        progressBar_CI_err_pos->setFormat(QString());
        progressBar_mag_err->setFormat(QString());
        label_ci_status->setText(QString());
        label_text_Magnet->setText(QApplication::translate("Info", "Magnet", 0));
        label_mag_err->setText(QApplication::translate("Info", "000.00", 0));
        label_text_error2_2->setText(QApplication::translate("Info", "Error =", 0));
        label_text_error2->setText(QApplication::translate("Info", "Error =", 0));
        label_text_error2_3->setText(QApplication::translate("Info", "mm", 0));
        ErrorBox_angle->setTitle(QApplication::translate("Info", "Angular Error", 0));
        label_ci_err_ang->setText(QApplication::translate("Info", "000.00", 0));
        progressBar_CI_err_ang->setFormat(QString());
        label_text_error2_4->setText(QApplication::translate("Info", "deg", 0));
        label_ci_status_ang->setText(QString());
        label_text_error2_5->setText(QApplication::translate("Info", "Error =", 0));
        label_mag_status_3->setText(QString());
        label_text_CITool_ang->setText(QApplication::translate("Info", "CI Tool", 0));
        button_recordData->setText(QApplication::translate("Info", "Record Data", 0));
        label_recordData->setText(QString());
        logo_VUeng->setText(QString());
        logo_medlab->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Info: public Ui_Info {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INFO_H
