#include "kinect_app.h"
#include "WorkerClass.h"


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	kinect_app w;
	w.show();


	WorkerClass *workerThread = new WorkerClass;

	QObject::connect(workerThread, SIGNAL(processReady(JointOrientation*, Joint*, int)), &w, SLOT(recieveProcess(JointOrientation*, Joint*, int)));
	QObject::connect(&w, SIGNAL(renderReady()), workerThread, SLOT(recieveRender()));
	workerThread->start();

	return a.exec();
}
