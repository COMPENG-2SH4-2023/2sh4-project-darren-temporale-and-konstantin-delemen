#ifndef FOOD_H
#define FOOD_H

#include "objPos.h"
#include "objPosArrayList.h"

class Food{
    protected:
        objPosArrayList *foodBucket;

    public:
        Food();//new food with the default symbol 'O' and position using default game size
        Food(char s, objPos &blockOff, int xRange, int yRange); //new food with specified symbol, playerPos, and game board size

        Food(Food &o);

        ~Food();//There is nothing on the heap in Food

        //individual food position
        void getFoodPos(objPos &returnPos, int index);
        int getSizeBucket();
        void getFoodBucketList(objPosArrayList* returnBucket);
        void setFoodBucket(objPosArrayList* setBucket);

        //to be used before the snake body grows (only snake head in objPos)
        void generateInitialFood(objPosArrayList *returnPos, objPos *blockOff, int xRange, int yRange);
        
        //generating food while avoiding the whole snake body
        void generateFood(objPosArrayList *returnPos, objPosArrayList* blockOff, int xRange, int yRange);
};

#endif