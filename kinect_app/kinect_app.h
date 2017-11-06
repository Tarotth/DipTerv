#ifndef KINECT_APP_H
#define KINECT_APP_H

#include <QtWidgets/QMainWindow>
#include "kinect_ui.h"
#include <qfiledialog.h>
#include "Kinect.h"

class kinect_app : public QMainWindow
{
	Q_OBJECT

public:
	kinect_app(QWidget *parent = 0);
	~kinect_app();

private:
	Ui::kinect_appClass ui;

public slots:
	void recieveProcess(JointOrientation* joints, Joint* jointPos, int size);
signals:
	void renderReady();
private slots:
    void on_actionNew_Project_triggered();
    void on_actionOpen_Project_triggered();
    void on_actionSave_Project_triggered();
    void on_actionSave_Project_As_triggered();
    void on_actionAbout_triggered();
    void on_actionLoad_Model_triggered();
    void on_actionExit_triggered();
    void on_actionSkin_triggered();
    void on_actionBones_triggered();
    void on_actionGround_Plane_triggered();
    void on_RecButton_clicked();
    void on_BackButton_clicked();
    void on_PlayPauseButton_clicked();
    void on_StopButton_clicked();
    void on_ForwardButton_clicked();
};

#endif // KINECT_APP_H
