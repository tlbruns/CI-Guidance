/********************************************************************************
** Form generated from reading UI file 'Demo.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEMO_H
#define UI_DEMO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Demo
{
public:
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label_5;
    QLabel *label_6;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *button_set_target;
    QPushButton *button_datalog;
    QSpacerItem *horizontalSpacer;
    QPushButton *button_end;

    void setupUi(QDialog *Demo)
    {
        if (Demo->objectName().isEmpty())
            Demo->setObjectName(QStringLiteral("Demo"));
        Demo->setWindowModality(Qt::ApplicationModal);
        Demo->resize(463, 282);
        verticalLayout_3 = new QVBoxLayout(Demo);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        groupBox_2 = new QGroupBox(Demo);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        font.setUnderline(false);
        font.setWeight(75);
        groupBox_2->setFont(font);
        groupBox_2->setAlignment(Qt::AlignCenter);
        gridLayout = new QGridLayout(groupBox_2);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        QFont font1;
        font1.setPointSize(11);
        font1.setBold(false);
        font1.setUnderline(true);
        font1.setWeight(50);
        label_5->setFont(font1);

        verticalLayout->addWidget(label_5);

        label_6 = new QLabel(groupBox_2);
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


        verticalLayout_3->addWidget(groupBox_2);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        button_set_target = new QPushButton(Demo);
        button_set_target->setObjectName(QStringLiteral("button_set_target"));

        horizontalLayout->addWidget(button_set_target);

        button_datalog = new QPushButton(Demo);
        button_datalog->setObjectName(QStringLiteral("button_datalog"));

        horizontalLayout->addWidget(button_datalog);

        horizontalSpacer = new QSpacerItem(20, 10, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        button_end = new QPushButton(Demo);
        button_end->setObjectName(QStringLiteral("button_end"));
        button_end->setCheckable(false);
        button_end->setFlat(false);

        horizontalLayout->addWidget(button_end);


        verticalLayout_2->addLayout(horizontalLayout);


        verticalLayout_3->addLayout(verticalLayout_2);


        retranslateUi(Demo);

        button_end->setDefault(false);


        QMetaObject::connectSlotsByName(Demo);
    } // setupUi

    void retranslateUi(QDialog *Demo)
    {
        Demo->setWindowTitle(QApplication::translate("Demo", "Dialog", nullptr));
        groupBox_2->setTitle(QApplication::translate("Demo", "Demo", nullptr));
        label_5->setText(QApplication::translate("Demo", "Instructions:", nullptr));
        label_6->setText(QApplication::translate("Demo", "Position tool in desired target position and click 'Set Target'. Then move tool away and click 'Record Data'. Use the gui to align the tool. When satisfied, click 'Done'.", nullptr));
        button_set_target->setText(QApplication::translate("Demo", "Set Target", nullptr));
        button_datalog->setText(QApplication::translate("Demo", "Record Data", nullptr));
        button_end->setText(QApplication::translate("Demo", "Done", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Demo: public Ui_Demo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEMO_H
