#include <iostream>
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
    std::cout <<"Treasure Quantity: " << _treasureQuantity << endl;
    cout <<"Treasure Food Quantity: " << _treasureFoodQuantity << endl;
    cout <<"Treasure Food total Value: " << _treasureFoodValue << endl;
    cout <<"Treasure Jewel Quantity: " << _treasureJewelQuantity << endl;
    cout <<"Treasure Jewel total Value: " << _treasureJewelValue << endl;

    for (int i = 0; i < _width; i++) 
    {
        for (int j = 0; j < _height; j++) 
        {
            if(_map[i][j].GetType() != '\0'){
                cout << _map[i][j].GetType();
            }else{
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