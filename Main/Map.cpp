#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>
#include <cstring>
#include "Map.h"
#include "Treasure.h"

using namespace Core;
using namespace Main;
using namespace std;

Map::Map(int width, int height)
{
    _width = width;
    _height = height; 
    _map = new ItemModel *[_width];
    
    for (int i = 0; i < _width; i++) {
        _map[i] = new ItemModel[_height];
    }
}

Map::~Map()
{
    Map::DeleteMap(_map);
}

void Map::SetEmptyMap()
{
    for (int i = 0; i < _width; i++) 
    {
        for (int j = 0; j < _height; j++) 
        {
            _map[i][j] = ItemModel();
        }
    }
}

void Map::PrintMap()
{
    Map::FindItemList();
    std::cout <<"T: " << _treasureQuantity <<" T-Food: " << _treasureFoodQuantity 
    <<" T-Food total: " << _treasureFoodValue <<" T-Jewel: " << _treasureJewelQuantity 
    <<" T-Jewel total: " << _treasureJewelValue << endl;

    _treasureQuantity       = 0;
    _treasureFoodQuantity   = 0;
    _treasureFoodValue      = 0;
    _treasureJewelQuantity  = 0;
    _treasureJewelValue     = 0;

    for (int i = 0; i < _width; i++) 
    {
        for (int j = 0; j < _height; j++) 
        {
            if(_map[i][j].GetType() != '\0')
            {
                cout << _map[i][j].GetType();
            }
            else
            {
                cout << " ";
            }
        }
        cout << "\n"<< endl;
    }
}

void Map::AddItem(int width, int height, ItemModel& item)
{
    _map[width][height] = item;
}

void Map::RemoveItem(int width, int height)
{
    _map[width][height] = ItemModel();
}

void Map::FindItemList()
{
    for (int i = 0; i < _width; i++) 
    {
        for (int j = 0; j < _height; j++) 
        {
            if(_map[i][j].GetType() == 'T')
            {
                _treasureQuantity = _treasureQuantity + 1;
                auto treasure = _map[i][j];
                
                for(ItemModel item : treasure.GetItemList())
                {
                    if(item.GetType() == 'F')
                    {
                        _treasureFoodQuantity +=1;
                        _treasureFoodValue += item.GetValue();    
                    }
                    else if(item.GetType() == 'J')
                    {
                        _treasureJewelQuantity +=1;
                        _treasureJewelValue  += item.GetValue();
                    }
                }
            }
        }
    } 
}

void Map::DeleteMap(ItemModel** matriz)
{
    for (int i = 0; i < _width; i++) {
        delete[] matriz[i]; 
    }
    delete[] matriz;
}

string Map::WalkInMap(char command, int width, int height, ItemModel& itemModel)
{
    _walkInMapSucess = false;

    string validate = ValidateResponse(width, height, itemModel); 
    string empty = "";

    transform(validate.begin(), validate.end(), validate.begin(), ::toupper);
    if (!(strcasecmp(validate.c_str(), empty.c_str()) == 0))
    {
        return validate;
    }

    switch (command)
    {
        case 'w':
        {
            return Up(width, height, itemModel);
        }
        case 'a':
        {
            return Left(width, height, itemModel);
        }
        case 'd':
        {
            return Right(width, height, itemModel);
        }
        case 's':
        {
            return Down(width, height, itemModel);
        }
        case 'g':
        {
            CollectAll(width, height, itemModel);
            return empty;
        }
        default:
        {
            return "Use a valid command: Up = w, Left = a, Right = d, Down = s, and CollectAll = g";
        };
    }
}

bool Map::GetWalkInMapSucess()
{
    return _walkInMapSucess;
}

bool Map::ValidateBoundariesOutsideMap(int width, int height)
{
    if ((((width < 0) && (width >= _width)) || ((height < 0) && (height >= _height))))
    {
        return true;
    }

    return false;
}

bool Map::ValidateIfHasAnItem(int width, int height)
{
    if((_map[width][height].GetType() != '\0') && (_map[width][height].GetType() != 'R'))
    {
        return true;
    }

    return false;
}

bool Map::ValidateRobot(Core::ItemModel& itemModel)
{
    if(itemModel.GetType() != 'R')
    {
        return true;
    }

    return false;
}

string Map::ValidateAll(int width, int height, Core::ItemModel& itemModel)
{
    if (ValidateBoundariesOutsideMap(width, height))
    {
        return "You cannot walk outside the map boundaries!";
    }

    if(ValidateIfHasAnItem(width, height))
    {
        string type(1, _map[width][height].GetType());

        return "You cannot move to a position that has an item! The item is: " + type;
    }

    if(ValidateRobot(itemModel))
    {
        return "You need to be a robot to walk around the map!";
    }

    return "";
}

std::string Map::ValidateResponse(int width, int height, Core::ItemModel& itemModel)
{
    string empty = "";
    string validate = ValidateAll(width, height, itemModel);

    transform(validate.begin(), validate.end(), validate.begin(), ::toupper);
    if (!(strcasecmp(validate.c_str(), empty.c_str()) == 0))
    {
        return validate;
    }

    return empty;
}

