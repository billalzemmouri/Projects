# ifndef INPUTLISTENER_HH_
# define INPUTLISTENER_HH_
# include <OIS/OIS.h>
# include <Ogre.h>
# include <vector>
# include <SdkTrays.h>
# include <SdkCameraMan.h>
# include <thread>
# include <CEGUI/CEGUI.h>
# include <Renderer.h>
# include "Worm.hh"
# include "Menu.hh"

class InputListener : public Ogre::FrameListener, public Ogre::WindowEventListener, public OIS::KeyListener, public OIS::MouseListener
		    , public OgreBites::SdkTrayListener
{
public:
  InputListener(Ogre::RenderWindow *window, Ogre::Camera *camera, Ogre::SceneManager *sceneMgr, bool *isEnd,
		std::vector<Worm*> *listWorms, int *curWorm, Menu *_Menu);
  ~InputListener();
  OIS::Mouse	*getMouse() const;
  OIS::Keyboard *getKeyboard() const;
  void		Exit();

private:
  void 		startOIS();
  bool 		frameRenderingQueued(const Ogre::FrameEvent &evt);
  
  void 		windowResized(Ogre::RenderWindow *rw);
  void 		windowClosed(Ogre::RenderWindow *rw);

  bool 		keyPressed(const OIS::KeyEvent &arg);
  bool 		keyReleased(const OIS::KeyEvent &arg);

  bool 		mouseMoved(const OIS::MouseEvent & arg);
  bool 		mousePressed(const OIS::MouseEvent & arg, OIS::MouseButtonID id);
  bool 		mouseReleased(const OIS::MouseEvent & arg, OIS::MouseButtonID id);

  void		setDeplacementWorm(const OIS::KeyEvent &arg);

  void		setupCEGUI(void);
  void		changeMouse(void);
  void		pressESCAPE();


  CEGUI::OgreRenderer	*mRenderer;
  Ogre::RenderWindow 	*mWindow;
  Ogre::Camera		*mCamera;
  Ogre::SceneManager	*mSceneMgr;

  OIS::InputManager 	*mInputMgr;
  OIS::Mouse 		*mMouse;
  OIS::Keyboard		*mKeyboard;

  OgreBites::InputContext	mInputContext;
  OgreBites::SdkTrayManager*	mTrayMgr;
  std::vector<Worm*>	*listWorms;
  int			*curWorm;
  bool 			*mIsEnd;  

  bool			Interface_Mouse;

  std::thread		*threadJump;

  Menu			*mMenu;
};

#endif /* !INPUTLISTENER_HH_ */
