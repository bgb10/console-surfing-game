#include "ObjectGenerator.h"

void ObjectGenerator::Generate(ObjectManager& objectManager, SceneManager& sceneManager){
    MovableObject move;
    objectManager.AddMovable(move);
    sceneManager.Init();
}
int ObjectGenerator::GetLevel(){
    
}
void ObjectGenerator::LevelUp(){
    //The amount of unit distance should be decided.
}