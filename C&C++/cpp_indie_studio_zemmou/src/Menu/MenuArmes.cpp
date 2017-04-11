# include"Menu.hh"

MenuArmes::MenuArmes()
{
}

MenuArmes::~MenuArmes()
{
}

void	MenuArmes::init()
{
  this->wmgr = &CEGUI::WindowManager::getSingleton();
  this->sheet = wmgr->createWindow("DefaultWindow", "CEGUIDemo/Sheet");
  
  CEGUI::System::getSingleton().getDefaultGUIContext().setRootWindow(sheet);
  CEGUI::System::getSingleton().getDefaultGUIContext().setRootWindow(sheet);

  this->MenuBackground = wmgr->createWindow("TaharezLook/StaticImage", "Background");
  this->Title = (CEGUI::Titlebar*)wmgr->createWindow("TaharezLook/Titlebar", "Title");

  this->buttonArme1 = (CEGUI::PushButton*)wmgr->createWindow("TaharezLook/Button", "buttonArme1");
  this->buttonArme2 = (CEGUI::PushButton*)wmgr->createWindow("TaharezLook/Button", "buttonArme2");
  this->buttonArme3 = (CEGUI::PushButton*)wmgr->createWindow("TaharezLook/Button", "buttonArme3");
  this->buttonArme4 = (CEGUI::PushButton*)wmgr->createWindow("TaharezLook/Button", "buttonArme4");
  this->buttonArme5 = (CEGUI::PushButton*)wmgr->createWindow("TaharezLook/Button", "buttonArme5");
  this->buttonArme6 = (CEGUI::PushButton*)wmgr->createWindow("TaharezLook/Button", "buttonArme6");
  this->buttonArme7 = (CEGUI::PushButton*)wmgr->createWindow("TaharezLook/Button", "buttonArme7");
  this->buttonArme8 = (CEGUI::PushButton*)wmgr->createWindow("TaharezLook/Button", "buttonArme8");
  this->buttonArme9 = (CEGUI::PushButton*)wmgr->createWindow("TaharezLook/Button", "buttonArme9");
}

void	MenuArmes::createMenu()
{
  MenuBackground->setPosition( CEGUI::UVector2( CEGUI::UDim( 0.2f, 0.0f ), CEGUI::UDim( 0.2f, 0.0f)));
  MenuBackground->setSize(CEGUI::USize(CEGUI::UDim(0.6f, 0.0f), CEGUI::UDim( 0.6f, 0.0f)));

  Title->setPosition(CEGUI::UVector2(CEGUI::UDim( 0.0f, 0.0f), CEGUI::UDim(0.0f, 0.0f)));
  Title->setSize(CEGUI::USize(CEGUI::UDim(1.0f, 0.0f), CEGUI::UDim(0.1f, 0.0f)));
  Title->setText("Armes");

  buttonArme1->setPosition(CEGUI::UVector2(CEGUI::UDim( 0.0f, 0.0f), CEGUI::UDim(0.2f, 0.0f)));
  buttonArme1->setSize(CEGUI::USize(CEGUI::UDim(0.2f, 0.0f), CEGUI::UDim(0.3f, 0.0f)));
  buttonArme1->setText("Arme 1");

  buttonArme2->setPosition(CEGUI::UVector2(CEGUI::UDim( 0.2f, 0.0f), CEGUI::UDim(0.2f, 0.0f)));
  buttonArme2->setSize(CEGUI::USize(CEGUI::UDim(0.2f, 0.0f), CEGUI::UDim(0.3f, 0.0f)));
  buttonArme2->setText("Arme 2");

  buttonArme3->setPosition(CEGUI::UVector2(CEGUI::UDim( 0.4f, 0.0f), CEGUI::UDim(0.2f, 0.0f)));
  buttonArme3->setSize(CEGUI::USize(CEGUI::UDim(0.2f, 0.0f), CEGUI::UDim(0.3f, 0.0f)));
  buttonArme3->setText("Arme 3");

  buttonArme4->setPosition(CEGUI::UVector2(CEGUI::UDim( 0.4f, 0.0f), CEGUI::UDim(0.3f, 0.0f)));
  buttonArme4->setSize(CEGUI::USize(CEGUI::UDim(0.1f, 0.0f), CEGUI::UDim(0.1f, 0.0f)));
  buttonArme4->setText("Arme 4");

  buttonArme5->setPosition(CEGUI::UVector2(CEGUI::UDim( 0.4f, 0.0f), CEGUI::UDim(0.3f, 0.0f)));
  buttonArme5->setSize(CEGUI::USize(CEGUI::UDim(0.1f, 0.0f), CEGUI::UDim(0.1f, 0.0f)));
  buttonArme5->setText("Arme 5");

  buttonArme6->setPosition(CEGUI::UVector2(CEGUI::UDim( 0.4f, 0.0f), CEGUI::UDim(0.3f, 0.0f)));
  buttonArme6->setSize(CEGUI::USize(CEGUI::UDim(0.1f, 0.0f), CEGUI::UDim(0.1f, 0.0f)));
  buttonArme6->setText("Arme 6");

  buttonArme7->setPosition(CEGUI::UVector2(CEGUI::UDim( 0.4f, 0.0f), CEGUI::UDim(0.3f, 0.0f)));
  buttonArme7->setSize(CEGUI::USize(CEGUI::UDim(0.1f, 0.0f), CEGUI::UDim(0.1f, 0.0f)));
  buttonArme7->setText("Arme 7");

  buttonArme8->setPosition(CEGUI::UVector2(CEGUI::UDim( 0.4f, 0.0f), CEGUI::UDim(0.3f, 0.0f)));
  buttonArme8->setSize(CEGUI::USize(CEGUI::UDim(0.1f, 0.0f), CEGUI::UDim(0.1f, 0.0f)));
  buttonArme8->setText("Arme 8");

  buttonArme9->setPosition(CEGUI::UVector2(CEGUI::UDim( 0.4f, 0.0f), CEGUI::UDim(0.3f, 0.0f)));
  buttonArme9->setSize(CEGUI::USize(CEGUI::UDim(0.1f, 0.0f), CEGUI::UDim(0.1f, 0.0f)));
  buttonArme9->setText("Arme 9");
}

void	MenuArmes::displayMenu()
{
  this->createMenu();

  sheet->addChild(MenuBackground);
  MenuBackground->addChild(Title);

  MenuBackground->addChild(buttonArme1);
  MenuBackground->addChild(buttonArme2);
  MenuBackground->addChild(buttonArme3);
  //  MenuBackground->addChild(buttonArme4);
  //MenuBackground->addChild(buttonArme5);
  //MenuBackground->addChild(buttonArme6);
  //MenuBackground->addChild(buttonArme7);
  //MenuBackground->addChild(buttonArme8);
  //MenuBackground->addChild(buttonArme9);
}
