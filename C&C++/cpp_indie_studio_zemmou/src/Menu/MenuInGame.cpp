# include "Menu.hh"

MenuInGame::MenuInGame()
{
}

MenuInGame::~MenuInGame()
{
}

void	MenuInGame::init()
{
  this->wmgr = &CEGUI::WindowManager::getSingleton();
  this->sheet = wmgr->createWindow("DefaultWindow", "CEGUIDemo/Sheet");
  CEGUI::System::getSingleton().getDefaultGUIContext().setRootWindow(sheet);
  CEGUI::System::getSingleton().getDefaultGUIContext().setRootWindow(sheet);

  this->buttonArmes = (CEGUI::PushButton*)wmgr->createWindow("TaharezLook/Button", "ButtonArmes");
  this->txtScore = (CEGUI::DefaultWindow*)wmgr->createWindow("TaharezLook/StaticText", "txtScore");
  this->txtLife = (CEGUI::DefaultWindow*)wmgr->createWindow("TaharezLook/StaticText", "txtLife");
}

CEGUI::PushButton* MenuInGame::getbuttonArmes()
{
  return this->buttonArmes;
}

void MenuInGame::createMenu()
{
  buttonArmes->setPosition(CEGUI::UVector2(CEGUI::UDim( 0.45f, 0.0f), CEGUI::UDim(0.95f, 0.0f)));
  buttonArmes->setSize(CEGUI::USize(CEGUI::UDim(0.1f, 0.0f), CEGUI::UDim(0.05f, 0.0f)));
  buttonArmes->setText("Armes");

  txtLife->setPosition(CEGUI::UVector2(CEGUI::UDim( 0.9f, 0.0f), CEGUI::UDim(0.0f, 0.0f)));
  txtLife->setSize(CEGUI::USize(CEGUI::UDim(0.1f, 0.0f), CEGUI::UDim(0.1f, 0.0f)));
  txtLife->setText("Life : 0");

  txtScore->setPosition(CEGUI::UVector2(CEGUI::UDim( 0.9f, 0.0f), CEGUI::UDim(0.1f, 0.0f)));
  txtScore->setSize(CEGUI::USize(CEGUI::UDim(0.1f, 0.0f), CEGUI::UDim(0.1f, 0.0f)));
  txtScore->setText("Score : 0");
}

void MenuInGame::displayMenu()
{
  this->createMenu();
  sheet->addChild(buttonArmes);
  sheet->addChild(txtLife);
  sheet->addChild(txtScore);
}
