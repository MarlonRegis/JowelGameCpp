#ifndef ITEM_MODEL
#define ITEM_MODEL

#include <string>
#include <stdio.h>
#include <vector>
#include "Core/JewelModel.h"
#include "Core/FoodModel.h"

using namespace Core;

namespace Main
{
    class Treasure{
    {
        public: 
            Treasure();
            ~Treasure() = default;
            void Add(FoodModel foodModel);
            void Add(JewelModel jewelModel);
            void Remove(FoodModel foodModel);
            void Remove(JewelModel jewelModel);
            int getValue();
        private:
            std::vector<class JewelModel> _jewelList;
            std::vector<class Food> _foodList;
    };
}
#endif