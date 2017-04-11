#include <sstream>
#include "InputListener.hh"

InputListener::InputListener(Ogre::RenderWindow *window, Ogre::Camera *camera, Ogre::SceneManager *sceneMgr, bool *isEnd,
			     std::vector<Worm*> *listWorms, int *curWorm,Menu *_Menu)
{
  this->mWindow = window;
  this->mCamera = camera;
  this->mSceneMgr = sceneMgr;
  this->startOIS();
  this->mIsEnd = isEnd;
  this->listWorms = listWorms;
  this->curWorm = curWorm;
  this->Interface_Mouse = true;
  this->mMenu = _Menu;
  this->setupCEGUI();

  // display fps  
  this->mInputContext.mKeyboard = this->mKeyboard;
  this->mInputContext.mMouse = this->mMouse;
  this->mTrayMgr = new OgreBites::SdkTrayManager("InterfaceName", this->mWindow, this->mInputContext, this);
  this->mTrayMgr->showFrameStats(OgreBites::TL_BOTTOMRIGHT);
  this->mTrayMgr->toggleAdvancedFrameStats();
} 

void InputListener::setupCEGUI(void)
{
  this->mRenderer = &CEGUI::OgreRenderer::bootstrapSystem();
  CEGUI::ImageManager::setImagesetDefaultResourceGroup("Imagesets");
  CEGUI::Font::setDefaultResourceGroup("Fonts");
  CEGUI::Scheme::setDefaultResourceGroup("Schemes");
  CEGUI::WidgetLookManager::setDefaultResourceGroup("LookNFeel");
  CEGUI::WindowManager::setDefaultResourceGroup("Layouts");
  CEGUI::SchemeManager::getSingleton().createFromFile("TaharezLook.scheme");
  CEGUI::System::getSingleton().getDefaultGUIContext().getMouseCursor().setDefaultImage("TaharezLook/MouseArrow"); 
}

InputListener::~InputListener()
{
  this->mRenderer->destroySystem();
  Ogre::WindowEventUtilities::removeWindowEventListener(mWindow, this);
  this->windowClosed(mWindow);
}

void 	InputListener::startOIS()
{
  Ogre::LogManager::getSingletonPtr()->logMessage("*** Initializing OIS ***");

  OIS::ParamList	pl;
  size_t		windowHnd = 0;
  std::ostringstream	windowHndStr;

  mWindow->getCustomAttribute("WINDOW", &windowHnd);
  windowHndStr << windowHnd;
  pl.insert(std::make_pair(std::string("WINDOW"), windowHndStr.str()));

  mInputMgr = OIS::InputManager::createInputSystem(pl);

  mMouse = static_cast<OIS::Mouse *>(mInputMgr->createInputObject(OIS::OISMouse, true));
  mKeyboard = static_cast<OIS::Keyboard *>(mInputMgr->createInputObject(OIS::OISKeyboard, true));

  mMouse->setEventCallback(this);
  mKeyboard->setEventCallback(this);

  windowResized(mWindow);

  Ogre::WindowEventUtilities::addWindowEventListener(mWindow, this);
}

bool 		InputListener::frameRenderingQueued(const Ogre::FrameEvent &evt)
{
  if (*mIsEnd || mWindow->isClosed())
    return (false);

  mKeyboard->capture();
  mMouse->capture();
  
  Worm *w = (*this->listWorms)[(*this->curWorm)];
  Ogre::Vector3 deplacement = w->getMouvement();
  Ogre::Vector3 pos = w->getNode()->getPosition();
  w->getNode()->setPosition(deplacement + pos);
  
  //CEGUI
  CEGUI::System::getSingleton().injectTimePulse(evt.timeSinceLastFrame);
  //CEGUI

  this-mTrayMgr->frameRenderingQueued(evt);
  //enable animation of the game here
  for (int i = 0; i < this->listWorms->size(); ++i) {
    (*this->listWorms)[i]->getAnimationState()->addTime(evt.timeSinceLastFrame);
  }

  if(mMenu->getExit() == true)
    {
      for (int i = 0; i < this->listWorms->size(); i++)
        (*this->listWorms)[i]->die();
      *mIsEnd = true;
    }
  return (true);
}

void		InputListener::setDeplacementWorm(const OIS::KeyEvent &arg) {
  Worm	*curWorm;
  Ogre::Vector3	vect = Ogre::Vector3::ZERO;
  
  curWorm = (*this->listWorms)[(*this->curWorm)];
  switch (arg.key) {
  case OIS::KC_D:
    if (!curWorm->getWalkLeft()) {
      curWorm->getNode()->setOrientation(Ogre::Quaternion(Ogre::Degree(0), Ogre::Vector3(0, 1, 0)));
      vect = curWorm->getMouvement();
      vect.x = vect.x + 0.200;
      curWorm = (*this->listWorms)[(*this->curWorm)];
      curWorm->walk(); 
      curWorm->setMouvement(vect);
      curWorm->setWalkRight(true);
      //std::cout << vect << "\n";
    }
    break;
  case OIS::KC_Q:
    if (!curWorm->getWalkRight()) {
      curWorm->getNode()->setOrientation(Ogre::Quaternion(Ogre::Degree(180), Ogre::Vector3(0, 1, 0)));
      curWorm->walk();
      vect = curWorm->getMouvement();
      vect.x = vect.x - 0.200;
      //std::cout << vect << "\n";
      curWorm->setMouvement(vect);
      curWorm->setWalkLeft(true);
    }
    break;
  case OIS::KC_SPACE:
    if (!curWorm->getFall()) {
      curWorm->jump();
      vect = curWorm->getMouvement();
      vect.y = vect.y + 1.5;
      //std::cout << vect << "\n";
      curWorm->setMouvement(vect);
    }
    break;
  }
}

