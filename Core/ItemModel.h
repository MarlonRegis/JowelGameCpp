#ifndef ITEM_MODEL
#define ITEM_MODEL

#include <stdio.h>

namespace Core
{
    class ItemModel
    {
        private:
            char _typeOfItem = null;
            int _relevanceValue = null;
            
        public: 
            ItemModel::ItemModel(char setTypeValue, int setRevelanceValue);
            ~ItemModel() = default;
            char GetType();
            int GetValue();
            void SetType(char setTypeValue);
            void SetValue(int setRevelanceValue);
    };
}
#endif