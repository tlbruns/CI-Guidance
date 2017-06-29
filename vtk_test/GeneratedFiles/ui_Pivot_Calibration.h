/********************************************************************************
** Form generated from reading UI file 'Pivot_Calibration.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PIVOT_CALIBRATION_H
#define UI_PIVOT_CALIBRATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_PivotCalibration
{
public:
    QVBoxLayout *verticalLayout_4;
    QGroupBox *groupBox_header;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_instructionsHeader;
    QLabel *label_instructions;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton_takeSample;
    QLabel *label_numSamples;
    QLabel *label_samples;
    QPushButton *pushButton_computeOffset;
    QPushButton *pushButton_reset;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_offsetText;
    QFormLayout *formLayout_2;
    QLabel *label_x_2;
    QLabel *label_offsetX;
    QLabel *label_y_2;
    QLabel *label_offsetY;
    QLabel *label_z_2;
    QLabel *label_offsetZ;
    QVBoxLayout *verticalLayout;
    QLabel *label_pivotText;
    QFormLayout *formLayout;
    QLabel *label_x;
    QLabel *label_pivotX;
    QLabel *label_y;
    QLabel *label_pivotY;
    QLabel *label_z;
    QLabel *label_pivotZ;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *PivotCalibration)
    {
        if (PivotCalibration->objectName().isEmpty())
            PivotCalibration->setObjectName(QStringLiteral("PivotCalibration"));
        PivotCalibration->resize(507, 577);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(PivotCalibration->sizePolicy().hasHeightForWidth());
        PivotCalibration->setSizePolicy(sizePolicy);
        verticalLayout_4 = new QVBoxLayout(PivotCalibration);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        groupBox_header = new QGroupBox(PivotCalibration);
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
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_instructionsHeader = new QLabel(groupBox_header);
        label_instructionsHeader->setObjectName(QStringLiteral("label_instructionsHeader"));
        QFont font1;
        font1.setPointSize(11);
        font1.setBold(false);
        font1.setUnderline(true);
        font1.setWeight(50);
        label_instructionsHeader->setFont(font1);

        verticalLayout_2->addWidget(label_instructionsHeader);

        label_instructions = new QLabel(groupBox_header);
        label_instructions->setObjectName(QStringLiteral("label_instructions"));
        QFont font2;
        font2.setPointSize(9);
        font2.setBold(false);
        font2.setWeight(50);
        label_instructions->setFont(font2);
        label_instructions->setAlignment(Qt::AlignJustify|Qt::AlignTop);
        label_instructions->setWordWrap(true);

        verticalLayout_2->addWidget(label_instructions);


        gridLayout->addLayout(verticalLayout_2, 0, 0, 1, 1);


        verticalLayout_4->addWidget(groupBox_header);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        pushButton_takeSample = new QPushButton(PivotCalibration);
        pushButton_takeSample->setObjectName(QStringLiteral("pushButton_takeSample"));

        gridLayout_2->addWidget(pushButton_takeSample, 0, 0, 1, 1);

        label_numSamples = new QLabel(PivotCalibration);
        label_numSamples->setObjectName(QStringLiteral("label_numSamples"));
        label_numSamples->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_numSamples, 0, 2, 1, 1);

        label_samples = new QLabel(PivotCalibration);
        label_samples->setObjectName(QStringLiteral("label_samples"));
        label_samples->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_samples, 0, 1, 1, 1);

        pushButton_computeOffset = new QPushButton(PivotCalibration);
        pushButton_computeOffset->setObjectName(QStringLiteral("pushButton_computeOffset"));

        gridLayout_2->addWidget(pushButton_computeOffset, 2, 0, 1, 1);

        pushButton_reset = new QPushButton(PivotCalibration);
        pushButton_reset->setObjectName(QStringLiteral("pushButton_reset"));

        gridLayout_2->addWidget(pushButton_reset, 1, 0, 1, 1);


        verticalLayout_4->addLayout(gridLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_offsetText = new QLabel(PivotCalibration);
        label_offsetText->setObjectName(QStringLiteral("label_offsetText"));
        QFont font3;
        font3.setPointSize(10);
        label_offsetText->setFont(font3);

        verticalLayout_3->addWidget(label_offsetText);

        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        formLayout_2->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        label_x_2 = new QLabel(PivotCalibration);
        label_x_2->setObjectName(QStringLiteral("label_x_2"));
        QFont font4;
        font4.setPointSize(9);
        font4.setBold(true);
        font4.setWeight(75);
        label_x_2->setFont(font4);

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_x_2);

        label_offsetX = new QLabel(PivotCalibration);
        label_offsetX->setObjectName(QStringLiteral("label_offsetX"));
        QFont font5;
        font5.setPointSize(9);
        label_offsetX->setFont(font5);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, label_offsetX);

        label_y_2 = new QLabel(PivotCalibration);
        label_y_2->setObjectName(QStringLiteral("label_y_2"));
        label_y_2->setFont(font4);

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_y_2);

        label_offsetY = new QLabel(PivotCalibration);
        label_offsetY->setObjectName(QStringLiteral("label_offsetY"));
        label_offsetY->setFont(font5);

        formLayout_2->setWidget(1, QFormLayout::FieldRole, label_offsetY);

        label_z_2 = new QLabel(PivotCalibration);
        label_z_2->setObjectName(QStringLiteral("label_z_2"));
        label_z_2->setFont(font4);

        formLayout_2->setWidget(2, QFormLayout::LabelRole, label_z_2);

        label_offsetZ = new QLabel(PivotCalibration);
        label_offsetZ->setObjectName(QStringLiteral("label_offsetZ"));
        label_offsetZ->setFont(font5);

        formLayout_2->setWidget(2, QFormLayout::FieldRole, label_offsetZ);


        verticalLayout_3->addLayout(formLayout_2);


        horizontalLayout->addLayout(verticalLayout_3);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_pivotText = new QLabel(PivotCalibration);
        label_pivotText->setObjectName(QStringLiteral("label_pivotText"));
        label_pivotText->setFont(font3);

        verticalLayout->addWidget(label_pivotText);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        label_x = new QLabel(PivotCalibration);
        label_x->setObjectName(QStringLiteral("label_x"));
        label_x->setFont(font4);

        formLayout->setWidget(0, QFormLayout::LabelRole, label_x);

        label_pivotX = new QLabel(PivotCalibration);
        label_pivotX->setObjectName(QStringLiteral("label_pivotX"));
        label_pivotX->setFont(font5);

        formLayout->setWidget(0, QFormLayout::FieldRole, label_pivotX);

        label_y = new QLabel(PivotCalibration);
        label_y->setObjectName(QStringLiteral("label_y"));
        label_y->setFont(font4);

        formLayout->setWidget(1, QFormLayout::LabelRole, label_y);

        label_pivotY = new QLabel(PivotCalibration);
        label_pivotY->setObjectName(QStringLiteral("label_pivotY"));
        label_pivotY->setFont(font5);

        formLayout->setWidget(1, QFormLayout::FieldRole, label_pivotY);

        label_z = new QLabel(PivotCalibration);
        label_z->setObjectName(QStringLiteral("label_z"));
        label_z->setFont(font4);

        formLayout->setWidget(2, QFormLayout::LabelRole, label_z);

        label_pivotZ = new QLabel(PivotCalibration);
        label_pivotZ->setObjectName(QStringLiteral("label_pivotZ"));
        label_pivotZ->setFont(font5);

        formLayout->setWidget(2, QFormLayout::FieldRole, label_pivotZ);


        verticalLayout->addLayout(formLayout);


        horizontalLayout->addLayout(verticalLayout);


        verticalLayout_4->addLayout(horizontalLayout);

        buttonBox = new QDialogButtonBox(PivotCalibration);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_4->addWidget(buttonBox);

        groupBox_header->raise();
        buttonBox->raise();

        retranslateUi(PivotCalibration);
        QObject::connect(buttonBox, SIGNAL(accepted()), PivotCalibration, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), PivotCalibration, SLOT(reject()));

        QMetaObject::connectSlotsByName(PivotCalibration);
    } // setupUi

    void retranslateUi(QDialog *PivotCalibration)
    {
        PivotCalibration->setWindowTitle(QApplication::translate("PivotCalibration", "Dialog", 0));
        groupBox_header->setTitle(QApplication::translate("PivotCalibration", "Pivot Calibration", 0));
        label_instructionsHeader->setText(QApplication::translate("PivotCalibration", "Instructions:", 0));
        label_instructions->setText(QApplication::translate("PivotCalibration", "Place the tip of the tool on the pivot point and press \"Take Sample\". It is recommended that you take at least 10 samples from different orientations.", 0));
        pushButton_takeSample->setText(QApplication::translate("PivotCalibration", "Take Sample", 0));
        label_numSamples->setText(QApplication::translate("PivotCalibration", "0", 0));
        label_samples->setText(QApplication::translate("PivotCalibration", "Total Samples = ", 0));
        pushButton_computeOffset->setText(QApplication::translate("PivotCalibration", "Compute Offset", 0));
        pushButton_reset->setText(QApplication::translate("PivotCalibration", "Reset", 0));
        label_offsetText->setText(QApplication::translate("PivotCalibration", "Calculated Tip Offset:", 0));
        label_x_2->setText(QApplication::translate("PivotCalibration", "X", 0));
        label_offsetX->setText(QApplication::translate("PivotCalibration", "-000.00", 0));
        label_y_2->setText(QApplication::translate("PivotCalibration", "Y", 0));
        label_offsetY->setText(QApplication::translate("PivotCalibration", "-000.00", 0));
        label_z_2->setText(QApplication::translate("PivotCalibration", "Z", 0));
        label_offsetZ->setText(QApplication::translate("PivotCalibration", "-000.00", 0));
        label_pivotText->setText(QApplication::translate("PivotCalibration", "Estimated Pivot Location:", 0));
        label_x->setText(QApplication::translate("PivotCalibration", "X", 0));
        label_pivotX->setText(QApplication::translate("PivotCalibration", "-0000.00", 0));
        label_y->setText(QApplication::translate("PivotCalibration", "Y", 0));
        label_pivotY->setText(QApplication::translate("PivotCalibration", "-0000.00", 0));
        label_z->setText(QApplication::translate("PivotCalibration", "Z", 0));
        label_pivotZ->setText(QApplication::translate("PivotCalibration", "-0000.00", 0));
    } // retranslateUi

};

namespace Ui {
    class PivotCalibration: public Ui_PivotCalibration {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PIVOT_CALIBRATION_H
