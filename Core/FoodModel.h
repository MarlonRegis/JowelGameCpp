#ifndef FOOD_MODEL
#define FOOD_MODEL

#include <stdio.h>
#include "ItemModel.h"

namespace Core
{
    class FoodModel : public ItemModel
    {
        public: 
            FoodModel(int setRevelanceValue);
            ~FoodModel() = default;
    };
}
#endif