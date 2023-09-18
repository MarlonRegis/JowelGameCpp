#ifndef MAP_H
#define MAP_H

#include <string>
#include <vector>
#include "../Core/ItemModel.h"

namespace Main
{
    class Map 
    {
        private:
            Core::ItemModel **_map;
            int _width;
            int _height;

            bool _walkInMapSucess;
            bool _winGame;

            int _treasureQuantity = 0;
            int _treasureFoodQuantity = 0;
            int _treasureJewelQuantity = 0;
            int _treasureFoodValue = 0;
            int _treasureJewelValue = 0;

            void FindItemList();
            void DeleteMap(Core::ItemModel** matriz);
            bool ValidateBoundariesOutsideMap(int width, int height);
            bool ValidateIfHasAnItem(int width, int height);
            bool ValidateRobot(Core::ItemModel& itemModel);
            std::string ValidateAll(int width, int height, Core::ItemModel& itemModel);
            std::string ValidateResponse(int width, int height, Core::ItemModel& itemModel);

            std::string Up(int width, int height, Core::ItemModel& itemModel);
            std::string Left(int width, int height, Core::ItemModel& itemModel);
            std::string Right(int width, int height, Core::ItemModel& itemModel);
            std::string Down(int width, int height, Core::ItemModel& itemModel);

            void CollectAll(int width, int height, Core::ItemModel& itemModel);

            void SetStatusMap(int width, int height, int newWidth, int newHeight, Core::ItemModel& itemModel);
            void SetStatusMapCollect(int newWidth, int newHeight, Core::ItemModel& itemModel);
        public:
            Map(int w, int h);
            ~Map();
            void AddItem(int width, int height, Core::ItemModel& item);
            void RemoveItem(int width, int height);
            void SetEmptyMap();
            void PrintMap();
            bool GameOver();

            void GetRobotPosition(int &width, int &height);
            bool GetWinGame();

            bool GetWalkInMapSucess();
            std::string WalkInMap(char command, int width, int height, Core::ItemModel& itemModel);
    };
}
#endif