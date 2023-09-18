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
            std::vector<class Core::ItemModel> _inventory;

            void CollectTreasure(Core::ItemModel itemModel);

        public:
            Robot() = default;
            Robot(int setRevelanceValue);
            ~Robot() = default;

            std::vector<class Core::ItemModel> GetItemList();
            void Add(Core::ItemModel itemModel);
    };
}
#endif