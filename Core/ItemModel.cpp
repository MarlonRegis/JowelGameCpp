#include <iostream>
#include <string>
#include "ItemModel.h"

using namespace Core;
using namespace std;

ItemModel::ItemModel(char setTypeValue, int setRevelanceValue){
        _relevanceValue = setRevelanceValue;
        _typeOfItem = setTypeValue;
}

void ItemModel::SetValue(int setRevelanceValue){
        _relevanceValue = setRevelanceValue;
}

void ItemModel::SetType(char setTypeValue){
        _typeOfItem = setTypeValue;
}

void ItemModel::SetEnergy(int setEnergy) 
{
        _energy = setEnergy;
}

int ItemModel::GetValue(){
        return _relevanceValue;
}

char ItemModel::GetType(){
        return _typeOfItem;
}

int ItemModel::GetEnergy(){
        return _energy;
}

std::vector<class ItemModel> ItemModel::GetItemList(){
        return ItemModel::_itemList;
}

void ItemModel::Add(ItemModel itemModel){
        _itemList.push_back(itemModel);
}

void ItemModel::RemoveAll()
{
        _itemList.clear();
}

void ItemModel::AddItem(ItemModel itemModel)
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

void ItemModel::CollectTreasure(ItemModel itemModel)
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
            ItemModel newItem = ItemModel(item->GetType(), item->GetValue());
            _inventory.push_back(newItem);
        } 
    }
}