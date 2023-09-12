#ifndef ITEM_MODEL
#define ITEM_MODEL

#include <string>
#include <stdio.h>

namespace Core
{
    class ItemModel
    {
        private:
            std::string _typeOfItem = null;
            int _relevanceValue = null;
            
        public: 
            ItemModel::ItemModel(std::string setTypeValue, int setRevelanceValue);
            ~ItemModel() = default;
            std::string GetType();
            std::string GetRevelanceValue();
            void SetType(std::string setTypeValue);
            void SetRevelanceValue(int setRevelanceValue);
    };
}
#endif