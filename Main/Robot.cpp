#include "Robot.h"
#include <vector>
#include "../Core/JewelModel.h"

using namespace Core;
using namespace Main;
using namespace std;

Robot::Robot(int setRevelanceValue):ItemModel('R', setRevelanceValue){};

int Robot::GetEnergy()
{
    return _energy;
}

void Robot::SetEnergy(int setEnergy)
{
    _energy = setEnergy;
}

void Robot::Add(ItemModel itemModel)
{
    if(itemModel.GetType() == 'F')
    {
        SetEnergy(GetEnergy() + itemModel.GetValue());
    }
    else if(itemModel.GetType() == 'J')
    {
        ItemModel::SetValue(ItemModel::GetValue() + itemModel.GetValue());
        _inventory.push_back(itemModel);
    } 
    else if(itemModel.GetType() == 'T')
    {
        CollectTreasure(itemModel);
    }
}

void Robot::CollectTreasure(ItemModel itemModel)
{
    vector<ItemModel>::iterator item; 

    for(item = ItemModel::GetItemList().begin(); item != ItemModel::GetItemList().end(); item++)
    {
        if(item->GetType() == 'F')
        {
            SetEnergy(GetEnergy() + item->GetValue());
        }
        else if(item->GetType() == 'J')
        {
            ItemModel::SetValue(ItemModel::GetValue() + item->GetValue());
            ItemModel newItem = JewelModel(item->GetValue());
            _inventory.push_back(newItem);
        } 
    }
}
