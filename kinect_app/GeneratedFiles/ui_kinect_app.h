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
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolButton>
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
    QAction *actionLoad_Model;
    QAction *actionExit;
    QAction *actionSkin;
    QAction *actionBones;
    QAction *actionGround_Plane;
    QWidget *centralWidget;
    QGridLayout *gridLayout_6;
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QToolButton *RecButton;
    QToolButton *BackButton;
    QToolButton *PlayPauseButton;
    QToolButton *StopButton;
    QToolButton *ForwardButton;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLCDNumber *lcdNumber;
    QSlider *horizontalSlider;
    QMenuBar *menuBar;
    QMenu *menuFile;
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
        actionLoad_Model = new QAction(kinect_appClass);
        actionLoad_Model->setObjectName(QStringLiteral("actionLoad_Model"));
        actionExit = new QAction(kinect_appClass);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionSkin = new QAction(kinect_appClass);
        actionSkin->setObjectName(QStringLiteral("actionSkin"));
        actionBones = new QAction(kinect_appClass);
        actionBones->setObjectName(QStringLiteral("actionBones"));
        actionGround_Plane = new QAction(kinect_appClass);
        actionGround_Plane->setObjectName(QStringLiteral("actionGround_Plane"));
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
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        RecButton = new QToolButton(centralWidget);
        RecButton->setObjectName(QStringLiteral("RecButton"));
        QIcon icon;
        icon.addFile(QStringLiteral("Resources/record.png"), QSize(), QIcon::Normal, QIcon::Off);
        RecButton->setIcon(icon);

        horizontalLayout->addWidget(RecButton);

        BackButton = new QToolButton(centralWidget);
        BackButton->setObjectName(QStringLiteral("BackButton"));
        BackButton->setMinimumSize(QSize(50, 50));
        QIcon icon1;
        icon1.addFile(QStringLiteral("Resources/backward2.png"), QSize(), QIcon::Normal, QIcon::Off);
        BackButton->setIcon(icon1);

        horizontalLayout->addWidget(BackButton);

        PlayPauseButton = new QToolButton(centralWidget);
        PlayPauseButton->setObjectName(QStringLiteral("PlayPauseButton"));
        PlayPauseButton->setMinimumSize(QSize(50, 50));
        QIcon icon2;
        icon2.addFile(QStringLiteral("Resources/play4.png"), QSize(), QIcon::Normal, QIcon::Off);
        PlayPauseButton->setIcon(icon2);

        horizontalLayout->addWidget(PlayPauseButton);

        StopButton = new QToolButton(centralWidget);
        StopButton->setObjectName(QStringLiteral("StopButton"));
        QIcon icon3;
        icon3.addFile(QStringLiteral("Resources/stop3.png"), QSize(), QIcon::Normal, QIcon::Off);
        StopButton->setIcon(icon3);

        horizontalLayout->addWidget(StopButton);

        ForwardButton = new QToolButton(centralWidget);
        ForwardButton->setObjectName(QStringLiteral("ForwardButton"));
        QIcon icon4;
        icon4.addFile(QStringLiteral("Resources/forward2.png"), QSize(), QIcon::Normal, QIcon::Off);
        ForwardButton->setIcon(icon4);

        horizontalLayout->addWidget(ForwardButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_2->addWidget(label);

        lcdNumber = new QLCDNumber(centralWidget);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));

        horizontalLayout_2->addWidget(lcdNumber);

        horizontalSlider = new QSlider(centralWidget);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(horizontalSlider);


        verticalLayout->addLayout(horizontalLayout_2);


        gridLayout_6->addLayout(verticalLayout, 1, 0, 1, 2);

        kinect_appClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(kinect_appClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
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
        menuBar->addAction(menuView->menuAction());
        menuBar->addAction(menuAbout->menuAction());
        menuFile->addAction(actionNew_Project);
        menuFile->addAction(actionOpen_Project);
        menuFile->addAction(actionSave_Project);
        menuFile->addAction(actionSave_Project_As);
        menuFile->addSeparator();
        menuFile->addAction(actionLoad_Model);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuView->addAction(actionSkin);
        menuView->addAction(actionBones);
        menuView->addAction(actionGround_Plane);
        menuAbout->addAction(actionAbout);
        mainToolBar->addAction(actionNew_Project);
        mainToolBar->addAction(actionOpen_Project);
        mainToolBar->addAction(actionSave_Project);

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
        actionLoad_Model->setText(QApplication::translate("kinect_appClass", "Load Model", 0));
        actionExit->setText(QApplication::translate("kinect_appClass", "Exit", 0));
        actionSkin->setText(QApplication::translate("kinect_appClass", "Skin", 0));
        actionBones->setText(QApplication::translate("kinect_appClass", "Bones", 0));
        actionGround_Plane->setText(QApplication::translate("kinect_appClass", "Ground Plane", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("kinect_appClass", "Event Log", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("kinect_appClass", "Model info", 0));
#ifndef QT_NO_TOOLTIP
        RecButton->setToolTip(QApplication::translate("kinect_appClass", "Record button", 0));
#endif // QT_NO_TOOLTIP
        RecButton->setText(QApplication::translate("kinect_appClass", "...", 0));
        RecButton->setShortcut(QApplication::translate("kinect_appClass", "R", 0));
#ifndef QT_NO_TOOLTIP
        BackButton->setToolTip(QApplication::translate("kinect_appClass", "Backward button", 0));
#endif // QT_NO_TOOLTIP
        BackButton->setText(QApplication::translate("kinect_appClass", "...", 0));
        BackButton->setShortcut(QApplication::translate("kinect_appClass", "B", 0));
#ifndef QT_NO_TOOLTIP
        PlayPauseButton->setToolTip(QApplication::translate("kinect_appClass", "Play/Pause button", 0));
#endif // QT_NO_TOOLTIP
        PlayPauseButton->setText(QApplication::translate("kinect_appClass", "...", 0));
#ifndef QT_NO_TOOLTIP
        StopButton->setToolTip(QApplication::translate("kinect_appClass", "Stop button", 0));
#endif // QT_NO_TOOLTIP
        StopButton->setText(QApplication::translate("kinect_appClass", "...", 0));
        StopButton->setShortcut(QApplication::translate("kinect_appClass", "S", 0));
#ifndef QT_NO_TOOLTIP
        ForwardButton->setToolTip(QApplication::translate("kinect_appClass", "Forward button", 0));
#endif // QT_NO_TOOLTIP
        ForwardButton->setText(QApplication::translate("kinect_appClass", "...", 0));
        ForwardButton->setShortcut(QApplication::translate("kinect_appClass", "F", 0));
        label->setText(QApplication::translate("kinect_appClass", "Time", 0));
        menuFile->setTitle(QApplication::translate("kinect_appClass", "File", 0));
        menuView->setTitle(QApplication::translate("kinect_appClass", "View", 0));
        menuAbout->setTitle(QApplication::translate("kinect_appClass", "About", 0));
    } // retranslateUi

};

namespace Ui {
    class kinect_appClass: public Ui_kinect_appClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KINECT_APP_H
