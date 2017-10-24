#ifndef KINECT_APP_H
#define KINECT_APP_H

#include <QtWidgets/QMainWindow>
#include "kinect_ui.h"

class kinect_app : public QMainWindow
{
	Q_OBJECT

public:
	kinect_app(QWidget *parent = 0);
	~kinect_app();

private:
	Ui::kinect_appClass ui;
};

#endif // KINECT_APP_H
