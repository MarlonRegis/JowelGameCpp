#ifndef ROBOT_H
#define ROBOT_H

#include <stdio.h>
#include <vector>
#include "../Core/ItemModel.h"
#include "Map.h"

namespace Main
{
    class Robot: public Core::ItemModel
    {
        public:
            Robot(int setRevelanceValue);
            ~Robot() = default;
    };
}
#endif