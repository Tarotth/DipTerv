#ifndef QTOGRE_QOGREWIDGET_H
#define QTOGRE_QOGREWIDGET_H

#include "Ogre.h"
#define OIS_DYNAMIC_LIB
#include <OIS.h>


#include <QtOpenGL/QGLWidget>

namespace qt_ogre
{
//*********************************************************************************************************************
  /** Qt widget that wraps an embedded ogre render window
   *
   * This classes only responsibility is to initialise the ogre render window. The Ogre::Root object
   * to be used must be supplied by the user and once initialised the intended usage is to extract the
   * ogre render window and manipulate it directly to create the desired scene. The underlying widget
   * takes care of rendering and resizing when necessary.
   */
  class QOgreWidget : public QWidget
  {
    Q_OBJECT

  public: // interface
    /** Constructor
     *
     * @param parent is required because ogre needs to set it as it's parent during initialisation
     *
     * @throws if parent is NULL
     *
     * @post Ogre3D renderwindow has been created
     */
    QOgreWidget(Ogre::Root* ogreRoot, QWidget* parent);

    Ogre::RenderWindow* getEmbeddedOgreWindow();

	Ogre::SceneManager* getSceneManager();

  protected: // interface
    /** @name Inherited from QWidget
     */
    //@{
      virtual void paintEvent(QPaintEvent* pEvent);
      virtual void resizeEvent(QResizeEvent* rEvent);
      virtual void update();
	  virtual void mousePressEvent(QMouseEvent *mEvent);
	  //virtual bool framestarted(const FrameEvent& evt);
    //@}

  private: // data
    Ogre::Root* ogreRoot_; // hold a pointer here so that we can trigger rendering
    Ogre::RenderWindow* ogreRenderWindow_;
	OIS::InputManager* OISInputManager;
	Ogre::Camera* camera;
	Ogre::SceneManager* sceneManager;
	Ogre::Viewport* ogreViewport_;
	OIS::Mouse* mMouse;
	OIS::Keyboard* mKeyboard;

  }; // class

//*********************************************************************************************************************

} // namespace

#endif // QTOGRE_QOGREWIDGET_H
