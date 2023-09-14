#include "Treasure.h"
#include <vector>

using namespace Core;
using namespace Main;
using namespace std;

Treasure::Treasure(int setRevelanceValue):ItemModel('T', setRevelanceValue){};

int Treasure::GetValue()
{
        int resultValue = 0;
        
        vector<ItemModel>::iterator item; 

        for(item = ItemModel::GetItemList().begin(); item != ItemModel::GetItemList().end(); item++)
        {
                resultValue += item->GetValue();
        }

        return resultValue;
}