/********************************************************************************
** Form generated from reading UI file 'TrackerSetup.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRACKERSETUP_H
#define UI_TRACKERSETUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TrackerSetup
{
public:
    QComboBox *comboBox_COM;
    QLabel *label;
    QPushButton *selectButton;
    QPushButton *cancelButton;

    void setupUi(QWidget *TrackerSetup)
    {
        if (TrackerSetup->objectName().isEmpty())
            TrackerSetup->setObjectName(QStringLiteral("TrackerSetup"));
        TrackerSetup->resize(400, 164);
        comboBox_COM = new QComboBox(TrackerSetup);
        comboBox_COM->setObjectName(QStringLiteral("comboBox_COM"));
        comboBox_COM->setGeometry(QRect(170, 50, 41, 22));
        label = new QLabel(TrackerSetup);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(120, 10, 161, 31));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);
        selectButton = new QPushButton(TrackerSetup);
        selectButton->setObjectName(QStringLiteral("selectButton"));
        selectButton->setGeometry(QRect(90, 100, 93, 28));
        cancelButton = new QPushButton(TrackerSetup);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setGeometry(QRect(200, 100, 93, 28));

        retranslateUi(TrackerSetup);

        QMetaObject::connectSlotsByName(TrackerSetup);
    } // setupUi

    void retranslateUi(QWidget *TrackerSetup)
    {
        TrackerSetup->setWindowTitle(QApplication::translate("TrackerSetup", "TrackerSetup", 0));
        label->setText(QApplication::translate("TrackerSetup", "Select COM port", 0));
        selectButton->setText(QApplication::translate("TrackerSetup", "Select", 0));
        cancelButton->setText(QApplication::translate("TrackerSetup", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class TrackerSetup: public Ui_TrackerSetup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRACKERSETUP_H
