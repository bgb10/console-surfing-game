#ifndef OBJECTGENERATOR_H
#define OBJECTGENERATOR_H

#include "SceneManager.h"
#include "ObjectManager.h"
#include "GameObject.h"
#include "GameObject/MovableObject/Kraken.h"
#include "GameObject/Obstacle/Buoy.h"
#include "GameObject/Obstacle/Deck.h"
#include "GameObject/Item/Boost.h"
#include "GameObject/Item/Health.h"

#include <random> //random
#include <ctime>

using namespace std;

class ObjectGenerator{
    private:
        int level = 0;
        const float chance_map[3][5] = {
            {0.0, 0.2,  0.1,  0.2,  0.2},
            {0.1, 0.25, 0.2,  0.2,  0.25},
            {0.2, 0.3,  0.25, 0.15, 0.3},
        };
    public:
        ObjectGenerator();
        void Generate(ObjectManager& objectManager);
        void Generate(ObjectManager& objectManager, SceneManager& sceneManager);
        int GetLevel();
        void LevelUp();
};

#endif