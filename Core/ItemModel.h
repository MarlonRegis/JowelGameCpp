#ifndef ITEM_MODEL
#define ITEM_MODEL

#include <stdio.h>
#include <vector>

namespace Core
{
    class ItemModel
    {
        private:
            char _typeOfItem = '\0';
            int _relevanceValue = 0;
            int _energy = 0;
            std::vector<class ItemModel> _itemList;
            
        public: 
            ItemModel() = default;
            ItemModel(char setTypeValue, int setRevelanceValue);
            ~ItemModel() = default;

            char GetType();
            int GetValue();
            void SetType(char setTypeValue);
            void SetValue(int setRevelanceValue);

            std::vector<class ItemModel> GetItemList();
            void Add(ItemModel itemModel);
            void Remove(int index);

            int GetEnergy();
            void SetEnergy(int setEnergy);
    };
}
#endif