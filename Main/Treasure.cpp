#include "Treasure.h"
#include <vector>

using namespace Main;
using namespace std;

Treasure::Treasure(){
}

void Add(FoodModel foodModel){
        _foodList.push_back(foodModel);
}

void Add(JewelModel jewelModel){
        _jewelList.push_back(jewelModel);
}

void Remove(FoodModel foodModel){
        _foodList.remove(_foodList.begin(),_foodList.end(),foodModel)
}

void Remove(JewelModel jewelModel){
        vector<int>::iterator new_end;
        new_end =_jewelList.remove(_foodList.begin(),_foodList.end(),jewelModel)
}

int getValue(){
        vector<FoodModel>::iterator itFood; 
        for(itFood = _foodList.begin(); itFood != _foodList.end(); itFood++)    {
                int resultValue = itFood._relevanceValue;
        }

        vector<JewelModel>::iterator itJewel; 
        for(itJewel = _foodList.begin(); itJewel != _foodList.end(); itJewel++)    {
                resultValue = itJewel._relevanceValue;
        }
        return resultValue;
}