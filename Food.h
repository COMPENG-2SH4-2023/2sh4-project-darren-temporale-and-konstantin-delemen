#ifndef FOOD_H
#define FOOD_H

#include "objPos.h"
#include "objPosArrayList.h"

class Food{
    public:
        objPos foodPos;

        Food();//new food with the default symbol 'O' and position using default game size
        Food(char s, objPos &blockOff, int xRange, int yRange); //new food with specified symbol, playerPos, and game board size

        Food(Food &o);

        //~foodPos();//there is nothing within foodPos on the heap

        void getFoodPos(objPos &returnPos);

        //to be used before the snake body grows (only snake head in objPos)
        void generateInitialFood(objPos &returnPos, objPos &blockOff, int xRange, int yRange);
        
        //generating food while avoiding the whole snake body
        void generateFood(objPos &returnPos, objPosArrayList* blockOff, int xRange, int yRange);
};

#endif