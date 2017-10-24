#include "ogrewidgetv2.h"
#include <QResizeEvent>
#include <string>
#include <cassert>
#include <iostream>
#include <fstream>

#ifdef __unix__
#include <QtX11Extras/QX11Info>
#endif


QOgreWidgetv2::QOgreWidgetv2(Ogre::Root* ogreRoot, IOgreEventHandler *ogreEventHandler, QWidget* parent) :
	QGLWidget(parent),
	mOgreEventHandler(ogreEventHandler),
	mOgreRoot(ogreRoot),
	mOgreRenderWindow(NULL) {

	if (!parent) {
		throw std::runtime_error("Parent widget supplied was uninitialised!"); // interface requirement
	}

	setAttribute(Qt::WA_PaintOnScreen, true);
	setAttribute(Qt::WA_NoSystemBackground, true);
	setFocusPolicy(Qt::StrongFocus);

	Ogre::String winHandle;
#ifdef WIN32
	// Windows code
	winHandle += Ogre::StringConverter::toString(this->parentWidget()->winId());
#else
	winHandle = Ogre::StringConverter::toString((unsigned long)(QX11Info::display()));
	winHandle += ":";
	winHandle += Ogre::StringConverter::toString((unsigned int)(QX11Info::appScreen()));
	winHandle += ":";
	winHandle += Ogre::StringConverter::toString((unsigned long)(winId()));
#endif

	Ogre::NameValuePairList params;
	params["parentWindowHandle"] = winHandle;
	params["FSAA"] = Ogre::String("8");

	int w = width();
	int h = height();
	mOgreRenderWindow = mOgreRoot->createRenderWindow("OgreWidget_RenderWindow", qMax(w, 640), qMax(h, 480), false, &params);
	mOgreRenderWindow->setActive(true);
	mOgreRenderWindow->setVisible(true);

	WId ogreWinId = 0x0;
	mOgreRenderWindow->getCustomAttribute("WINDOW", &ogreWinId);
	assert(ogreWinId); // guaranteed to be valid due to the way it was created
	QWidget::create(ogreWinId);
	setAttribute(Qt::WA_OpaquePaintEvent);   // qt won't bother updating the area under/behind the render window

	Ogre::ResourceGroupManager::getSingleton().addResourceLocation("media",
		"FileSystem",
		"General",
		false);
	Ogre::ResourceGroupManager::getSingleton().initialiseAllResourceGroups();

	sceneManager = ogreRoot->createSceneManager(Ogre::ST_EXTERIOR_CLOSE);

	camera = sceneManager->createCamera("Main Camera");
	camera->setPosition(0, 20, 100);
	camera->lookAt(0, 20, 0);
	camera->setFarClipDistance(1000);
	camera->setNearClipDistance(0.1);

	ogreViewport_ = mOgreRenderWindow->addViewport(camera);
}


Ogre::RenderWindow *QOgreWidgetv2::getEmbeddedOgreWindow() {
	assert(mOgreRenderWindow); // guaranteed to be valid after construction
	return mOgreRenderWindow;
}


void QOgreWidgetv2::paintEvent(QPaintEvent *pEvent) {
	this->update();
}


void QOgreWidgetv2::resizeEvent(QResizeEvent *rEvent) {
	if (rEvent) {
		QWidget::resizeEvent(rEvent);
	}

	if (mOgreRenderWindow) {
		// since the underlying widget has already been updated we can source the resize values from there
		mOgreRenderWindow->reposition(x(), y());
		mOgreRenderWindow->resize(width(), height());
		mOgreRenderWindow->windowMovedOrResized();
	}
}


void QOgreWidgetv2::mousePressEvent(QMouseEvent *event) {
	mOgreEventHandler->ogreMousePressEvent(event);
}


void QOgreWidgetv2::mouseMoveEvent(QMouseEvent *event) {
	mOgreEventHandler->ogreMouseMoveEvent(event);
}

void QOgreWidgetv2::wheelEvent(QWheelEvent *event) {
	mOgreEventHandler->onZoomEvent(event);
}

void QOgreWidgetv2::update() {
	try {
		QWidget::update();
		mOgreRoot->renderOneFrame();
	}
	catch(std::exception &e)
	{
		std::ofstream myfile;
		myfile.open("D:\\egyetem\\Msc dipterv\\err.txt");
		myfile << e.what() << std::endl;
		myfile.close();
		//std::cout << "\nERROR: " << e.what() << std::endl;
	}
}

Ogre::SceneManager* QOgreWidgetv2::getSceneManager()
{
	assert(sceneManager); // guaranteed to be valid after construction
	return sceneManager;

}

QOgreWidgetv2* QOgreWidgetv2::instance = 0;

QOgreWidgetv2* QOgreWidgetv2::getInstance(Ogre::Root *ogreRoot, IOgreEventHandler *ogreEventHandler, QWidget *parent)
{
	if (instance == 0)
	{
		instance = new QOgreWidgetv2(ogreRoot,ogreEventHandler,parent);
	}

	return instance;
}

QOgreWidgetv2* QOgreWidgetv2::getInstance()
{
	if (instance == 0)
	{
		return 0;
	}

	return instance;
}