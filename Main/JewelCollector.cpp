#include <iostream>
#include <stdio.h>
#include "Map.h"

using namespace std;
using namespace Main;

void PrintScreen()
{
    std::cout << "---Jewel Collector v1.0---" << std::endl;
    std::cout << "Choose an option: " << std::endl;
    std::cout << "1- Add Item in Map" << std::endl;
    std::cout << "2- Remove Item in Map" << std::endl;
    std::cout << "3- Add Treasure in Map" << std::endl;
    std::cout << "4- Remove Treasure in Map" << std::endl;
    std::cout << "5- Exit" << std::endl;
}


int main()
{
    bool exitProgram = false;
    int inputvalue;
    int maxWidth = 10;
    int maxHeight = 10; 

    Map map;
    map(maxWidth, maxHeight);
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
            char valueDraw;

            switch (inputvalue)
            {
                case 1:
                    cout<<"Enter the row position: "<< endl;
                    if (!(cin >> line))
                        throw std::invalid_argument("Unnexpected line, choice a correctly line!");
                    cout<<"Enter the column position: "<< endl;
                    if (!(cin >> column))
                        throw std::invalid_argument("Unnexpected column, choice a correctly column!");
                    cout<<"Enter with Item Model Type: "<< endl;
                    cin >> valueDraw;
                    screenFactory.DrawScreen(line-1, column-1, valueDraw);
                    break;
                case 2:
                    cout << "Enter the number of rows" << std::endl;
                    if (!(cin >> line))
                        throw std::invalid_argument("Unnexpected line, choice a correctly line!");
                    cout << "Enter the numbers of columns" << std::endl;
                    if (!(cin >> column))
                        throw std::invalid_argument("Unnexpected column, choice a correctly column!");
                    
                    screenFactory.ResizeScreen(line, column);
                    break;
                case 3:
                    screenFactory.ReadScreen();
                    break;
                case 4:
                    exitProgram = true;
                    break;
                case 5:
                    exitProgram = true;
                    break;
                default:
                    cout << "Unnexpected value, choice a correctly number." << endl;
                    break;
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