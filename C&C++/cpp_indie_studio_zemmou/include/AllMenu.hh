
class MenuParameter : public Menu
{
public:
  MenuParameter();
  ~MenuParameter();
  void  add_Player();
  void  remove_Player();
  void  startMenuBack();
  void  Play();
  void  createMenu();
  void  displayMenu();
protected:
  CEGUI::Window *sheet;
  CEGUI::Window *MenuBackground;
  CEGUI::Titlebar* Title;

  CEGUI::PushButton* buttonPlay;
  CEGUI::PushButton* buttonBack;

  CEGUI::DefaultWindow* txtPlayer;
  CEGUI::PushButton* addPlayer;
  CEGUI::PushButton* removePlayer;

  CEGUI::DefaultWindow* txtTeam;
  CEGUI::PushButton* addTeam;
  CEGUI::PushButton* removeTeam;
};

class MenuInGame : public Menu
{
public:
  MenuInGame();
  ~MenuInGame();
  void  createMenu();
  void  displayMenu();
protected:
  CEGUI::Window *sheet;
  CEGUI::DefaultWindow* txtLife;
  CEGUI::DefaultWindow* txtScore;
  CEGUI::PushButton* buttonArmes;
};

class AllMenu
{
public:
  AllMenu();
  ~AllMenu();
protected:
  MenuParameter mMenuParameter;
  MenuInGame	mMenuInGame;
};
