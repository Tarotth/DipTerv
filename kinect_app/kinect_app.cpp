#include "kinect_app.h"

kinect_app::kinect_app(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

kinect_app::~kinect_app()
{

}

void kinect_app::recieveProcess(JointOrientation* joints, Joint* jointPos, int size)
{
    ui.ogreWidget_->renderJoints(joints, jointPos, size);
	emit renderReady();
}

void kinect_app::on_actionNew_Project_triggered()
{

}

void kinect_app::on_actionOpen_Project_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Open Image"), "/home/jana", tr("Image Files (*.png *.jpg *.bmp)"));
}


void kinect_app::on_actionSave_Project_triggered()
{

}

void kinect_app::on_actionSave_Project_As_triggered()
{

}

void kinect_app::on_actionAbout_triggered()
{

}

void kinect_app::on_actionLoad_Model_triggered()
{

}

void kinect_app::on_actionExit_triggered()
{

}

void kinect_app::on_actionSkin_triggered()
{

}

void kinect_app::on_actionBones_triggered()
{

}

void kinect_app::on_actionGround_Plane_triggered()
{

}

void kinect_app::on_RecButton_clicked()
{

}

void kinect_app::on_BackButton_clicked()
{

}

void kinect_app::on_PlayPauseButton_clicked()
{

}

void kinect_app::on_StopButton_clicked()
{

}

void kinect_app::on_ForwardButton_clicked()
{

}
