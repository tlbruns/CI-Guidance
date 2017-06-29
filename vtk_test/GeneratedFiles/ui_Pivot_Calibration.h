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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_PivotCalibration
{
public:
    QVBoxLayout *verticalLayout_2;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *PivotCalibration)
    {
        if (PivotCalibration->objectName().isEmpty())
            PivotCalibration->setObjectName(QStringLiteral("PivotCalibration"));
        PivotCalibration->resize(482, 434);
        verticalLayout_2 = new QVBoxLayout(PivotCalibration);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        buttonBox = new QDialogButtonBox(PivotCalibration);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_2->addWidget(buttonBox);


        retranslateUi(PivotCalibration);
        QObject::connect(buttonBox, SIGNAL(accepted()), PivotCalibration, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), PivotCalibration, SLOT(reject()));

        QMetaObject::connectSlotsByName(PivotCalibration);
    } // setupUi

    void retranslateUi(QDialog *PivotCalibration)
    {
        PivotCalibration->setWindowTitle(QApplication::translate("PivotCalibration", "Dialog", 0));
    } // retranslateUi

};

namespace Ui {
    class PivotCalibration: public Ui_PivotCalibration {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PIVOT_CALIBRATION_H
