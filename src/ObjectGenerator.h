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
            {0.001f, 0.02f,  0.01f,  0.02f,  0.02f},
            {0.002f, 0.025f, 0.02f,  0.02f,  0.025f},
            {0.003f, 0.03f,  0.025f, 0.015f, 0.03f},
        };
		int kraken_score = 0;
    public:
        ObjectGenerator();
        void Generate(ObjectManager& objectManager);
        void Generate(ObjectManager& objectManager, SceneManager& sceneManager);
        int GetLevel();
        void LevelUp();
};

#endif