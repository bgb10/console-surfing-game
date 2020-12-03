#ifndef OBJECTGENERATOR_H
#define OBJECTGENERATOR_H

#include "SceneManager.h"
#include "ObjectManager.h"
#include "GameObject.h"
#include "GameObject/MovableObject/Kraken.h"
#include "GameObject/MovableObject/Surfer.h"
#include "GameObject/Drawback.h"
#include "GameObject/Item.h"
#include "GameObject/Obstacle.h"

#include <random> //random
#include <ctime>

using namespace std;

class ObjectGenerator{
    private:
        int level = 0;
        const float chance_map[3][5] = {
            {0.0f, 0.2f,  0.1f,  0.2f,  0.2f},
            {0.1f, 0.25f, 0.2f,  0.2f,  0.25f},
            {0.2f, 0.3f,  0.25f, 0.15f, 0.3f},
        };
    public:
        ObjectGenerator();
        void Generate(ObjectManager& objectManager);
        void Generate(ObjectManager& objectManager, SceneManager& sceneManager);
        int GetLevel();
        void LevelUp();
};

#endif