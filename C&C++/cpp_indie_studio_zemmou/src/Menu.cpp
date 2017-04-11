#include "Menu.hh"

Menu::Menu()
{
  mMenuParameter = new MenuParameter;
  mMenuInGame = new MenuInGame;
  mMenuArmes = new MenuArmes;
  mMenuESCAPE = new MenuESCAPE;
  Exit = false;
}

Menu::~Menu()
{

}

bool		Menu::getExit()
{
  return this->Exit;
}

void	Menu::pushExit()
{
  this->Exit = true;
}

void		Menu::configureGame()
{
  mMenuParameter->init();
  mMenuParameter->displayMenu();
  mMenuParameter->getbuttonBack()->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&Menu::startMenu,this));
  mMenuParameter->getbuttonPlay()->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&Menu::startMenuGame,this));
}

void		Menu::startMenuGame()
{
  mMenuParameter->hide();
  mMenuInGame->init();
  mMenuInGame->displayMenu();
  mMenuInGame->getbuttonArmes()->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&Menu::armesMenu,this));
}

void		Menu::armesMenu()
{
  mMenuArmes->init();
  mMenuArmes->displayMenu();
}

void		Menu::escapeMenu()
{
  mMenuESCAPE->init();
  mMenuESCAPE->displayMenu();
  mMenuESCAPE->getbuttonExit()->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&Menu::pushExit,this));
  mMenuESCAPE->getbuttonReturnMenu()->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&Menu::startMenu,this));
}

void		Menu::startMenu()
{
  CEGUI::WindowManager &wmgr = CEGUI::WindowManager::getSingleton();
  CEGUI::Window *sheet = wmgr.createWindow("DefaultWindow", "CEGUIDemo/Sheet");
  CEGUI::System::getSingleton().getDefaultGUIContext().setRootWindow(sheet);                                                                                                              
  CEGUI::Window *MenuBackground = wmgr.createWindow("TaharezLook/StaticImage", "Background");
  MenuBackground->setPosition( CEGUI::UVector2( CEGUI::UDim( 0.0f, 0.0f ), CEGUI::UDim( 0.0f, 0.0f)));
  MenuBackground->setSize(CEGUI::USize(CEGUI::UDim(1.0f, 0.0f), CEGUI::UDim( 1.0f, 0.0f)));
  MenuBackground->setProperty("BackgroundColours", "tl:00000000 tr:FFFFFFFF bl:FFFFFFFF br:FFFFFFFF"); 

  CEGUI::PushButton* NewGame= (CEGUI::PushButton*)wmgr.createWindow("TaharezLook/Button", "Newgame");
  NewGame->setPosition(CEGUI::UVector2(CEGUI::UDim(0.3f, 0.0f), CEGUI::UDim(0.2f, 0.0f)));
  NewGame->setSize(CEGUI::USize(CEGUI::UDim(0.4f, 0.0f), CEGUI::UDim(0.2f, 0.0f)));
  NewGame->setText("New Game");
  NewGame->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&Menu::configureGame, this));
  
  CEGUI::PushButton* QuitGame= (CEGUI::PushButton*)wmgr.createWindow("TaharezLook/Button", "QuitGame");
  QuitGame->setPosition(CEGUI::UVector2(CEGUI::UDim(0.3f, 0.0f), CEGUI::UDim(0.45f, 0.0f)));
  QuitGame->setSize(CEGUI::USize(CEGUI::UDim(0.4f, 0.0f), CEGUI::UDim(0.2f, 0.0f)));
  QuitGame->setText("Exit");
  QuitGame->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&Menu::pushExit,this));
 
  sheet->addChild(MenuBackground);
  MenuBackground->addChild(NewGame);
  MenuBackground->addChild(QuitGame);
}



bool	Menu::showStartMenu(Ogre::SceneManager *sceneMgr)
{
  startMenu();

  // tant que l'utilisateur n'a pas cliqué sur play
  // return true si user clic play et false si il quitte
  return (true);
}
