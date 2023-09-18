#ifndef ROBOT_H
#define ROBOT_H

#include <stdio.h>
#include <vector>
#include "../Core/ItemModel.h"
#include "Map.h"

namespace Main
{
    class Robot: public Core::ItemModel
    {
        private:
            int _energy = 10;
            std::vector<class Core::ItemModel> _inventory;

            void CollectTreasure(ItemModel itemModel);

        public:
            Robot() = default;
            Robot(int setRevelanceValue);
            ~Robot() = default;

            int GetEnergy();
            void SetEnergy(int setEnergy);

            std::vector<class ItemModel> GetItemList();
            void Add(ItemModel itemModel);
    };
}
#endif