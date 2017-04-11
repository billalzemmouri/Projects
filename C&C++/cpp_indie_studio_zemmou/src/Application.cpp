#include <iostream>
#include "Application.hh"
#include "MyLight.hh"
#include "Worm.hh"

Application::Application() : mRoot(0), mWindow(0), mSceneMgr(0), mCamera(0)
{
  mIsEnd = false;
  this->curWorm = 0;
}

Application::~Application()
{
  //delete listWorms;
  delete mInputListener;
  delete mRoot;
}

bool 	Application::init()
{
  mRoot = new Ogre::Root("plugins.cfg", "ogre.cfg", "Ogre.log");
  
  this->setupResources();

  if (!configure("Worms"))
    {
      std::cerr << "fail configure\n";
      return false;
    }

  mSceneMgr = mRoot->createSceneManager("DefaultSceneManager", "WormSceneMgr");
  mCamera = mSceneMgr->createCamera("PlayerCam");

  mOverlaySystem = new Ogre::OverlaySystem();
  mSceneMgr->addRenderQueueListener(mOverlaySystem);
  
  Ogre::TextureManager::getSingleton().setDefaultNumMipmaps(5);

  Ogre::ResourceGroupManager::getSingleton().initialiseAllResourceGroups();
  return (true);
}

void	Application::setupResources()
{
  Ogre::ConfigFile confile;
  confile.load("resources.cfg");

  Ogre::ConfigFile::SectionIterator	seci = confile.getSectionIterator();

  Ogre::String 	secName, typeName, archName;

  while (seci.hasMoreElements())
    {
      secName = seci.peekNextKey();
      Ogre::ConfigFile::SettingsMultiMap 	*settings = seci.getNext();
      Ogre::ConfigFile::SettingsMultiMap::iterator 	i;
      for (i = settings->begin(); i != settings->end(); ++i)
	{
	  typeName = i->first;
	  archName = i->second;
	  Ogre::ResourceGroupManager::getSingleton().addResourceLocation(
									 archName, typeName, secName);
	}
    }
}

bool	Application::configure(const std::string &appName)
{
  // showConfigDialog return true if OK is press
  if (mRoot->restoreConfig() && mRoot->showConfigDialog()) {
    mWindow = mRoot->initialise(true, appName);
    return true;
  } else {
    std::cerr << "showConfigDialog fail\n";
    return false;
  }
}

void	Application::createViewPort() {
  Ogre::Viewport *vue = mWindow->addViewport(mCamera);

  mCamera->setAspectRatio(Ogre::Real(vue->getActualWidth()) / Ogre::Real(vue->getActualHeight()));
  vue->setBackgroundColour(Ogre::ColourValue(0.0, 0.0, 0.0));
}

void	Application::setCamera(const Ogre::Real &oX, const Ogre::Real &oY, const Ogre::Real &oZ,const Ogre::Real &dX,const Ogre::Real &dY
			       , const Ogre::Real &dZ, const Ogre::Real &clipDist) {
  this->mCamera->setPosition(Ogre::Vector3(oX, oY, oZ));
  this->mCamera->lookAt(Ogre::Vector3(dX, dY, dZ));
  this->mCamera->setNearClipDistance(clipDist);
}

void	Application::createMap() {
  int toto = 0;
  //mSceneMgr->setSkyBox(true, "Examples/EveningSkyBox"); //ciel fixe
  mSceneMgr->setSkyDome(true, "Examples/CloudySky", 2, 10.0); // ciel en forme de dome qui bouge =)
  for (int j = 0; j < 25; j++) {
    for (int i = -10; i < 180; i++) {
      if ((i < 20 || i > 25) || (i >= 20 && i <= 25 && (j > 10 || j < 0))) {
	if (i <= 40 + toto || i >= 80 - toto) {
	Ogre::Entity *entity = mSceneMgr->createEntity("cube" + std::to_string(i) + "/" + std::to_string(j), "Cube.mesh");
	Ogre::SceneNode *node = mSceneMgr->getRootSceneNode()->createChildSceneNode("nodeCube" + std::to_string(i) + "/"  + std::to_string(j));
	node->setPosition(i, -j, 0);
	node->attachObject(entity);
	}
      }
    }
    toto++;
  }
}

bool 		Application::createScene()
{
  //init the game, obj placement, create scene etc ...
  putLight(mSceneMgr);

  this->createMap();

  this->createViewPort();

  this->setCamera(50, 10, 80, 50, 10, 0, 5);

  for (int i = 0; i < 12; i++) {
    Worm *w;
    w = new Worm(Ogre::Vector3(10 + (i * 10), 5, 0));
    w->init(mSceneMgr);
    this->listWorms.push_back(w);
  }
  this->curWorm = 1;
}

void		Application::createFrameListener()
{
  menu = new Menu();
  mInputListener = new InputListener(mWindow, mCamera, mSceneMgr, &mIsEnd, &this->listWorms, &this->curWorm,this->menu);
  mRoot->addFrameListener(mInputListener);

}

bool 		Application::game()
{
  // game loop
  while (!mIsEnd)
    {
      Ogre::WindowEventUtilities::messagePump();
      
      if (mWindow->isClosed() || !mRoot->renderOneFrame())
	{
	  mIsEnd = true;
	}
    }
  return (true);
}

bool 	Application::start()
{
  if(!this->init())
    {
      std::cerr << "fail init\n";
      return (false);
    }

  this->createScene();

  this->createFrameListener();

  this->menu->showStartMenu(this->mSceneMgr);

  this->game();

  return (true);
}
