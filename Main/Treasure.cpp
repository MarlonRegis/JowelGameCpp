#include "Treasure.h"
#include <vector>

using namespace Main;
using namespace std;

Treasure::Treasure():  ItemModel("T", 0){
}

void Treasure::Add(ItemModel itemModel){
        _itemList.push_back(itemModel);
}

void Treasure::Remove(ItemModel itemModel){
        //TODO: Analise this method
        _itemList.remove(_itemList.begin(),_itemList.end(),itemModel);
}

int Treasure::GetValue(){
        int resultValue = 0;
        vector<ItemModel>::iterator item; 

        for(item = _itemList.begin(); item != _itemList.end(); item++){
                resultValue = item.GetValue();
        }
        return resultValue;
}

std::vector<class ItemModel> Treause::GetItemList(){
        return _itemList;
}