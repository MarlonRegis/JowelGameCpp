#ifndef FOOD_MODEL
#define FOOD_MODEL

#include <string>
#include <stdio.h>
#include "ItemModel.h"

namespace Core
{
    class FoodModel : ItemModel
    {
        public: 
            FoodModel(std::string setTypeValue, int setRevelanceValue);
            ~FoodModel() = default;
    };
}
#endif