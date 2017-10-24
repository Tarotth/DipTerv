#include "kinect_app.h"
#include "BodyProcess.h"
#include <QtWidgets/QApplication>
#include "stdafx.h"
#include "resource.h"
#include <QThread>

#include "Ogre.h"
#include "BodyProcess.h"

//using namespace Ogre;

Ogre::Root* ogreRoot;
Ogre::SceneManager* sceneManager;
Ogre::Camera* camera;
Ogre::RenderWindow* renderWindow;
Ogre::Light* light;

class WorkerClass : public QThread
{
private:
	BodyProcess* bp;
public:

	WorkerClass()
	{
		bp = new BodyProcess();
	}

	void run()
	{
		while (true)
		{
			bp->Update();
			QThread::msleep(50);

		}
	}
};

void setupScene()
{
	camera = sceneManager->createCamera("Main Camera");       
	camera->setPosition(0, 20, 100); 
	camera->lookAt(0, 20, 0);
	camera->setFarClipDistance(1000);
	camera->setNearClipDistance(0.1);

	Ogre::Viewport* viewport = renderWindow->addViewport(camera);
	renderWindow->setActive(true); 

}

void setupListeners()
{
}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	kinect_app w;
	w.show();



	WorkerClass *workerThread = new WorkerClass;

	QObject::connect(workerThread, SIGNAL(progressChanged(QString)), workerThread, SLOT(onProgressChanged(QString)));
	QObject::connect(workerThread, SIGNAL(finished()), workerThread, SLOT(deleteLater()));
	workerThread->start(); // This invokes WorkerThread::run in a new thread

	return a.exec();
}
