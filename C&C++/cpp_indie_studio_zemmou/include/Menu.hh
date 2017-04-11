# ifndef MENU_HH_
# define MENU_HH_
# include <OgreSceneManager.h>
# include <CEGUI/CEGUI.h>
# include <Renderer.h>

class MenuParameter
{
public: 
  MenuParameter();
  ~MenuParameter();  
  void			init();
  void			add_Player();
  void			remove_Player();
  void			add_Team();
  void			remove_Team();
  CEGUI::PushButton*	getbuttonBack();
  CEGUI::PushButton*	getbuttonPlay();
  void			hide();
  void			createMenu();
  void			displayMenu();
  unsigned int		getNbTeam() const;
  unsigned int		getNbPlayer() const;
  void			setNbTeam(unsigned int _NbTeam);
  void			setNbPlayer(unsigned int _NbPlayer);

protected:
  CEGUI::WindowManager*	wmgr;
  CEGUI::Window*	sheet;
  CEGUI::Window*	MenuBackground;
  CEGUI::Titlebar*	Title;

  CEGUI::PushButton*	buttonPlay;
  CEGUI::PushButton*	buttonBack;

  CEGUI::DefaultWindow* txtPlayer;
  CEGUI::PushButton*	addPlayer;
  CEGUI::PushButton*	removePlayer;

  CEGUI::DefaultWindow* txtTeam;
  CEGUI::PushButton*	addTeam;
  CEGUI::PushButton*	removeTeam;

  unsigned int		nbPlayer;
  unsigned int		nbTeam;
};

class MenuArmes
{
public:
  MenuArmes();
  ~MenuArmes();
  void	init();
  void  createMenu();
  void  displayMenu();
protected:
  CEGUI::WindowManager*	wmgr;
  CEGUI::Window*	sheet;
  CEGUI::Window*	MenuBackground;
  CEGUI::Titlebar*	Title;
  
  CEGUI::PushButton*	buttonArme1;
  CEGUI::PushButton*	buttonArme2;
  CEGUI::PushButton*	buttonArme3;
  CEGUI::PushButton*	buttonArme4;
  CEGUI::PushButton*	buttonArme5;
  CEGUI::PushButton*	buttonArme6;
  CEGUI::PushButton*	buttonArme7;
  CEGUI::PushButton*	buttonArme8;
  CEGUI::PushButton*	buttonArme9;
};

class MenuInGame
{
public:
  MenuInGame();
  ~MenuInGame();
  void			init();
  void			createMenu();
  void			displayMenu();
  CEGUI::PushButton*	getbuttonArmes();
protected:
  CEGUI::WindowManager*	wmgr;
  CEGUI::Window*	sheet;
  CEGUI::DefaultWindow* txtLife;
  CEGUI::DefaultWindow* txtScore;
  CEGUI::PushButton*	buttonArmes;
};

class MenuESCAPE
{
public:
  MenuESCAPE();
  ~MenuESCAPE();
  void			init();
  void			hide();
  CEGUI::PushButton*	getbuttonReturnMenu();
  CEGUI::PushButton*	getbuttonExit();
  void			createMenu();
  void			displayMenu();
protected:
  CEGUI::WindowManager*	wmgr;
  CEGUI::Window*	sheet;
  CEGUI::Window*	MenuBackground;
 
  CEGUI::PushButton*	buttonResume;
  CEGUI::PushButton*	buttonReturnMenu;
  CEGUI::PushButton*	buttonExit;
};

class Menu 
{
public:
  Menu();
  ~Menu();
  bool			showStartMenu(Ogre::SceneManager *);
  void			configureGame();
  void			armesMenu();
  void			startMenu();
  void			startMenuGame();
  void			escapeMenu();
  bool			getExit();
  void			pushExit();
protected:
  MenuParameter*	mMenuParameter;
  MenuInGame*		mMenuInGame;
  MenuArmes*		mMenuArmes;
  MenuESCAPE*		mMenuESCAPE;
  bool			Exit;
};

#endif /* !MENU_HH_ */
