#ifndef TREASURE_H
#define TREASURE_H

#include "../Core/ItemModel.h"

namespace Main
{
    class Treasure: public Core::ItemModel
    {
        public:
            Treasure() = default;
            Treasure(int setRevelanceValue);
            ~Treasure() = default;
            int GetValue();
    };
}
#endif