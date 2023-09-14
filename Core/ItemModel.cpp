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

int ItemModel::GetValue(){
        return _relevanceValue;
}
char ItemModel::GetType(){
        return _typeOfItem;
}

std::vector<class ItemModel> ItemModel::GetItemList(){
        return ItemModel::_itemList;
}

void ItemModel::Add(ItemModel itemModel){
        _itemList.push_back(itemModel);
}

void ItemModel::Remove(int index)
{
        _itemList.erase(_itemList.begin() + index);
}