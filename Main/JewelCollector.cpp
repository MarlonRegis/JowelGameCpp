#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <algorithm>
#include <cstring>
#include "../Core/FoodModel.h"
#include "../Core/JewelModel.h"
#include "Robot.h"
#include "Treasure.h"
#include "Map.h"

using namespace std;
using namespace Main;
using namespace Core;

static void PrintScreen()
{
    std::cout << "---Jewel Collector v1.0---" << std::endl;
    std::cout << "---Map 10 x 10---" << std::endl;
    std::cout << "Choose an option: " << std::endl;
    std::cout << "1- Start Game" << std::endl;
    std::cout << "2- Exit" << std::endl;
}

int main()
{
    bool exitProgram = false;
    int inputvalue;
    char command;
    bool gameOver;
    int robotWidth = 0;
    int robotHeight = 0; 
    int maxWidth = 30;
    int maxHeight = 30; 

    string validateCommand = "";

    Map map(maxWidth, maxHeight);
    map.SetEmptyMap();

    ItemModel robot = Robot(0);
    map.AddItem(0, 0, robot);
    
    ItemModel foodModel = FoodModel(15);
    map.AddItem(0, 10, foodModel);
    ItemModel foodModel2 = FoodModel(10);
    map.AddItem(12, 8, foodModel2);
    ItemModel jewelModel = JewelModel(50);
    map.AddItem(20, 25, jewelModel);
    ItemModel jewelModel2 = JewelModel(50);
    map.AddItem(29, 29, jewelModel2);

    ItemModel treasure = Treasure(0);
    ItemModel foodModel3 = FoodModel(25);
    ItemModel jewelModel3 = JewelModel(100);
    treasure.Add(foodModel3);
    treasure.Add(jewelModel3);
    map.AddItem(10, 5, treasure);

    do 
    { 
        try
        {
            PrintScreen();
            if (!(cin >> inputvalue))
                throw std::invalid_argument("Unnexpected value, choice a correctly number!");
            
            switch (inputvalue)
            {
                case 1:
                {
                    std::cout << "Energy: " << robot.GetEnergy() << " Inventory: " << robot.GetValue() << std::endl;
                    map.PrintMap();

                    do
                    {
                        std::cout << "Waiting for Command! Press P for Game Over!" << std::endl;
                        cin >> command;
                        
                        if (tolower(command) == 'p')
                        {
                            gameOver = true;
                            exitProgram = true;
                            std::cout << "GAME OVER!" << std::endl;
                        }
                        else 
                        {
                            map.GetRobotPosition(robotWidth, robotHeight);
                            validateCommand = map.WalkInMap(tolower(command), robotWidth, robotHeight, robot);
                            string empty = "";

                            transform(validateCommand.begin(), validateCommand.end(), validateCommand.begin(), ::toupper);
                            if (!(strcasecmp(validateCommand.c_str(), empty.c_str()) == 0))
                            {
                                 std::cout << validateCommand << std::endl;
                            }

                            gameOver = map.GameOver();

                            if(!gameOver)
                            {
                                std::cout << "Energy: " << robot.GetEnergy() << "Inventory: " << robot.GetValue() << std::endl;
                                map.PrintMap();
                            } 
                            else
                            {
                                exitProgram = true;
                                std::cout << "GAME OVER!" << std::endl;
                            }
                        }
                    } while (!gameOver);
                    break;
                }
                case 2:
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