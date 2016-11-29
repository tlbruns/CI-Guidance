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
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
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
    QGroupBox *ErrorBox;
    QGridLayout *gridLayout;
    QLabel *label_Magnet_err;
    QLabel *label_mag_err;
    QLabel *label_mag_status;
    QSpacerItem *verticalSpacer;
    QProgressBar *progressBar_CI_err;
    QLabel *label_ci_status;
    QLabel *label_CI_Tool_err;
    QLabel *label_ci_err;
    QProgressBar *progressBar_mag_err;
    QLabel *label_10;
    QLabel *label_11;
    QHBoxLayout *Logos;
    QLabel *logo_VUeng;
    QLabel *logo_medlab;

    void setupUi(QWidget *Info)
    {
        if (Info->objectName().isEmpty())
            Info->setObjectName(QStringLiteral("Info"));
        Info->resize(532, 1132);
        verticalLayout = new QVBoxLayout(Info);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(5, 15, 10, 2);
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

        ErrorBox = new QGroupBox(Info);
        ErrorBox->setObjectName(QStringLiteral("ErrorBox"));
        ErrorBox->setFont(font);
        gridLayout = new QGridLayout(ErrorBox);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_Magnet_err = new QLabel(ErrorBox);
        label_Magnet_err->setObjectName(QStringLiteral("label_Magnet_err"));
        label_Magnet_err->setFont(font3);

        gridLayout->addWidget(label_Magnet_err, 3, 0, 1, 1);

        label_mag_err = new QLabel(ErrorBox);
        label_mag_err->setObjectName(QStringLiteral("label_mag_err"));
        label_mag_err->setFont(font2);
        label_mag_err->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_mag_err, 3, 2, 1, 1);

        label_mag_status = new QLabel(ErrorBox);
        label_mag_status->setObjectName(QStringLiteral("label_mag_status"));
        label_mag_status->setFont(font1);
        label_mag_status->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_mag_status, 3, 3, 1, 1);

        verticalSpacer = new QSpacerItem(20, 25, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer, 2, 0, 1, 4);

        progressBar_CI_err = new QProgressBar(ErrorBox);
        progressBar_CI_err->setObjectName(QStringLiteral("progressBar_CI_err"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(progressBar_CI_err->sizePolicy().hasHeightForWidth());
        progressBar_CI_err->setSizePolicy(sizePolicy1);
        progressBar_CI_err->setFont(font3);
        progressBar_CI_err->setValue(0);
        progressBar_CI_err->setTextVisible(false);

        gridLayout->addWidget(progressBar_CI_err, 1, 0, 1, 4);

        label_ci_status = new QLabel(ErrorBox);
        label_ci_status->setObjectName(QStringLiteral("label_ci_status"));
        label_ci_status->setFont(font1);
        label_ci_status->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_ci_status, 0, 3, 1, 1);

        label_CI_Tool_err = new QLabel(ErrorBox);
        label_CI_Tool_err->setObjectName(QStringLiteral("label_CI_Tool_err"));
        label_CI_Tool_err->setFont(font3);

        gridLayout->addWidget(label_CI_Tool_err, 0, 0, 1, 1);

        label_ci_err = new QLabel(ErrorBox);
        label_ci_err->setObjectName(QStringLiteral("label_ci_err"));
        label_ci_err->setFont(font2);
        label_ci_err->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_ci_err, 0, 2, 1, 1);

        progressBar_mag_err = new QProgressBar(ErrorBox);
        progressBar_mag_err->setObjectName(QStringLiteral("progressBar_mag_err"));
        progressBar_mag_err->setFont(font3);
        progressBar_mag_err->setValue(0);
        progressBar_mag_err->setTextVisible(false);
        progressBar_mag_err->setInvertedAppearance(false);
        progressBar_mag_err->setTextDirection(QProgressBar::BottomToTop);

        gridLayout->addWidget(progressBar_mag_err, 4, 0, 1, 4);

        label_10 = new QLabel(ErrorBox);
        label_10->setObjectName(QStringLiteral("label_10"));
        QFont font4;
        font4.setPointSize(8);
        font4.setBold(false);
        font4.setItalic(false);
        font4.setWeight(50);
        label_10->setFont(font4);
        label_10->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_10, 0, 1, 1, 1);

        label_11 = new QLabel(ErrorBox);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setFont(font1);
        label_11->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_11, 3, 1, 1, 1);


        verticalLayout->addWidget(ErrorBox);

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
        CIToolBox->setTitle(QApplication::translate("Info", "CI Tool", 0));
        label_4->setText(QApplication::translate("Info", "<b>x</b>", 0));
        label_ci_x->setText(QApplication::translate("Info", "-0000.00", 0));
        label_5->setText(QApplication::translate("Info", "<b>y</b>", 0));
        label_ci_y->setText(QApplication::translate("Info", "-0000.00", 0));
        label_6->setText(QApplication::translate("Info", "<b>z</b>", 0));
        label_ci_z->setText(QApplication::translate("Info", "-0000.00", 0));
        MagnetBox->setTitle(QApplication::translate("Info", "Magnet", 0));
        label_7->setText(QApplication::translate("Info", "<b>x</b>", 0));
        label_mag_x->setText(QApplication::translate("Info", "-0000.00", 0));
        label_8->setText(QApplication::translate("Info", "<b>y</b>", 0));
        label_mag_y->setText(QApplication::translate("Info", "-0000.00", 0));
        label_9->setText(QApplication::translate("Info", "<b>z</b>", 0));
        label_mag_z->setText(QApplication::translate("Info", "-0000.00", 0));
        ErrorBox->setTitle(QApplication::translate("Info", "Error", 0));
        label_Magnet_err->setText(QApplication::translate("Info", "Magnet", 0));
        label_mag_err->setText(QApplication::translate("Info", "000.00", 0));
        label_mag_status->setText(QString());
        progressBar_CI_err->setFormat(QString());
        label_ci_status->setText(QString());
        label_CI_Tool_err->setText(QApplication::translate("Info", "CI Tool", 0));
        label_ci_err->setText(QApplication::translate("Info", "000.00", 0));
        progressBar_mag_err->setFormat(QString());
        label_10->setText(QApplication::translate("Info", "Error =", 0));
        label_11->setText(QApplication::translate("Info", "Error =", 0));
        logo_VUeng->setText(QString());
        logo_medlab->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Info: public Ui_Info {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INFO_H
