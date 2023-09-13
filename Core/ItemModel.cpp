#include "ItemModel.h"

using namespace Core;
using namespace std;

ItemModel::ItemModel(char setTypeValue, int setRevelanceValue){
        _relevanceValue = setRevelanceValue;
        _typeOfItem = setTypeValue;
}

void SetValue(int setRevelanceValue){
        _relevanceValue = setRevelanceValue;
}

void SetType(char setTypeValue){
        _typeOfItem = setTypeValue;
}

int GetValue(){
        return _relevanceValue;
}
char GetType(){
        return _typeOfItem;
}