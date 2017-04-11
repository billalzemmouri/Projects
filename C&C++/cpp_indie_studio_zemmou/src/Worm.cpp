#include <chrono>
#include "Worm.hh"

unsigned int Worm::wormId = 0;

Worm::Worm(Ogre::Vector3 const& position)
{
  this->id = Worm::wormId;
  this->position = position;
  this->entity = 0;
  this->node = 0;
  this->animationState = 0;
  this->gravity = 0;
  this->gravityMtx = 0;
  this->isAlive = true;
  this->life = 100;
  this->mMouvement = Ogre::Vector3::ZERO;
  Worm::wormId += 1;
  this->walkLeft = false;
  this->walkRight = false;
  this->inFall = false;
}

Worm::~Worm()
{
  //this->isAlive = false;
  //this->life = 0;
  /*delete this->animationState;
    delete this->node;
    delete this->entity;*/
  //this->gravity->join();
  delete this->gravity;
  delete this->gravityMtx;
}

unsigned int 	Worm::getId()
{
  return (this->id);
}

void	nodeGravity(Ogre::SceneManager* sceneMgr, Worm *worm)
{
  Ogre::RaySceneQuery* myRaySceneQuery;
  Ogre::Vector3 vect(worm->getNode()->getPosition());

  while (worm->getIsAlive() && worm->getLife() > 0) {
    Ogre::Ray r(worm->getNode()->getPosition(), Ogre::Vector3(0, -1, 0));    
    myRaySceneQuery = sceneMgr->createRayQuery(Ogre::Ray());
    myRaySceneQuery->setRay(r);
    myRaySceneQuery->setSortByDistance(true, 2);
    Ogre::RaySceneQueryResult &res = myRaySceneQuery->execute();    
    Ogre::RaySceneQueryResult::iterator it = res.begin();
    for (it = res.begin(); it < res.end(); it++) {
      if (it->movable && it->movable->getMovableType() == "Entity")
	{
	  Ogre::String str = it->movable->getName();
	  Ogre::Real distance = it->distance;
	  if (str != "Worm" + worm->getId())
	    {
	      if (distance > Ogre::Real(2.3)) {
		worm->setFall(true);
		worm->lockGravityMutex();
		vect = worm->getNode()->getPosition();
		vect.y -= 0.2;
		worm->getNode()->setPosition(vect);
		worm->unlockGravityMutex();
	      }
	      break;
	    }
	}
    }
    worm->setFall(false);
    std::this_thread::sleep_for (std::chrono::milliseconds(10));
  }
  std::cout << "end gravity thread\n";
}

void	Worm::init(Ogre::SceneManager *sceneMgr)
{
  this->entity = sceneMgr->createEntity("Worm" + this->id, "MeshWorms.mesh");
  this->node = sceneMgr->getRootSceneNode()->createChildSceneNode("nodeWorm" + this->id);

  this->node->attachObject(this->entity);
  this->node->setPosition(this->position);

  this->gravityMtx = new std::mutex();
  this->gravity = new std::thread(nodeGravity, sceneMgr, this);
  this->node->setOrientation(Ogre::Quaternion(Ogre::Degree(-90), Ogre::Vector3(0, 1, 0)));

  this->animationState = this->entity->getAnimationState("idle");
  this->animationState->setLoop(true);
  this->animationState->setEnabled(true);
}

bool	Worm::getFall() const {
  return (this->inFall);
}

void	Worm::setFall(bool a)
{
  this->inFall = a;
}

bool			Worm::getWalkRight() const {
  return (this->walkRight);
}

void			Worm::setWalkRight(bool a) {
  this->walkRight = a;
}

bool			Worm::getWalkLeft() const {
  return (this->walkLeft);
}

void			Worm::setWalkLeft(bool a) {
  this->walkLeft = a;
}

Ogre::AnimationState	*Worm::getAnimationState() const
{
  return (this->animationState);
}

void	Worm::idle() {
  this->animationState->setEnabled(false);
  this->animationState->setLoop(false);
  this->node->setOrientation(Ogre::Quaternion(Ogre::Degree(-90), Ogre::Vector3(0, 1, 0)));
  this->animationState = this->entity->getAnimationState("idle");
  this->animationState->setLoop(true);
  this->animationState->setEnabled(true);
}

void 	Worm::walk()
{
  this->animationState->setEnabled(false);
  this->animationState->setLoop(false);
  this->animationState = this->entity->getAnimationState("walk");
  this->animationState->setLoop(true);
  this->animationState->setEnabled(true);
}

void 					Worm::die()
{
  //this->animationState = this->entity->getAnimationState("die");
  //this->animationState->setLoop(true);
  //this->animationState->setEnabled(true);
  this->isAlive = false;
  this->life = 0;
  this->gravity->join();
}

void 					Worm::jump()
{
  this->animationState = this->entity->getAnimationState("jump");
  this->animationState->setLoop(true);
  this->animationState->setEnabled(true);
}

// a utiliser pour proteger le deplacement du worm
void 					Worm::lockGravityMutex()
{
  this->gravityMtx->lock();
}

void 					Worm::unlockGravityMutex()
{
  this->gravityMtx->unlock();
}

void					Worm::setMouvement(Ogre::Vector3 vec) {
  this->mMouvement = vec;
}

Ogre::Vector3				Worm::getMouvement() const {
  return (this->mMouvement);
}

bool					Worm::receiveDamage(unsigned int damages)
{
  if (this->life - damages < 0)
    {
      this->isAlive = false;
      this->life = 0;
      return (false);
    }
  else
    this->life -= damages;
  return (true);
}

bool 					Worm::getIsAlive() const
{
  return (this->isAlive);
}

unsigned int 			Worm::getLife() const
{
  return (this->life);
}

Ogre::SceneNode			*Worm::getNode() const
{
  if (this->node == 0)
    {
      std::cout << "AHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH" << std::endl;
      exit(0);
    }
  return (this->node);
}
