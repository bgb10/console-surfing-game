#include "ObjectGenerator.h"

void ObjectGenerator::Generate(ObjectManager& objectManager, SceneManager& sceneManager){
    Deck deck;
    Buoy byou;
    Kraken kraken;

    Boost boost; 
    Health health;

    random_device rd;
    mt19937 gen(rd());
    //Scene x:160 y:45 
    uniform_int_distribution<float> x_pos(-sceneManager.GetWidth()/2, -sceneManager.GetWidth()/2); //-80<x_pos<80 
    uniform_int_distribution<float> y_pos(-sceneManager.GetHeight()/2,-sceneManager.GetHeight()/2-3); //-27.5<y_pos<-22.5 
    srand(time(0));

    //Create Obstacles to Match chance_map Probability
    if(rand()%100<chance_map[GetLevel()-1][2]*100){
        if(rand()%2)
            deck.SetCenter(x_pos(gen),y_pos(gen));
        else
            byou.SetCenter(x_pos(gen),y_pos(gen));
    }

    uniform_int_distribution<float> krakeny_pos(sceneManager.GetHeight()/2,sceneManager.GetHeight()/2+3); //22.5<krakeny_pos<27.5
    if(rand()%100<chance_map[GetLevel()-1][0]*100){
         kraken.SetCenter(x_pos(gen),krakeny_pos(gen));
    } //Create Kraken to Match chance_map Probability

    if(rand()%100<chance_map[GetLevel()-1][3]*100){
        if(rand()%2)
            health.SetCenter(x_pos(gen),y_pos(gen));
        else
            boost.SetCenter(x_pos(gen),y_pos(gen));
     } //Create Item to Match chance_map Probability
}
//Getter
int ObjectGenerator::GetLevel(){
    return level;
}

void ObjectGenerator::LevelUp(){
    if(level >= 3){
        //nothing happen
        level = 3;
    }
    else{level = level+1;}//increase one level   
    //The amount of unit distance should be decided.
}