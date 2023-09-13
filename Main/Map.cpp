#include "Treasure.h"

using namespace Main;

Map::Map(int width, int height){
    _width = width;
    _height = height; 
    _map = new ItemModel *[_width];
    
    for (int i = 0; i < _width; i++) {
        _map[i] = new ItemModel[_height];
    }
}

Map::~Map()
{
    Map::DeleteScreen(_map);
}

void Map::SetEmptyMap()
{
    for (int i = 0; i < _width; i++) 
    {
        for (int j = 0; j < _height; j++) 
        {
            _map[i][j]=" ";
        }
    }
}

void Map::PrintMap(){
    Map::FindItemList();   
    cout <<"Treasure Quantity: " << _treasureQuantity << endl;
    cout <<"Treasure Food Quantity: " << _treasureFoodQuantity << endl;
    cout <<"Treasure Food total Value: " << _treasureFoodValue << endl;
    cout <<"Treasure Jewel Quantity: " << _treasureJewelQuantity << endl;
    cout <<"Treasure Jewel total Value: " << _treasureJewelValue << endl;

    for (int i = 0; i < _width; i++) 
    {
        for (int j = 0; j < _height; j++) 
        {
            if(_map[i][j].GetType() != null){
                cout << _map[i][j].GetType();
            }else{
                cout << " ";
            }
        }
        cout << "\n"<< endl;
    }
}

void Map::AddItem(int width, int height, ItemModel item)
{
    _map[width][height]=item;
}

void Map::RemoveItem(int x, int y){
    _map[width][height]= nullptr;
}

void Map::FindItemList(){
    for (int i = 0; i < _width; i++) 
    {
        for (int j = 0; j < _height; j++) 
        {
            if(_map[i][j].GetType() == "T"){
                _treasureQuantity += 1;
                auto test = (Treasure) _map[i][j];
                for(ItemModel item : test.GetItemList()){
                        if(item.GetType() == "F"){
                            _treasureFoodQuantity +=1;
                            _treasureFoodValue +=item.GetValue();    
                        }else if(item.GetType() == "J"){
                            _treasureJewelQuantity +=1;
                            _treasureJewelValue  +=item.GetValue();
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