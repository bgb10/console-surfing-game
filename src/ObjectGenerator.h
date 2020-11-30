#ifndef OBJECTGENERATOR_H
#define OBJECTGENERATOR_H

#include "SceneManager.h"
#include "ObjectManager.h"

using namespace std;

class ObjectGenerator{
    private:
        int level;
        static float chance_map[][5];
    public:
        void Generate(ObjectManager& objectManager, SceneManager& sceneManager);
        int GetLevel();
        void LevelUp();
};

#endif