#ifndef JEWEL_MODEL
#define JEWEL_MODEL

#include <string>
#include <stdio.h>
#include "ItemModel.h"

namespace Core
{
    class JewelModel : ItemModel
    {
        public: 
            JewelModel(std::string setTypeValue, std::string setRevelanceValue);
            ~JewelModel() = default;
    };
}
#endif