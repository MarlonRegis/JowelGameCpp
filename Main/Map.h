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
            int _foodQuantity;
            int _jewelQuantity;
            int _foodValue;
            int _jewelValue;
        public:
            Map(int w, int h);
            ~Map()=default;
            void AddItem(int x, int y, Item* item);
            void RemoveItem(int x, int y);
            void SetEmptyMap();
            void PrintMap() const;
            void SetItemList();
    };
}
#endif