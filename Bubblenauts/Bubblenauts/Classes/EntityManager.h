//
//  EntityManager.h
//  Bubblenauts
//
//  Created by Breton Goers on 11/12/13.
//
//

#ifndef __Bubblenauts__EntityManager__
#define __Bubblenauts__EntityManager__

#include <iostream>
#include "cocos2d.h"

class Entity;

USING_NS_CC;

class EntityManager
{
public:
    EntityManager();
    ~EntityManager();
    
    static Entity* createEntity();
    
private:
    uint32_t generateNewEID();
    
    CCArray         *m_pEntities;
    CCDictionary    *m_pComponentsByClass;
    uint32_t        m_lowestEID;
};

#endif /* defined(__Bubblenauts__EntityManager__) */
