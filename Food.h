#ifndef FOOD_H
#define FOOD_H

#include "objPos.h"

class Food{
    public:
        objPos foodPos;

        Food();//new food with the default symbol 'O' and position using default game size
        Food(char s, objPos &blockOff, int xRange, int yRange); //new food with specified symbol, playerPos, and game board size

        Food(Food &o);

        //~foodPos();//there is nothing within foodPos on the heap

        void getFoodPos(objPos &returnPos);
        void generateFood(objPos &returnPos, objPos blockOff, int xRange, int yRange);
};

#endif