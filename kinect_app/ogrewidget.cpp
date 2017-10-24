#include "ogrewidget.h"
#include "BodyProcess.h"

#include <QResizeEvent>

#include <string>
#include <cassert>

namespace qt_ogre
{
	MSG msg = { 0 };
	CBodyBasics Bp;
	HWND hWndApp;
//---------------------------------------------------------------------------------------------------------------------
  QOgreWidget::QOgreWidget(Ogre::Root* ogreRoot, QWidget* parent) :
    QWidget(parent),
    ogreRoot_(ogreRoot),
    ogreRenderWindow_(NULL)
  {
    if ( ! parent )
    {
      throw std::runtime_error("Parent widget supplied was uninitialised!"); // interface requirement
    }

    std::string justXid = Ogre::StringConverter::toString((unsigned long)(this->parentWidget()->winId()));
    Ogre::NameValuePairList params;
    params["parentWindowHandle"] = justXid;

    ogreRenderWindow_ = ogreRoot_->createRenderWindow( "QOgreWidget_RenderWindow",
                                                       this->width(),
                                                       this->height(),
                                                       false,
                                                       &params );

    //ogreRenderWindow_->setActive(true);
    //ogreRenderWindow_->setVisible(true);
	ogreRenderWindow_->setVSyncEnabled(true);

    WId ogreWinId = 0x0;
    ogreRenderWindow_->getCustomAttribute( "WINDOW", &ogreWinId );
    assert( ogreWinId ); // guaranteed to be valid due to the way it was created

    QWidget::create( ogreWinId );
    setAttribute( Qt::WA_OpaquePaintEvent ); // qt won't bother updating the area under/behind the render window

	
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

	ogreViewport_ = ogreRenderWindow_->addViewport( camera );
	ogreViewport_->setBackgroundColour( Ogre::ColourValue( 0.49, 0.56, 0.64 ) );


	//Init BodyProcess
	//WNDCLASS  wc;
	//// Dialog custom window class
	//ZeroMemory(&wc, sizeof(wc));
	//wc.style = CS_HREDRAW | CS_VREDRAW;
	//wc.cbWndExtra = DLGWINDOWEXTRA;
	//wc.hCursor = LoadCursorW(NULL, IDC_ARROW);
	//// wc.hIcon         = LoadIconW(hInstance, MAKEINTRESOURCE(IDI_APP));
	//wc.lpfnWndProc = DefDlgProcW;
	//wc.lpszClassName = L"BodyBasicsAppDlgWndClass";

	//if (!RegisterClassW(&wc))
	//{
	//	return;
	//}

	//CBodyBasics::MessageRouter((HWND)ogreWinId,msg,1,0);

	// Create main application window
	//hWndApp = CreateDialogParamW(
	//	NULL,
	//	MAKEINTRESOURCE(IDD_APP),
	//	NULL,
	//	(DLGPROC)CBodyBasics::MessageRouter,
	//	reinterpret_cast<LPARAM>(this));

	//// Show window
	//ShowWindow(hWndApp, 1);

	/*OIS::ParamList pl;

	size_t windowHnd = 0;
	ogreRenderWindow_->getCustomAttribute("WINDOW", &windowHnd);
	std::ostringstream windowHndStr;
	windowHndStr << windowHnd;
	pl.insert(std::make_pair(std::string("WINDOW"), windowHndStr.str()));

	OISInputManager = OIS::InputManager::createInputSystem( pl );


	try{
		mMouse = static_cast<OIS::Mouse*>(OISInputManager->createInputObject( OIS::OISMouse, true ));
	}
	catch(const OIS::Exception ex)
	{
		throw ex;
	}
	/*mKeyboard  =  static_cast<OIS::Keyboard*>
				(OISInputManager->createInputObject( OIS::OISKeyboard, false ));*/


  }

//---------------------------------------------------------------------------------------------------------------------
  Ogre::RenderWindow* QOgreWidget::getEmbeddedOgreWindow()
  {
    assert(ogreRenderWindow_); // guaranteed to be valid after construction
    return ogreRenderWindow_;

  }

 //---------------------------------------------------------------------------------------------------------------------
  Ogre::SceneManager* QOgreWidget::getSceneManager()
  {
    assert(sceneManager); // guaranteed to be valid after construction
	return sceneManager;

  }

//---------------------------------------------------------------------------------------------------------------------
  void QOgreWidget::paintEvent(QPaintEvent* pEvent)
  {
    this->update();

  }

//---------------------------------------------------------------------------------------------------------------------
  void QOgreWidget::resizeEvent(QResizeEvent* rEvent)
  {
    if (rEvent)
    {
      QWidget::resizeEvent( rEvent);
    }

    if (ogreRenderWindow_)
    {
       // since the underlying widget has already been updated we can source the resize values from there
       ogreRenderWindow_->reposition( x(), y() );
       ogreRenderWindow_->resize( width(), height() );
       ogreRenderWindow_->windowMovedOrResized();
    }

  }

//---------------------------------------------------------------------------------------------------------------------
  void QOgreWidget::update()
  {
    QWidget::update();
    ogreRoot_->renderOneFrame();

	//while (WM_QUIT != msg.message)
	//{
	//	Bp.Update();

	//	while (PeekMessageW(&msg, NULL, 0, 0, PM_REMOVE))
	//	{
	//		// If a dialog message will be taken care of by the dialog proc
	//		if (hWndApp && IsDialogMessageW(hWndApp, &msg))
	//		{
	//			continue;
	//		}

	//		TranslateMessage(&msg);
	//		DispatchMessageW(&msg);
	//	}
	//}

	/*Ogre::Vector3 camright = camera->getRight();
	Ogre::Vector3 camup = camera->getUp();
	Ogre::Vector3 cammove(0,0,0);
	float mousesensitivity = 1.0f;
	float cameraRotateSpeed = 25.0f;
	mMouse->capture();

	const OIS::MouseState &ms = mMouse->getMouseState();

	if(ms.buttonDown(OIS::MB_Right))
	{
		cammove += camright * ms.X.rel * 0.01f;
		cammove += camup * ms.Y.rel * 0.01f;
	}
	else
	{
		camera->yaw(Ogre::Radian(-cameraRotateSpeed * mousesensitivity * ms.X.rel * 0.01f));
		camera->pitch(Ogre::Radian(-cameraRotateSpeed * mousesensitivity * ms.Y.rel * 0.01f));
	}*/

		
  }

//---------------------------------------------------------------------------------------------------------------------
  void QOgreWidget::mousePressEvent(QMouseEvent *mEvent)
  {
	Ogre::Vector3 camright = camera->getRight();
	Ogre::Vector3 camup = camera->getUp();
	Ogre::Vector3 cammove(0,0,0);
	float mousesensitivity = 1.0f;
	float cameraRotateSpeed = 25.0f;

	//const OIS::MouseState &ms = mMouse->getMouseState();

	if(mEvent->button() == Qt::LeftButton)
	{
		cammove += camright * mEvent->x() * 0.01f;
		cammove += camup * mEvent->y() * 0.01f;
	}
	else
	{
		camera->yaw(Ogre::Radian(-cameraRotateSpeed * mousesensitivity * mEvent->x() * 0.01f));
		camera->pitch(Ogre::Radian(-cameraRotateSpeed * mousesensitivity * mEvent->y() * 0.01f));
	}

  }

//---------------------------------------------------------------------------------------------------------------------

} // namespace
