/********************************************************************************
** Form generated from reading UI file 'vtk_test.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VTK_TEST_H
#define UI_VTK_TEST_H

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

class Ui_vtk_testClass
{
public:
    QAction *actionClose;
    QAction *actionLoad_Patient_File;
    QAction *actionTracker_Setup;
    QAction *actionRegister_Patient;
    QWidget *centralWidget;
    QGridLayout *gridLayout_3;
    QGridLayout *gridlayout;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *vtk_testClass)
    {
        if (vtk_testClass->objectName().isEmpty())
            vtk_testClass->setObjectName(QStringLiteral("vtk_testClass"));
        vtk_testClass->resize(1016, 866);
        actionClose = new QAction(vtk_testClass);
        actionClose->setObjectName(QStringLiteral("actionClose"));
        actionLoad_Patient_File = new QAction(vtk_testClass);
        actionLoad_Patient_File->setObjectName(QStringLiteral("actionLoad_Patient_File"));
        actionTracker_Setup = new QAction(vtk_testClass);
        actionTracker_Setup->setObjectName(QStringLiteral("actionTracker_Setup"));
        actionRegister_Patient = new QAction(vtk_testClass);
        actionRegister_Patient->setObjectName(QStringLiteral("actionRegister_Patient"));
        centralWidget = new QWidget(vtk_testClass);
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

        vtk_testClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(vtk_testClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1016, 38));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        vtk_testClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(vtk_testClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        vtk_testClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(vtk_testClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        vtk_testClass->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionTracker_Setup);
        menuFile->addAction(actionRegister_Patient);
        menuFile->addAction(actionClose);

        retranslateUi(vtk_testClass);
        QObject::connect(actionClose, SIGNAL(triggered()), vtk_testClass, SLOT(close()));

        QMetaObject::connectSlotsByName(vtk_testClass);
    } // setupUi

    void retranslateUi(QMainWindow *vtk_testClass)
    {
        vtk_testClass->setWindowTitle(QApplication::translate("vtk_testClass", "vtk_test", 0));
        actionClose->setText(QApplication::translate("vtk_testClass", "Close", 0));
        actionLoad_Patient_File->setText(QApplication::translate("vtk_testClass", "Load Patient File", 0));
        actionTracker_Setup->setText(QApplication::translate("vtk_testClass", "Tracker Setup", 0));
        actionRegister_Patient->setText(QApplication::translate("vtk_testClass", "Register Patient", 0));
        menuFile->setTitle(QApplication::translate("vtk_testClass", "File", 0));
    } // retranslateUi

};

namespace Ui {
    class vtk_testClass: public Ui_vtk_testClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VTK_TEST_H
