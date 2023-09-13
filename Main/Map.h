#ifndef MAP_H
#define MAP_H

#include "Core/ItemModel.h"


using namespace Core;

namespace Main
{
    class Map {
        private:
            ItemModel **_map;
            int _width;
            int _height;
            std::vector<class ItemModel> _itemList;
            int _treasureQuantity;
            int _treasureFoodQuantity;
            int _treasureJewelQuantity;
            int _treasureFoodValue;
            int _treasureJewelValue;
            void FindItemList();
        public:
            Map(int w, int h);
            ~Map();
            void AddItem(int x, int y, Item* item);
            void RemoveItem(int x, int y);
            void SetEmptyMap();
            void DeleteMap();
            void PrintMap() const;
    };
}
#endif