# include "Menu.hh"

MenuParameter::MenuParameter()
{ 
  this->nbPlayer = 2;
  this->nbTeam = 2;
}


MenuParameter::~MenuParameter()
{
}

void	MenuParameter::init()
{
  this->wmgr = &CEGUI::WindowManager::getSingleton(); 
  this->sheet = wmgr->createWindow("DefaultWindow", "CEGUIDemo/Sheet");

  CEGUI::System::getSingleton().getDefaultGUIContext().setRootWindow(sheet);
  CEGUI::System::getSingleton().getDefaultGUIContext().setRootWindow(sheet);

  this->MenuBackground = wmgr->createWindow("TaharezLook/StaticImage", "Background");
  this->Title = (CEGUI::Titlebar*)wmgr->createWindow("TaharezLook/Titlebar", "Title");

  this->buttonPlay = (CEGUI::PushButton*)wmgr->createWindow("TaharezLook/Button", "ButtonPlay");
  this->buttonBack = (CEGUI::PushButton*)wmgr->createWindow("TaharezLook/Button", "ButtonBack");

  this->txtPlayer = (CEGUI::DefaultWindow*)wmgr->createWindow("TaharezLook/StaticText", "txtPlayer");
  this->addPlayer = (CEGUI::PushButton*)wmgr->createWindow("TaharezLook/Button", "addPlayer");
  this->removePlayer = (CEGUI::PushButton*)wmgr->createWindow("TaharezLook/Button", "removePlayer");
  
  this->txtTeam = (CEGUI::DefaultWindow*)wmgr->createWindow("TaharezLook/StaticText", "txtTeam");
  this->addTeam = (CEGUI::PushButton*)wmgr->createWindow("TaharezLook/Button", "addTeam");
  this->removeTeam = (CEGUI::PushButton*)wmgr->createWindow("TaharezLook/Button", "removeTeam");
 
  this->createMenu();
}

void	MenuParameter::hide()
{
  sheet->hide();
}

void	MenuParameter::add_Player()
{
  char	buff[20];
  unsigned int  N;
  
  nbPlayer += 1;
  sprintf(buff,"%d players",nbPlayer);
  txtPlayer->setText(buff);
}

void	MenuParameter::remove_Player()
{  
  char	buff[20];
  
  if (nbPlayer != 2) 
    { 
      nbPlayer -= 1;
      sprintf(buff,"%d players",nbPlayer);
      txtPlayer->setText(buff);
    }
}

void	MenuParameter::add_Team()
{
  char	buff[20];
  
  nbTeam += 1;
  sprintf(buff,"%d teams",nbTeam);
  txtTeam->setText(buff);
}

void	MenuParameter::remove_Team()
{  
  char	buff[20];
  unsigned int  N;
  
  if (nbTeam != 2) 
    { 
      nbTeam -= 1;
      sprintf(buff,"%d teams",nbTeam);
      txtTeam->setText(buff);
    }
}

CEGUI::PushButton* MenuParameter::getbuttonPlay()
{
  return this->buttonPlay;
}


CEGUI::PushButton* MenuParameter::getbuttonBack()
{
  return this->buttonBack;
}

