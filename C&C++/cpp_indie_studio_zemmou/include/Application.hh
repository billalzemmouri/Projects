#ifndef APPLICATION_HH_
# define APPLICATION_HH_
# include <Ogre.h>
# include <string>
# include <SdkTrays.h>
# include <SdkCameraMan.h>
# include "Menu.hh"
# include "InputListener.hh"

class Application
{
public:
  Application();
  ~Application();
  bool			start();
private:
  Ogre::Root		*mRoot;
  Ogre::RenderWindow	*mWindow;
  Ogre::SceneManager	*mSceneMgr;
  Ogre::Camera 		*mCamera;
  InputListener 	*mInputListener;
  bool	 		mIsEnd;
  Menu 			*menu;
  std::vector<Worm *>	listWorms;
  int			curWorm;

  Ogre::OverlaySystem*		mOverlaySystem;
  
  bool 		init();
  void		setupResources();
  bool		configure(const std::string &appName);
  bool 		game();
  bool 		createScene();
  void		createFrameListener();
  void		createMap();
  void		createViewPort();
  void		setCamera(const Ogre::Real &oX, const Ogre::Real &oY, const Ogre::Real &oZ,const Ogre::Real &dX,const Ogre::Real &dY
    , const Ogre::Real &dZ, const Ogre::Real &clipDist);
};

#endif /* !APPLICATION_HH_ */
