#include <iostream>
#include <stdio.h>
#include "Map.h"
#include "../Core/FoodModel.h"
#include "../Core/JewelModel.h"
#include "Treasure.h"

using namespace std;
using namespace Main;
using namespace Core;

static void PrintScreen()
{
    std::cout << "---Jewel Collector v1.0---" << std::endl;
    std::cout << "---Map 10 x 10---" << std::endl;
    std::cout << "Choose an option: " << std::endl;
    std::cout << "1- Add Item in Map" << std::endl;
    std::cout << "2- Add Treasure in Map" << std::endl;
    std::cout << "3- Remove Item in Map" << std::endl;
    std::cout << "4- Exit" << std::endl;
}

static ItemModel& CreateItemModelByType(char itemModeltype, int valueReference, ItemModel& itemModel)
{
    if (itemModeltype == 'J')
    {
        itemModel = FoodModel(valueReference);
    } 
    else if (itemModeltype == 'F')
    {
        itemModel = JewelModel(valueReference);
    }

    return itemModel;
}

static void AddItemModel(Map &map, ItemModel &itemModel)
{
    int line;
    int column;
    int valueReference;
    char itemModeltype;

    cout<<"Enter the row position: "<< endl;
    if (((!(cin >> line)) && (line < 0 && line >= 10)))
        throw std::invalid_argument("Unnexpected line, choice a correctly line!");
    cout<<"Enter the column position: "<< endl;
    if (((!(cin >> column) && (column < 0 && column >= 10))))
        throw std::invalid_argument("Unnexpected column, choice a correctly column!");
    cout<<"Enter with Item Model Type (J or F): "<< endl;
    cin >> itemModeltype;
    cout<<"Enter with Value Reference: "<< endl;
    if (!(cin >> valueReference))
        throw std::invalid_argument("Unnexpected value reference, choice a correctly value reference!");
    
    map.AddItem(line, column, CreateItemModelByType(itemModeltype, valueReference, itemModel));
}

int main()
{
    bool exitProgram = false;
    int inputvalue;
    int maxWidth = 10;
    int maxHeight = 10; 

    Map map(maxWidth, maxHeight);
    map.SetEmptyMap();

    do 
    { 
        try
        {
            PrintScreen();
            if (!(cin >> inputvalue))
                throw std::invalid_argument("Unnexpected value, choice a correctly number!");

            int line;
            int column;
            int valueReference;
            char itemModeltype;
            Treasure treasure;
        
            switch (inputvalue)
            {
                case 1:
                {
                    ItemModel itemModel;
                    AddItemModel(map, itemModel);
                    break;
                }
                case 2:
                {
                    cout<<"Enter the row position: "<< endl;
                    if (((!(cin >> line)) && (line < 0 && line >= 10)))
                        throw std::invalid_argument("Unnexpected line, choice a correctly line!");
                    cout<<"Enter the column position: "<< endl;
                    if (((!(cin >> column) && (column < 0 && column >= 10))))
                        throw std::invalid_argument("Unnexpected column, choice a correctly column!");
                    
                    treasure = Treasure(0);
                    bool exitTreasure = false;
                    int exitTreasureValue;

                    do
                    {
                        cout<<"Enter with Item Model Type (J or F) to add in Treasure: "<< endl;
                        cin >> itemModeltype;
                        cout<<"Enter with Value Reference: "<< endl;
                        if (!(cin >> valueReference))
                            throw std::invalid_argument("Unnexpected value reference, choice a correctly value reference!");

                        ItemModel itemModel;
                        treasure.Add(CreateItemModelByType(itemModeltype, valueReference, itemModel));
                        
                        cout<<"Would you like to continue adding more ItemModel? (No: 1 )"<< endl;
                        if (!(cin >> exitTreasureValue))
                            throw std::invalid_argument("Unnexpected exit Treasure value, choice a correctly exit Treasure value!");

                        if (exitTreasureValue == 1)
                        {
                            exitTreasure = true;
                        }

                    } while(!exitTreasure);

                    map.AddItem(line, column, treasure);
                    break;
                }
                case 3:
                {
                    cout<<"Enter the row position: "<< endl;
                    if (((!(cin >> line)) && (line < 0 && line >= 10)))
                        throw std::invalid_argument("Unnexpected line, choice a correctly line!");
                    cout<<"Enter the column position: "<< endl;
                    if (((!(cin >> column) && (column < 0 && column >= 10))))
                        throw std::invalid_argument("Unnexpected column, choice a correctly column!");
                    
                    map.RemoveItem(line, column);
                    break;
                }
                case 4:
                {
                    exitProgram = true;
                    break;
                }
                default:
                {
                    cout << "Unnexpected value, choice a correctly number." << endl;
                    break;
                }
           }
        }
        catch(const exception& e)
        {
            cout << e.what() << endl;
            break;
        }
        
    } while (!exitProgram);

    return 0;
}