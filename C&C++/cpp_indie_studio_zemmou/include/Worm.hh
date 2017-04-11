#ifndef WORM_HH_
# define WORM_HH_
# include <OgreSceneManager.h>
# include <OgreEntity.h>
# include <OgreVector3.h>
# include <thread>
# include <mutex>

class Worm
{
public:
  Worm(Ogre::Vector3 const&);
  ~Worm();
  void			init(Ogre::SceneManager *);
  Ogre::AnimationState	*getAnimationState() const;
  void 			walk();
  void 		       	die();
  void 			jump();
  void 			lockGravityMutex();
  void 			unlockGravityMutex();
  bool 			receiveDamage(unsigned int);
  void			idle();
  unsigned int 		getId();
  bool 			getIsAlive() const;
  unsigned int 		getLife() const;
  Ogre::SceneNode	*getNode() const;
  void			setMouvement(Ogre::Vector3 vec);
  Ogre::Vector3		getMouvement() const;
  bool			getFall() const;
  void			setFall(bool a);
  bool			getWalkRight() const;
  void			setWalkRight(bool a);
  bool			getWalkLeft() const;
  void			setWalkLeft(bool a);
private:
  Ogre::Entity		*entity;
  Ogre::SceneNode	*node;
  Ogre::AnimationState	*animationState;
  Ogre::Vector3 	position;
  Ogre::Vector3		mMouvement;
  Ogre::Real		mSpeed;

  bool 			isAlive;
  unsigned int 		life;
  bool			inFall;
  bool			walkRight;
  bool			walkLeft;
  
  std::thread		*gravity;
  std::mutex		*gravityMtx;

  static unsigned int 	wormId;
  unsigned int 		id;
	
};

#endif /* !WORM_HH_ */
