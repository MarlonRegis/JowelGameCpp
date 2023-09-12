#include "ItemModel.h"

using namespace Core;
using namespace std;

ItemModel::ItemModel(std::string setTypeValue, std::string setRevelanceValue){
        _relevanceValue = setRevelanceValue;
        _typeOfItem = setTypeValue;
}

std::string SetRevelanceValue(std::string setRevelanceValue){
        _relevanceValue = setRevelanceValue;
}

std::string SetType(std::string setTypeValue){
        _typeOfItem = setTypeValue;
}

std::string GetRevelanceValue(){
        return _relevanceValue;
}
std::string GetType(){
        return _typeOfItem;
}