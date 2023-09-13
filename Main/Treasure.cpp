#include "Treasure.h"
#include <vector>

using namespace Core;
using namespace Main;
using namespace std;

Treasure::Treasure(int setRevelanceValue):ItemModel('T', setRevelanceValue){};

int Treasure::GetValue()
{
        int resultValue = 0;
        // vector<ItemModel>::iterator item; 

        // for(item = _itemList.begin(); item != _itemList.end(); item++)
        // {
        //         auto itemModel = (ItemModel) item;
        //         resultValue = itemModel.GetValue();
        // }

        return resultValue;
}