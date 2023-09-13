#ifndef JEWEL_MODEL
#define JEWEL_MODEL

#include <stdio.h>
#include "ItemModel.h"

namespace Core
{
    class JewelModel : public ItemModel
    {
        public: 
            JewelModel(char setTypeValue, int setRevelanceValue);
            ~JewelModel() = default;
    };
}
#endif