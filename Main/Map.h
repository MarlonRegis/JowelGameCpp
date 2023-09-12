#ifndef MAP_H
#define MAP_H

#include <vector>
#include "ItemModel.h"

class Map {
        private:
        std::vector<Item*> items;
        int width;
        int height;

        public:
        Map(int w, int h);
        void addItem(Item* item);
        void removeItem(Item* item);
        void printMap() const;
};

#endif