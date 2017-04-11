
#include <OgreSceneManager.h>

void	putLight(Ogre::SceneManager* mSceneMgr) {
  Ogre::Light *spotLight = mSceneMgr->createLight("Spot");
  Ogre::Light *spotLight2 = mSceneMgr->createLight("Spot2");
  
  spotLight->setDiffuseColour(1.0, 1.0, 1.0);
  spotLight->setSpecularColour(1.0, 1.0, 1.0);
  
  spotLight->setType(Ogre::Light::LT_SPOTLIGHT);
  
  spotLight->setDirection(0.5, 0, -1);
  spotLight->setPosition(Ogre::Vector3(30, 5, 250));

  spotLight->setSpotlightRange(Ogre::Degree(10), Ogre::Degree(90));

  //set color of the light
  spotLight2->setDiffuseColour(1.0, 1.0, 1.0);
  spotLight2->setSpecularColour(1.0, 1.0, 1.0);
  //set type light
  spotLight2->setType(Ogre::Light::LT_SPOTLIGHT);

  spotLight2->setDirection(0, -1, -1);
  spotLight2->setPosition(Ogre::Vector3(0, 50, 50));

  spotLight2->setSpotlightRange(Ogre::Degree(10), Ogre::Degree(90));
}
