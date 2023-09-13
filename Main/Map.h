#ifndef MAP_H
#define MAP_H

#include <stdio.h>
#include <vector>
#include "../Core/ItemModel.h"

namespace Main
{
    class Map 
    {
        private:
            Core::ItemModel **_map;
            std::vector<class Core::ItemModel> _itemList;

            int _width;
            int _height;

            int _treasureQuantity;
            int _treasureFoodQuantity;
            int _treasureJewelQuantity;
            int _treasureFoodValue;
            int _treasureJewelValue;

            void FindItemList();
            void DeleteMap(Core::ItemModel** matriz);
        public:
            Map(int w, int h);
            ~Map();
            void AddItem(int width, int height, Core::ItemModel item);
            void RemoveItem(int width, int height);
            void SetEmptyMap();
            void PrintMap();
    };
}
#endif