void	MenuParameter::createMenu()
{
  char	buff[20]; 

  MenuBackground->setPosition( CEGUI::UVector2( CEGUI::UDim( 0.0f, 0.0f ), CEGUI::UDim( 0.0f, 0.0f)));
  MenuBackground->setSize(CEGUI::USize(CEGUI::UDim(1.0f, 0.0f), CEGUI::UDim( 1.0f, 0.0f)));

  Title->setPosition(CEGUI::UVector2(CEGUI::UDim( 0.0f, 0.0f), CEGUI::UDim(0.0f, 0.0f)));
  Title->setSize(CEGUI::USize(CEGUI::UDim(1.0f, 0.0f), CEGUI::UDim(0.1f, 0.0f)));
  Title->setText("Parameter");

  buttonPlay->setPosition(CEGUI::UVector2(CEGUI::UDim( 0.7f, 0.0f), CEGUI::UDim(0.7f, 0.0f)));
  buttonPlay->setSize(CEGUI::USize(CEGUI::UDim(0.2f, 0.0f), CEGUI::UDim(0.2f, 0.0f)));
  buttonPlay->setText("Play");

  buttonBack->setPosition(CEGUI::UVector2(CEGUI::UDim( 0.0f, 0.0f), CEGUI::UDim(0.1f, 0.0f)));
  buttonBack->setSize(CEGUI::USize(CEGUI::UDim(0.1f, 0.0f), CEGUI::UDim(0.1f, 0.0f)));
  buttonBack->setText("Back");

  txtPlayer->setPosition(CEGUI::UVector2(CEGUI::UDim( 0.0f, 0.0f), CEGUI::UDim(0.3f, 0.0f)));
  txtPlayer->setSize(CEGUI::USize(CEGUI::UDim(0.1f, 0.0f), CEGUI::UDim(0.1f, 0.0f)));
  sprintf(buff, "%d players",nbPlayer);
  txtPlayer->setText(buff);

  addPlayer->setPosition(CEGUI::UVector2(CEGUI::UDim( 0.3f, 0.0f), CEGUI::UDim(0.3f, 0.0f)));
  addPlayer->setSize(CEGUI::USize(CEGUI::UDim(0.1f, 0.0f), CEGUI::UDim(0.1f, 0.0f)));
  addPlayer->setText("+");
  addPlayer->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&MenuParameter::add_Player, this));
  
  removePlayer->setPosition(CEGUI::UVector2(CEGUI::UDim( 0.4f, 0.0f), CEGUI::UDim(0.3f, 0.0f)));
  removePlayer->setSize(CEGUI::USize(CEGUI::UDim(0.1f, 0.0f), CEGUI::UDim(0.1f, 0.0f)));
  removePlayer->setText("-");
  removePlayer->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&MenuParameter::remove_Player, this));

  txtTeam->setPosition(CEGUI::UVector2(CEGUI::UDim( 0.0f, 0.0f), CEGUI::UDim(0.4f, 0.0f)));
  txtTeam->setSize(CEGUI::USize(CEGUI::UDim(0.1f, 0.0f), CEGUI::UDim(0.1f, 0.0f)));
  sprintf(buff, "%d teams",nbTeam);
  txtTeam->setText(buff);

  addTeam->setPosition(CEGUI::UVector2(CEGUI::UDim( 0.3f, 0.0f), CEGUI::UDim(0.4f, 0.0f)));
  addTeam->setSize(CEGUI::USize(CEGUI::UDim(0.1f, 0.0f), CEGUI::UDim(0.1f, 0.0f)));
  addTeam->setText("+");
  addTeam->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&MenuParameter::add_Team, this));
  
  removeTeam->setPosition(CEGUI::UVector2(CEGUI::UDim( 0.4f, 0.0f), CEGUI::UDim(0.4f, 0.0f)));
  removeTeam->setSize(CEGUI::USize(CEGUI::UDim(0.1f, 0.0f), CEGUI::UDim(0.1f, 0.0f)));
  removeTeam->setText("-");
  removeTeam->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&MenuParameter::remove_Team, this));
}

void	MenuParameter::displayMenu()
{
  sheet->addChild(MenuBackground);
  MenuBackground->addChild(Title);

  MenuBackground->addChild(buttonPlay);
  MenuBackground->addChild(buttonBack); 
 
  MenuBackground->addChild(addPlayer);
  MenuBackground->addChild(removePlayer);
  MenuBackground->addChild(txtPlayer);
  
  MenuBackground->addChild(addTeam);
  MenuBackground->addChild(removeTeam);
  MenuBackground->addChild(txtTeam);
}
