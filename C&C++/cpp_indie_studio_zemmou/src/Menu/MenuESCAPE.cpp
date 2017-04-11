# include"Menu.hh"

MenuESCAPE::MenuESCAPE()
{
}

MenuESCAPE::~MenuESCAPE()
{
}

void			MenuESCAPE::hide()
{
  this->sheet->hide();
}

void			MenuESCAPE::init()
{
  this->wmgr = &CEGUI::WindowManager::getSingleton();
  this->sheet = wmgr->createWindow("DefaultWindow", "CEGUIDemo/Sheet");
  
  CEGUI::System::getSingleton().getDefaultGUIContext().setRootWindow(sheet);
  CEGUI::System::getSingleton().getDefaultGUIContext().setRootWindow(sheet);

  this->MenuBackground = wmgr->createWindow("TaharezLook/StaticImage", "Background");

  this->buttonResume = (CEGUI::PushButton*)wmgr->createWindow("TaharezLook/Button", "buttonResume");
  this->buttonReturnMenu = (CEGUI::PushButton*)wmgr->createWindow("TaharezLook/Button", "buttonReturnMenu");
  this->buttonExit = (CEGUI::PushButton*)wmgr->createWindow("TaharezLook/Button", "buttonExit");
}

CEGUI::PushButton*	MenuESCAPE::getbuttonReturnMenu()
{
  return this->buttonReturnMenu;
}

CEGUI::PushButton*	MenuESCAPE::getbuttonExit()
{
  return this->buttonExit;
}

void			MenuESCAPE::createMenu()
{
  MenuBackground->setPosition( CEGUI::UVector2( CEGUI::UDim( 0.3f, 0.0f ), CEGUI::UDim( 0.2f, 0.0f)));
  MenuBackground->setSize(CEGUI::USize(CEGUI::UDim(0.4f, 0.0f), CEGUI::UDim( 0.6f, 0.0f)));

  buttonResume->setPosition(CEGUI::UVector2(CEGUI::UDim( 0.05f, 0.0f), CEGUI::UDim(0.05f, 0.0f)));
  buttonResume->setSize(CEGUI::USize(CEGUI::UDim(0.9f, 0.0f), CEGUI::UDim(0.3f, 0.0f)));
  buttonResume->setText("Resume");
  buttonResume->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&MenuESCAPE::hide,this));

  buttonReturnMenu->setPosition(CEGUI::UVector2(CEGUI::UDim( 0.05f, 0.0f), CEGUI::UDim(0.45f, 0.0f)));
  buttonReturnMenu->setSize(CEGUI::USize(CEGUI::UDim(0.9f, 0.0f), CEGUI::UDim(0.2f, 0.0f)));
  buttonReturnMenu->setText("Return Menu");

  buttonExit->setPosition(CEGUI::UVector2(CEGUI::UDim( 0.05f, 0.0f), CEGUI::UDim(0.75f, 0.0f)));
  buttonExit->setSize(CEGUI::USize(CEGUI::UDim(0.9f, 0.0f), CEGUI::UDim(0.2f, 0.0f)));
  buttonExit->setText("Exit");
}

void			MenuESCAPE::displayMenu()
{
  this->createMenu();

  sheet->addChild(MenuBackground);
  MenuBackground->addChild(buttonResume);
  MenuBackground->addChild(buttonReturnMenu);
  MenuBackground->addChild(buttonExit);
}
