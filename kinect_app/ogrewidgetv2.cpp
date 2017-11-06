#include "ogrewidgetv2.h"
#include <QResizeEvent>
#include <string>
#include <cassert>
#include <iostream>
#include <fstream>
#include "ViewportGrid.h"
#include "RTShaderSystem/OgreShaderGenerator.h"
#include "RTShaderSystem/OgreRTShaderSystem.h"

#ifdef __unix__
#include <QtX11Extras/QX11Info>
#endif

Ogre::SceneNode* rootNode;
Ogre::SceneNode* sphereNode[25];
Ogre::Entity* mEntity[25];
Ogre::ViewportGrid* grid;
Ogre::Entity* robot;
Ogre::Vector3 prevPosBone[25];
Ogre::Vector3 prevPosKinect[25];

RTSHADER_SYSTEM_BUILD_CORE_SHADERS
RTSHADER_SYSTEM_BUILD_EXT_SHADERS

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
	camera->setPosition(0, 2, 15);
	camera->lookAt(0, 2, 0);
	camera->setFarClipDistance(1000);
    camera->setNearClipDistance(0.1f);

	ogreViewport_ = mOgreRenderWindow->addViewport(camera);
    ogreViewport_->setBackgroundColour(Ogre::ColourValue(0.8f, 0.8f, 0.8f, 0.0f));

	grid = new Ogre::ViewportGrid(sceneManager,ogreViewport_);
	grid->enable();

	rootNode = sceneManager->getRootSceneNode();

	//Ogre::RTShader::ShaderGenerator* mShaderGenerator;

	//if (Ogre::RTShader::ShaderGenerator::initialize())
	//{
	//	// Grab the shader generator pointer.
	//	mShaderGenerator = Ogre::RTShader::ShaderGenerator::getSingletonPtr();

	//	// Add the shader libs resource location. a sample shader lib can be found in Samples\Media\RTShaderLib
	//	Ogre::ResourceGroupManager::getSingleton().addResourceLocation("D:\\egyetem\\Msc dipterv\\ogre sdk\\OGRE-SDK-1.9.0-vc140-x64-12.03.2016\\media\\RTShaderLib", "FileSystem");

	//	// Set shader cache path.
	//	mShaderGenerator->setShaderCachePath("D:\\egyetem\\Msc dipterv\\kinect_app\\bin\\media");

	//	// Set the scene manager.
	//	mShaderGenerator->addSceneManager(sceneManager);

	//	// Add a specialized sub-render (per-pixel lighting) state to the default scheme render state
	//	Ogre::RTShader::RenderState* pMainRenderState =
	//		mShaderGenerator->createOrRetrieveRenderState(Ogre::RTShader::ShaderGenerator::DEFAULT_SCHEME_NAME).first;
	//	pMainRenderState->reset();

	//	//mShaderGenerator->addSubRenderStateFactory(new Ogre::RTShader::PerPixelLightingFactory);
	//	pMainRenderState->addTemplateSubRenderState(mShaderGenerator->createSubRenderState(Ogre::RTShader::PerPixelLighting::Type));
	//}

	//mShaderGenerator->createShaderBasedTechnique("Examples/BeachStones", Ogre::MaterialManager::DEFAULT_SCHEME_NAME, Ogre::RTShader::ShaderGenerator::DEFAULT_SCHEME_NAME);
	//ogreViewport_->setMaterialScheme(Ogre::RTShader::ShaderGenerator::DEFAULT_SCHEME_NAME);

	Ogre::SceneNode* robotNode = rootNode->createChildSceneNode();
	robot = sceneManager->createEntity("robo1", "robo1.mesh");
	robotNode->attachObject(robot);
	robot->setMaterialName("robo1.material");
	//robotNode->setScale(10,10,10);
	//robot->setDisplaySkeleton(1);
	//archway->setSkeletonName();

	Ogre::Light* light = sceneManager->createLight("MainLight");
	light->setPosition(20, 80, 50);

	for (int i = 0; i < 25; i++)
	{
		Ogre::String number = Ogre::StringConverter::toString(i + 1);

		sphereNode[i] = rootNode->createChildSceneNode();
		mEntity[i] = sceneManager->createEntity("mySphere" + number, Ogre::SceneManager::PT_SPHERE);
		sphereNode[i]->attachObject(mEntity[i]);
		mEntity[i]->setMaterialName("Shader1_4_0.material");
        sphereNode[i]->setScale(Ogre::Vector3(0.001f, 0.001f, 0.001f));
	}
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


