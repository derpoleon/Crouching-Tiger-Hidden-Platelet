//
//  EntityManager.cpp
//  Bubblenauts
//
//  Created by Breton Goers on 11/12/13.
//
//

#include "EntityManager.h"

EntityManager::EntityManager()
{
    // Start with an ID of 1 for all objects
    m_lowestEID = 1;
    
    // Use static initializer to create an empty (mutable) array. This is basically
    // just a vector. The create() method returns an autoreleased object, so we must
    // retain it to keep it around.
    m_pEntities = CCArray::create();
    m_pEntities->retain();
    
    // Just the same as above, we get an autoreleased dictionary to track our comps.
    // This must be retained to stick around.
    m_pComponentsByClass = CCDictionary::create();
    m_pComponentsByClass->retain();
}

EntityManager::~EntityManager()
{
    // Safely release the array and dictionary that we have retained earlier
    CC_SAFE_RELEASE_NULL(m_pEntities);
    CC_SAFE_RELEASE_NULL(m_pComponentsByClass);
}

Entity* EntityManager::createEntity()
{
    // Create an entity with the eid from generateNewEID()
    
}

uint32_t EntityManager::generateNewEID()
{
    // If we aren't maxed out, return and increment. Otherwise check our array
    // for any open spots. If none available, we've blown up.
    
    if ( m_lowestEID < UINT32_MAX ) {
        return m_lowestEID++;
    }
    else {
        for (uint32_t i = 0; i < UINT32_MAX; i++) {
            CCInteger *wrap = CCInteger::create(i);
            if ( !(m_pEntities->containsObject(wrap)) ) {
                return i;
            }
        }
        CCLog("Looks like we had a flagrant error");
        return 0;
    }
}