string Map::Up(int width, int height, ItemModel& itemModel)
{
    int newWidth = width - 1;
    int newHeight = height;

    string validate = ValidateResponse(newWidth, newHeight, itemModel);
    string empty = "";

    transform(validate.begin(), validate.end(), validate.begin(), ::toupper);
    if (!(strcasecmp(validate.c_str(), empty.c_str()) == 0))
    {
        return validate;
    }

    SetStatusMap(width, height, newWidth, newHeight, itemModel);

    return empty;
}

string Map::Left(int width, int height, ItemModel& itemModel)
{
    int newWidth = width;
    int newHeight = height - 1;
    
    string validate = ValidateResponse(newWidth, newHeight, itemModel);
    string empty = "";

    transform(validate.begin(), validate.end(), validate.begin(), ::toupper);
    if (!(strcasecmp(validate.c_str(), empty.c_str()) == 0))
    {
        return validate;
    }

    SetStatusMap(width, height, newWidth, newHeight, itemModel);

    return empty;
}

string Map::Right(int width, int height, ItemModel& itemModel)
{
    int newWidth = width;
    int newHeight = height + 1;
    
    string validate = ValidateResponse(newWidth, newHeight, itemModel);
    string empty = "";

    transform(validate.begin(), validate.end(), validate.begin(), ::toupper);
    if (!(strcasecmp(validate.c_str(), empty.c_str()) == 0))
    {
        return validate;
    }

    SetStatusMap(width, height, newWidth, newHeight, itemModel);

    return empty;
}

string Map::Down(int width, int height, ItemModel& itemModel)
{
    int newWidth  = width + 1;
    int newHeight = height;
    
    string validate = ValidateResponse(newWidth, newHeight, itemModel);
    string empty = "";

    transform(validate.begin(), validate.end(), validate.begin(), ::toupper);
    if (!(strcasecmp(validate.c_str(), empty.c_str()) == 0))
    {
        return validate;
    }

    SetStatusMap(width, height, newWidth, newHeight, itemModel);

    return empty;
}

void Map::SetStatusMap(int width, int height, int newWidth, int newHeight, Core::ItemModel& itemModel)
{
    itemModel.SetEnergy(itemModel.GetEnergy() - 1);
    AddItem(newWidth, newHeight, itemModel);
    RemoveItem(width, height);
    _walkInMapSucess = true;
}

void Map::CollectAll(int width, int height, ItemModel& itemModel)
{
    //Up
    int newWidth = width - 1;
    int newHeight = height;
    SetStatusMapCollect(newWidth, newHeight, itemModel);

    //Left
    newWidth = width;
    newHeight = height - 1;
    SetStatusMapCollect(newWidth, newHeight, itemModel);

    //Right
    newWidth = width;
    newHeight = height + 1;
    SetStatusMapCollect(newWidth, newHeight, itemModel);

    //Down
    newWidth  = width + 1;
    newHeight = height;
    SetStatusMapCollect(newWidth, newHeight, itemModel);
}

void Map::SetStatusMapCollect(int newWidth, int newHeight, Core::ItemModel& itemModel)
{
    if (!ValidateBoundariesOutsideMap(newWidth, newHeight) 
        && ValidateIfHasAnItem(newWidth, newHeight)
        && !ValidateRobot(itemModel))
    {
        if(_map[newWidth][newHeight].GetType() == 'F')
        {
            itemModel.Add(_map[newWidth][newHeight]);
            RemoveItem(newWidth, newHeight);
        }
        else if(_map[newWidth][newHeight].GetType() == 'J')
        {
            itemModel.Add(_map[newWidth][newHeight]);
            RemoveItem(newWidth, newHeight);
        } 
        else if(_map[newWidth][newHeight].GetType() == 'T')
        {
            unsigned int vecSize = _map[newWidth][newHeight].GetItemList().size();
            for(unsigned int i = 0; i < vecSize; i++)
            {
                _map[newWidth][newHeight].Remove(i);
            }
        }
    }
}

bool Map::GameOver()
{
    int jewel = 0;
    for (int i = 0; i < _width; i++) 
    {
        for (int j = 0; j < _height; j++) 
        {
            if(_map[i][j].GetType() == 'R')
            {
                if(_map[i][j].GetEnergy() == 0)
                {
                    return true;
                }
            }
            else if(_map[i][j].GetType() == 'J')
            {
                jewel += 1;
            }
            else if(_map[i][j].GetType() == 'T')
            {
                auto treasure = _map[i][j];
                for(ItemModel item : treasure.GetItemList())
                {
                    if(item.GetType() == 'J')
                    {
                        jewel += 1;     
                    }
                }
            }
        }
    }

    if(jewel == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Map::GetRobotPosition(int &width, int &height)
{
    bool findRobotPosition = false;
    for (int i = 0; i < _width; i++) 
    {
        for (int j = 0; j < _height; j++) 
        {
            if(_map[i][j].GetType() == 'R')
            {
                width = i;
                height = j;
                findRobotPosition = true;
                break;
            }
        }

        if (findRobotPosition)
        {
            break;
        }
    }
}