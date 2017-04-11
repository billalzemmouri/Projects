//
// Fire.cpp for Fire.cpp in /home/armnit/EPITECH/rendu2015/cpp_indie_studio/src
//
// Made by armnit
// Login   <armnit@epitech.net>
//
// Started on  Sat May 21 18:22:11 2016 armnit
// Last update Mon May 23 06:42:48 2016 Alexis
//

::Ogre::Entity* Entity = mSceneMgr->createEntity("FireEntity", ::Ogre::SceneManager::PT_CUBE);
::Ogre::MaterialPtr material(Ogre::MaterialManager::getSingleton().getByName("Fire"));

if (!material.isNull())
  {
    Entity->setMaterial(material);

    ::Ogre::SceneNode* FireNode = mSceneMgr->getRootSceneNode()->createChildSceneNode("FireNode");
    ::Ogre::SceneNode* FireScaleNode = FireNode->createChildSceneNode("FireScaleNode");
    // scale the box to 1.5 units
    ::Ogre::AxisAlignedBox BoundingBox = Entity->getBoundingBox();
    float Scale = 1.50f / BoundingBox.getSize().x;
    FireScaleNode->attachObject(Entity);
    FireScaleNode->setScale(Scale, Scale, Scale);
    // put it some place where we can see it
    FireNode->setPosition(TargetPosition);
  }
