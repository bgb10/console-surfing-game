#include "ObjectManager.h"
#include <string>
//constructor
ObjectManager::ObjectManager(){
    
}
//Getter
Player ObjectManager::GetPlayer(){
    return m_player;
}
vector<MovableObject> ObjectManager::GetMovable(){
    return m_vector_movable;
}
vector<GameObject> ObjectManager::GetImmovable(){
    return m_vector_immovable;
}
//Setter
void ObjectManager::AddMovable(MovableObject object){
    m_vector_movable.push_back(object); //add Movable object using push_back
}
void ObjectManager::AddImmovable(GameObject object){
    m_vector_immovable.push_back(object);//add Immovable object using push_back
}
void ObjectManager::ResetPlayer(){
    
}
void ObjectManager::RemoveMovable(MovableObject object){
    //find_if
}
void ObjectManager::RemoveImmovable(GameObject object){
    //find_if
}
void ObjectManager::RemoveAllMovables(){
    m_vector_movable.clear();
}
void ObjectManager::RemoveAllImmovables(){
    m_vector_immovable.clear();
}
void ObjectManager::Clear(){
    m_vector_movable.clear();
    m_vector_immovable.clear();
}