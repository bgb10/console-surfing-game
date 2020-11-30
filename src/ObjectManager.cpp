#include "ObjectManager.h"

//constructor
ObjectManager::ObjectManager(){
    
}
//Getter
Player ObjectManager::GetPlayer(){
    return m_player;
}
vector<MovableObject> GetMovable()