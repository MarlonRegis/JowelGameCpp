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