bool 		InputListener::keyPressed(const OIS::KeyEvent &arg)
{
  //  std::cout << "Press : " << arg.key << std::endl;
  if (arg.key == OIS::KC_LCONTROL)
    {
      this->changeMouse();
    }
  
  /*CEGUI
  else if (Interface_Mouse == true)
    {
      CEGUI::GUIContext& context = CEGUI::System::getSingleton().getDefaultGUIContext();
      context.injectKeyDown((CEGUI::Key::Scan)arg.key);
      context.injectChar((CEGUI::Key::Scan)arg.text);
      return true;
    }
    else
  {
  CEGUI */
  
  if (arg.key == OIS::KC_ESCAPE)
    {
      this->pressESCAPE();
      //      *mIsEnd = true;
      std::cerr << "Echap Press\n";
    }
  this->setDeplacementWorm(arg);
  return true;
}

bool 		InputListener::keyReleased(const OIS::KeyEvent &arg)
{
  Ogre::Vector3 vect = Ogre::Vector3::ZERO;
  Worm	*curWorm;

  /* CEGUI 
  if(Interface_Mouse == true)
    {
      CEGUI::System::getSingleton().getDefaultGUIContext().injectKeyUp((CEGUI::Key::Scan)arg.key);
      return true;
    }
  else
    {
  CEGUI */

  curWorm = (*this->listWorms)[(*this->curWorm)];
  //  std::cerr << "Realease : " << arg.key << std::endl;
  switch (arg.key) {
  case OIS::KC_D:
    if (!curWorm->getWalkLeft() && curWorm->getWalkRight()) {
      curWorm->idle();
      vect = curWorm->getMouvement();
      vect.x = vect.x - 0.200;
      //  std::cout << vect << "\n";
      curWorm->setMouvement(vect);
      curWorm->setWalkRight(false);
    }
    break;
  case OIS::KC_Q:
    if (!curWorm->getWalkRight() && curWorm->getWalkLeft()) {
      curWorm->idle();
      vect = curWorm->getMouvement();
      vect.x = vect.x + 0.200;
      //std::cout << vect << "\n";
      curWorm->setMouvement(vect);
      curWorm->setWalkLeft(false);
    }
    break;
  case OIS::KC_SPACE:
    if (!curWorm->getWalkRight() && !curWorm->getWalkLeft())
      curWorm->idle();
    if (!curWorm->getFall()) {
      vect = curWorm->getMouvement();
      vect.y = vect.y - 1.5;
      //std::cout << vect << "\n";
      curWorm->setMouvement(vect);
    }
    break;
  }
  return true;
}


OIS::Mouse	*InputListener::getMouse() const {
  return (this->mMouse);
}

OIS::Keyboard *InputListener::getKeyboard() const {
  return (this->mKeyboard);
}

void	InputListener::changeMouse(void)
{
  if (Interface_Mouse == true)
    Interface_Mouse = false;
  else
    Interface_Mouse = true;
}

CEGUI::MouseButton	convertButton(OIS::MouseButtonID buttonID)
{
  switch (buttonID)
    {
    case OIS::MB_Left:
      return CEGUI::LeftButton;
 
    case OIS::MB_Right:
      return CEGUI::RightButton;
 
    case OIS::MB_Middle:
      return CEGUI::MiddleButton;
 
    default:
      return CEGUI::LeftButton;
    }
}

bool 		InputListener::mouseMoved(const OIS::MouseEvent & arg)
{
  if (Interface_Mouse == false)
    { 
      if (mTrayMgr->injectMouseMove(arg))
	return true;
    }
  else
    {
      CEGUI::System &sys = CEGUI::System::getSingleton();
      sys.getDefaultGUIContext().injectMouseMove(arg.state.X.rel, arg.state.Y.rel);
      if (arg.state.Z.rel)
	sys.getDefaultGUIContext().injectMouseWheelChange(arg.state.Z.rel / 120.0f);
      return true;
    }
}

bool 		InputListener::mousePressed(const OIS::MouseEvent & arg, OIS::MouseButtonID id)
{
  if (Interface_Mouse == false)
    {
      if (mTrayMgr->injectMouseDown(arg, id))
	return true;
    }
  else
    {
      CEGUI::System::getSingleton().getDefaultGUIContext().injectMouseButtonDown(convertButton(id));
      return true;
    }
}

bool 		InputListener::mouseReleased(const OIS::MouseEvent & arg, OIS::MouseButtonID id)
{
  if (Interface_Mouse == false)
    {
      if (mTrayMgr->injectMouseUp(arg, id))
	return true;
    }
  else
    {
      CEGUI::System::getSingleton().getDefaultGUIContext().injectMouseButtonUp(convertButton(id));
      return true;
    }
}

void 		InputListener::windowResized(Ogre::RenderWindow *rw)
{
  unsigned int 	width, height, depth;
  int 			left, top;

  rw->getMetrics(width, height, depth, left, top);

  const OIS::MouseState &ms = mMouse->getMouseState();
  ms.width = width;
  ms.height = height;
}

void 		InputListener::windowClosed(Ogre::RenderWindow *rw)
{
  if (rw == mWindow)
    {
      if (mInputMgr)
	{
	  mInputMgr->destroyInputObject(mMouse);
	  mInputMgr->destroyInputObject(mKeyboard);

	  OIS::InputManager::destroyInputSystem(mInputMgr);
	  mInputMgr = 0;
	}
    }
}

void		InputListener::pressESCAPE()
{
  this->mMenu->escapeMenu();

}
