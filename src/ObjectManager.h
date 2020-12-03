#ifndef OBJECTMANAGER_H
#define OBJECTMANAGER_H

#include "SceneManager.h"
#include "GameObject/MovableObject.h"
#include "GameObject/MovableObject/Player.h" 
#include <vector>

using namespace std;

class ObjectManager{
    private:
        Player m_player;
        vector<MovableObject> m_vector_movable;
        vector<GameObject> m_vector_immovable;
    public:
        //Constructor
        ObjectManager();
        //Getters
        Player& GetPlayer();
        vector<MovableObject>& GetMovable();
        vector<GameObject>& GetImmovable();
        //Setters
        void AddMovable(MovableObject& object);
        void AddImmovable(GameObject& object);
        void ResetPlayer();
        void RemoveMovable(MovableObject& object);
        void RemoveImmovable(GameObject& object);
        void RemoveAllMovables();
        void RemoveAllImmovables();
        void Clear();
};

#endif