void QOgreWidgetv2::renderJoints(JointOrientation* joints, Joint* jointPos, int size)
{
	//std::ofstream myfile;
	//myfile.open("D:\\egyetem\\Msc dipterv\\joints.txt");

	//Ogre::Bone* bone = robot->getSkeleton()->getBone("ShoulderLeft");
	//bone->setManuallyControlled(true);
	//bone->resetOrientation();
	//Ogre::Quaternion parentOrientation = bone->getParent()->_getFullTransform().extractQuaternion();
	//Ogre::Quaternion kinectOrient = Ogre::Quaternion(joints[8].Orientation.w, joints[8].Orientation.x, joints[8].Orientation.y, joints[8].Orientation.z);
	//Ogre::Quaternion orientation = parentOrientation.Inverse() * kinectOrient;
	//bone->setOrientation(orientation);

	//bone = robot->getSkeleton()->getBone("ElbowLeft");
	//bone->setManuallyControlled(true);
	//bone->resetOrientation();
	//parentOrientation = bone->getParent()->_getFullTransform().extractQuaternion();
	//kinectOrient = Ogre::Quaternion(joints[9].Orientation.w, joints[9].Orientation.x, joints[9].Orientation.y, joints[9].Orientation.z);
	//orientation = parentOrientation.Inverse() * kinectOrient;
	//bone->setOrientation(orientation);

	//bone = robot->getSkeleton()->getBone("WristLeft");
	//bone->setManuallyControlled(true);
	//bone->resetOrientation();
	//parentOrientation = bone->getParent()->_getFullTransform().extractQuaternion();
	//kinectOrient = Ogre::Quaternion(joints[10].Orientation.w, joints[10].Orientation.x, joints[10].Orientation.y, joints[10].Orientation.z);
	//orientation = parentOrientation.Inverse() * kinectOrient;
	//bone->setOrientation(orientation);

	for (int j = 0; j < size; j++)
	{
		std::string jointname;
		switch (joints[j].JointType)
		{
		case 0:
			jointname = "SpineBase";
			break;
		case 1:
			jointname = "SpineMid";
			//jointname = "SpineLower_M";
			break;
		case 2:
			jointname = "Neck";
			//jointname = "Neck_M";
			break;
		case 3:
			jointname = "Head";
			//jointname = "Head_M";
			break;
		case 4:
			jointname = "ShoulderLeft";
			//jointname = "Clavicle_L";
			break;
		case 5:
			jointname = "ElbowLeft";
			//jointname = "UpperArm_L";
			break;
		case 6:
			jointname = "WristLeft";
			break;
		case 7:
			jointname = "HandLeft";
			break;
		case 8:
			jointname = "ShoulderRight";
			break;
		case 9:
			jointname = "ElbowRight";
			break;
		case 10:
			jointname = "WristRight";
			break;
		case 11:
			jointname = "HandRight";
			break;
		case 12:
			jointname = "HipLeft";
			break;
		case 13:
			jointname = "KneeLeft";
			break;
		case 14:
			jointname = "AnkleLeft";
			break;
		case 15:
			jointname = "FootLeft";
			break;
		case 16:
			jointname = "HipRight";
			break;
		case 17:
			jointname = "KneeRight";
			break;
		case 18:
			jointname = "AnkleRight";
			break;
		case 19:
			jointname = "FootRight";
			break;
		case 20:
			jointname = "SpineShoulder";
			break;
		case 21:
			jointname = "HandTipLeft";
			break;
		case 22:
			jointname = "ThumbLeft";
			break;
		case 23:
			jointname = "HandTipRight";
			break;
		case 24:
			jointname = "ThumbRight";
			break;
		default:
			break;
		}

		/*myfile << j << " "<< joints[j].JointType << std::endl;*/
		try {
			sphereNode[j]->setPosition(Ogre::Vector3(jointPos[j].Position.X, jointPos[j].Position.Y, jointPos[j].Position.Z));
			//sphereNode[j]->setPosition(Ogre::Vector3(joints[j].Orientation.x, joints[j].Orientation.x, joints[j].Orientation.z));
			//setupBone(jointname);

			Ogre::Bone* bone = robot->getSkeleton()->getBone(jointname);
			bone->setManuallyControlled(true);
			bone->resetOrientation();
			Ogre::Quaternion parentOrientation = bone->getParent()->_getFullTransform().extractQuaternion();


			Ogre::Quaternion kinectOrient = Ogre::Quaternion(joints[j].Orientation.w, joints[j].Orientation.x, joints[j].Orientation.y, joints[j].Orientation.z);
			convertCoordinateSystem(&kinectOrient);
			//kinectOrient = bone->convertWorldToLocalOrientation(kinectOrient);
			Ogre::Quaternion orientation = parentOrientation.Inverse() * kinectOrient;

			bone->setOrientation(orientation);
		}
		catch(std::exception &e)
		{
			std::ofstream myfile;
			myfile.open("D:\\egyetem\\Msc dipterv\\err.txt");
			myfile << e.what() << std::endl;
			myfile.close();
		}
	}
	/*myfile.close();*/
}

void QOgreWidgetv2::setupBone(std::string name) {
	Ogre::Bone* bone = robot->getSkeleton()->getBone(name);
	Ogre::Quaternion initial = bone->_getDerivedOrientation(); // save orientation
	bone->setManuallyControlled(true);
	bone->setInheritOrientation(false);
	bone->resetToInitialState();
	bone->resetOrientation();
	bone->setOrientation(initial); // restore it
	bone->setInitialState();
}

void QOgreWidgetv2::convertCoordinateSystem(Ogre::Quaternion* quat)
{
	quat->w = -quat->w;
	quat->x = quat->x;
	quat->y = quat->y;
	quat->z = -quat->z;
}
