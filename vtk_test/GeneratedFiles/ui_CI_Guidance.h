/********************************************************************************
** Form generated from reading UI file 'CI_Guidance.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CI_GUIDANCE_H
#define UI_CI_GUIDANCE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CI_Guidance_Ui
{
public:
    QAction *actionClose;
    QAction *actionLoad_Patient_File;
    QAction *actionTracker_Setup;
    QAction *actionRegister_Patient;
    QAction *actionDemo;
    QAction *actionCenter_Target;
    QAction *actionTracker_Init;
    QAction *actionTracker_Stop;
    QAction *actionTracker_Setup_2;
    QAction *actionLoad_Plan;
    QAction *actionPivot_Calibration;
    QWidget *centralWidget;
    QGridLayout *gridLayout_3;
    QGridLayout *gridlayout;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuTracker;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *CI_Guidance_Ui)
    {
        if (CI_Guidance_Ui->objectName().isEmpty())
            CI_Guidance_Ui->setObjectName(QStringLiteral("CI_Guidance_Ui"));
        CI_Guidance_Ui->resize(1016, 866);
        actionClose = new QAction(CI_Guidance_Ui);
        actionClose->setObjectName(QStringLiteral("actionClose"));
        actionLoad_Patient_File = new QAction(CI_Guidance_Ui);
        actionLoad_Patient_File->setObjectName(QStringLiteral("actionLoad_Patient_File"));
        actionTracker_Setup = new QAction(CI_Guidance_Ui);
        actionTracker_Setup->setObjectName(QStringLiteral("actionTracker_Setup"));
        actionRegister_Patient = new QAction(CI_Guidance_Ui);
        actionRegister_Patient->setObjectName(QStringLiteral("actionRegister_Patient"));
        actionDemo = new QAction(CI_Guidance_Ui);
        actionDemo->setObjectName(QStringLiteral("actionDemo"));
        actionCenter_Target = new QAction(CI_Guidance_Ui);
        actionCenter_Target->setObjectName(QStringLiteral("actionCenter_Target"));
        actionTracker_Init = new QAction(CI_Guidance_Ui);
        actionTracker_Init->setObjectName(QStringLiteral("actionTracker_Init"));
        actionTracker_Stop = new QAction(CI_Guidance_Ui);
        actionTracker_Stop->setObjectName(QStringLiteral("actionTracker_Stop"));
        actionTracker_Setup_2 = new QAction(CI_Guidance_Ui);
        actionTracker_Setup_2->setObjectName(QStringLiteral("actionTracker_Setup_2"));
        actionLoad_Plan = new QAction(CI_Guidance_Ui);
        actionLoad_Plan->setObjectName(QStringLiteral("actionLoad_Plan"));
        actionPivot_Calibration = new QAction(CI_Guidance_Ui);
        actionPivot_Calibration->setObjectName(QStringLiteral("actionPivot_Calibration"));
        actionPivot_Calibration->setCheckable(false);
        actionPivot_Calibration->setChecked(false);
        centralWidget = new QWidget(CI_Guidance_Ui);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_3 = new QGridLayout(centralWidget);
        gridLayout_3->setSpacing(2);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(8, 8, 6, 0);
        gridlayout = new QGridLayout();
        gridlayout->setSpacing(6);
        gridlayout->setObjectName(QStringLiteral("gridlayout"));

        gridLayout_3->addLayout(gridlayout, 0, 0, 1, 1);

        CI_Guidance_Ui->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(CI_Guidance_Ui);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1016, 18));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuTracker = new QMenu(menuBar);
        menuTracker->setObjectName(QStringLiteral("menuTracker"));
        CI_Guidance_Ui->setMenuBar(menuBar);
        mainToolBar = new QToolBar(CI_Guidance_Ui);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        CI_Guidance_Ui->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(CI_Guidance_Ui);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        CI_Guidance_Ui->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuTracker->menuAction());
        menuFile->addAction(actionRegister_Patient);
        menuFile->addAction(actionDemo);
        menuFile->addAction(actionClose);
        menuTracker->addAction(actionTracker_Init);
        menuTracker->addAction(actionTracker_Stop);
        menuTracker->addSeparator();
        menuTracker->addAction(actionTracker_Setup_2);
        mainToolBar->addAction(actionLoad_Plan);
        mainToolBar->addAction(actionCenter_Target);
        mainToolBar->addAction(actionPivot_Calibration);

        retranslateUi(CI_Guidance_Ui);
        QObject::connect(actionClose, SIGNAL(triggered()), CI_Guidance_Ui, SLOT(close()));

        QMetaObject::connectSlotsByName(CI_Guidance_Ui);
    } // setupUi

    void retranslateUi(QMainWindow *CI_Guidance_Ui)
    {
        CI_Guidance_Ui->setWindowTitle(QApplication::translate("CI_Guidance_Ui", "CI Guidance", nullptr));
        actionClose->setText(QApplication::translate("CI_Guidance_Ui", "Close", nullptr));
        actionLoad_Patient_File->setText(QApplication::translate("CI_Guidance_Ui", "Load Patient File", nullptr));
        actionTracker_Setup->setText(QApplication::translate("CI_Guidance_Ui", "Tracker Setup", nullptr));
        actionRegister_Patient->setText(QApplication::translate("CI_Guidance_Ui", "Register Patient", nullptr));
        actionDemo->setText(QApplication::translate("CI_Guidance_Ui", "Demo", nullptr));
        actionCenter_Target->setText(QApplication::translate("CI_Guidance_Ui", "Center Target", nullptr));
        actionTracker_Init->setText(QApplication::translate("CI_Guidance_Ui", "Init", nullptr));
        actionTracker_Stop->setText(QApplication::translate("CI_Guidance_Ui", "Stop", nullptr));
        actionTracker_Setup_2->setText(QApplication::translate("CI_Guidance_Ui", "Setup", nullptr));
        actionLoad_Plan->setText(QApplication::translate("CI_Guidance_Ui", "Load Plan", nullptr));
        actionPivot_Calibration->setText(QApplication::translate("CI_Guidance_Ui", "Pivot Calibration", nullptr));
        menuFile->setTitle(QApplication::translate("CI_Guidance_Ui", "File", nullptr));
        menuTracker->setTitle(QApplication::translate("CI_Guidance_Ui", "Tracker", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CI_Guidance_Ui: public Ui_CI_Guidance_Ui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CI_GUIDANCE_H
