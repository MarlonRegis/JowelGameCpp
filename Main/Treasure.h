#ifndef ITEM_MODEL
#define ITEM_MODEL

#include <stdio.h>
#include <vector>
#include "Core/ItemModel.h"

using namespace Core;

namespace Main
{
    class Treasure: public ItemModel{
    {
        private:
            std::vector<class ItemModel> _itemList;
        public: 
            Treasure();
            ~Treasure() = default;
            void Add(ItemModel itemModel);
            void Remove(ItemModel foodModel);
            int GetValue();
            std::vector<class ItemModel> GetItemList();
    };
}
#endif