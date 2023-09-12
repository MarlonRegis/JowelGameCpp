#ifndef ITEM_MODEL
#define ITEM_MODEL

#include <string>
#include <stdio.h>

namespace Core
{
    class ItemModel
    {
        public: 
            ItemModel::ItemModel(std::string setTypeValue, std::string setRevelanceValue);
            ~ItemModel() = default;
            std::string GetType();
            std::string GetRevelanceValue();
            std::string SetType(std::string setTypeValue);
            std::string SetRevelanceValue(std::string setRevelanceValue);
            
        private:
            std::string _typeOfItem = null;
            std::string _relevanceValue = null;
    };
}
#endif