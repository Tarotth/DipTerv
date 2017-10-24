/********************************************************************************
** Form generated from reading UI file 'kinect_app.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KINECT_APP_H
#define UI_KINECT_APP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_kinect_appClass
{
public:
    QAction *actionNew_Project;
    QAction *actionOpen_Project;
    QAction *actionSave_Project;
    QAction *actionSave_Project_As;
    QAction *actionAbout;
    QAction *actionClose_Project;
    QAction *actionOpen_Animation;
    QAction *actionExport;
    QAction *actionExit;
    QAction *actionUndo;
    QAction *actionRedo;
    QAction *actionCopy;
    QAction *actionPaste;
    QAction *actionSkin;
    QAction *actionBones;
    QAction *actionGround_Plane;
    QAction *actionCamera;
    QWidget *centralWidget;
    QGridLayout *gridLayout_6;
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLCDNumber *lcdNumber;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QSlider *horizontalSlider;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuView;
    QMenu *menuAbout;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *kinect_appClass)
    {
        if (kinect_appClass->objectName().isEmpty())
            kinect_appClass->setObjectName(QStringLiteral("kinect_appClass"));
        kinect_appClass->resize(600, 400);
        actionNew_Project = new QAction(kinect_appClass);
        actionNew_Project->setObjectName(QStringLiteral("actionNew_Project"));
        actionOpen_Project = new QAction(kinect_appClass);
        actionOpen_Project->setObjectName(QStringLiteral("actionOpen_Project"));
        actionSave_Project = new QAction(kinect_appClass);
        actionSave_Project->setObjectName(QStringLiteral("actionSave_Project"));
        actionSave_Project_As = new QAction(kinect_appClass);
        actionSave_Project_As->setObjectName(QStringLiteral("actionSave_Project_As"));
        actionAbout = new QAction(kinect_appClass);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        actionClose_Project = new QAction(kinect_appClass);
        actionClose_Project->setObjectName(QStringLiteral("actionClose_Project"));
        actionOpen_Animation = new QAction(kinect_appClass);
        actionOpen_Animation->setObjectName(QStringLiteral("actionOpen_Animation"));
        actionExport = new QAction(kinect_appClass);
        actionExport->setObjectName(QStringLiteral("actionExport"));
        actionExit = new QAction(kinect_appClass);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionUndo = new QAction(kinect_appClass);
        actionUndo->setObjectName(QStringLiteral("actionUndo"));
        actionRedo = new QAction(kinect_appClass);
        actionRedo->setObjectName(QStringLiteral("actionRedo"));
        actionCopy = new QAction(kinect_appClass);
        actionCopy->setObjectName(QStringLiteral("actionCopy"));
        actionPaste = new QAction(kinect_appClass);
        actionPaste->setObjectName(QStringLiteral("actionPaste"));
        actionSkin = new QAction(kinect_appClass);
        actionSkin->setObjectName(QStringLiteral("actionSkin"));
        actionBones = new QAction(kinect_appClass);
        actionBones->setObjectName(QStringLiteral("actionBones"));
        actionGround_Plane = new QAction(kinect_appClass);
        actionGround_Plane->setObjectName(QStringLiteral("actionGround_Plane"));
        actionCamera = new QAction(kinect_appClass);
        actionCamera->setObjectName(QStringLiteral("actionCamera"));
        centralWidget = new QWidget(kinect_appClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_6 = new QGridLayout(centralWidget);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetNoConstraint);
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tabWidget->addTab(tab_2, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);


        gridLayout_6->addLayout(gridLayout, 0, 0, 1, 2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetNoConstraint);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        lcdNumber = new QLCDNumber(centralWidget);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));

        horizontalLayout->addWidget(lcdNumber);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        horizontalLayout->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        horizontalLayout->addWidget(pushButton_4);

        pushButton_5 = new QPushButton(centralWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));

        horizontalLayout->addWidget(pushButton_5);

        pushButton_6 = new QPushButton(centralWidget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));

        horizontalLayout->addWidget(pushButton_6);


        verticalLayout->addLayout(horizontalLayout);

        horizontalSlider = new QSlider(centralWidget);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(horizontalSlider);


        gridLayout_6->addLayout(verticalLayout, 1, 0, 1, 2);

        kinect_appClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(kinect_appClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuView = new QMenu(menuBar);
        menuView->setObjectName(QStringLiteral("menuView"));
        menuAbout = new QMenu(menuBar);
        menuAbout->setObjectName(QStringLiteral("menuAbout"));
        kinect_appClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(kinect_appClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        kinect_appClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(kinect_appClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        kinect_appClass->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuView->menuAction());
        menuBar->addAction(menuAbout->menuAction());
        menuFile->addAction(actionNew_Project);
        menuFile->addAction(actionOpen_Project);
        menuFile->addAction(actionSave_Project);
        menuFile->addAction(actionSave_Project_As);
        menuFile->addAction(actionClose_Project);
        menuFile->addSeparator();
        menuFile->addAction(actionOpen_Animation);
        menuFile->addSeparator();
        menuFile->addAction(actionExport);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuEdit->addAction(actionUndo);
        menuEdit->addAction(actionRedo);
        menuEdit->addSeparator();
        menuEdit->addAction(actionCopy);
        menuEdit->addAction(actionPaste);
        menuView->addAction(actionSkin);
        menuView->addAction(actionBones);
        menuView->addAction(actionGround_Plane);
        menuView->addAction(actionCamera);
        menuAbout->addAction(actionAbout);
        mainToolBar->addAction(actionNew_Project);
        mainToolBar->addAction(actionOpen_Project);
        mainToolBar->addAction(actionSave_Project);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionUndo);
        mainToolBar->addAction(actionRedo);

        retranslateUi(kinect_appClass);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(kinect_appClass);
    } // setupUi

    void retranslateUi(QMainWindow *kinect_appClass)
    {
        kinect_appClass->setWindowTitle(QApplication::translate("kinect_appClass", "kinect_app", 0));
        actionNew_Project->setText(QApplication::translate("kinect_appClass", "New Project", 0));
        actionNew_Project->setShortcut(QApplication::translate("kinect_appClass", "Ctrl+N", 0));
        actionOpen_Project->setText(QApplication::translate("kinect_appClass", "Open Project", 0));
        actionOpen_Project->setShortcut(QApplication::translate("kinect_appClass", "Ctrl+O", 0));
        actionSave_Project->setText(QApplication::translate("kinect_appClass", "Save Project", 0));
        actionSave_Project->setShortcut(QApplication::translate("kinect_appClass", "Ctrl+S", 0));
        actionSave_Project_As->setText(QApplication::translate("kinect_appClass", "Save Project as...", 0));
        actionAbout->setText(QApplication::translate("kinect_appClass", "About", 0));
        actionAbout->setShortcut(QApplication::translate("kinect_appClass", "F1", 0));
        actionClose_Project->setText(QApplication::translate("kinect_appClass", "Close Project", 0));
        actionOpen_Animation->setText(QApplication::translate("kinect_appClass", "Open Animation...", 0));
        actionExport->setText(QApplication::translate("kinect_appClass", "Export", 0));
        actionExport->setShortcut(QApplication::translate("kinect_appClass", "Ctrl+E", 0));
        actionExit->setText(QApplication::translate("kinect_appClass", "Exit", 0));
        actionUndo->setText(QApplication::translate("kinect_appClass", "Undo", 0));
        actionUndo->setShortcut(QApplication::translate("kinect_appClass", "Ctrl+Z", 0));
        actionRedo->setText(QApplication::translate("kinect_appClass", "Redo", 0));
        actionRedo->setShortcut(QApplication::translate("kinect_appClass", "Ctrl+Y", 0));
        actionCopy->setText(QApplication::translate("kinect_appClass", "Copy", 0));
        actionCopy->setShortcut(QApplication::translate("kinect_appClass", "Ctrl+C", 0));
        actionPaste->setText(QApplication::translate("kinect_appClass", "Paste", 0));
        actionPaste->setShortcut(QApplication::translate("kinect_appClass", "Ctrl+V", 0));
        actionSkin->setText(QApplication::translate("kinect_appClass", "Skin", 0));
        actionBones->setText(QApplication::translate("kinect_appClass", "Bones", 0));
        actionGround_Plane->setText(QApplication::translate("kinect_appClass", "Ground Plane", 0));
        actionCamera->setText(QApplication::translate("kinect_appClass", "Cameras", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("kinect_appClass", "Tab 1", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("kinect_appClass", "Tab 2", 0));
        label->setText(QApplication::translate("kinect_appClass", "Time", 0));
        pushButton->setText(QApplication::translate("kinect_appClass", "PushButton", 0));
        pushButton_2->setText(QApplication::translate("kinect_appClass", "PushButton", 0));
        pushButton_3->setText(QApplication::translate("kinect_appClass", "PushButton", 0));
        pushButton_4->setText(QApplication::translate("kinect_appClass", "PushButton", 0));
        pushButton_5->setText(QApplication::translate("kinect_appClass", "PushButton", 0));
        pushButton_6->setText(QApplication::translate("kinect_appClass", "PushButton", 0));
        menuFile->setTitle(QApplication::translate("kinect_appClass", "File", 0));
        menuEdit->setTitle(QApplication::translate("kinect_appClass", "Edit", 0));
        menuView->setTitle(QApplication::translate("kinect_appClass", "View", 0));
        menuAbout->setTitle(QApplication::translate("kinect_appClass", "About", 0));
    } // retranslateUi

};

namespace Ui {
    class kinect_appClass: public Ui_kinect_appClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KINECT_APP_H
