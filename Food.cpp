#include "Food.h"

#include <stdlib.h>
 
Food::Food(){
    foodBucket = new objPosArrayList();
   
    objPos tempPlayer(30/2, 15/2, 'O'); //the starting player position (only at the start of the game)
    generateInitialFood(foodBucket, &tempPlayer, 30, 15); //generating positions from the default game size
}
 
Food::Food(char s, objPos &blockOff, int xRange, int yRange) {
    foodBucket = new objPosArrayList();
   
    //generate 5 food positions
    generateInitialFood(foodBucket, &blockOff, xRange, yRange);
}

Food::Food(Food &o) {
    foodBucket = new objPosArrayList();
    foodBucket = o.foodBucket;
}

Food::~Food() { //delete any heap member here
    delete foodBucket;
}

void Food::generateInitialFood(objPosArrayList* returnPos, objPos* blockOff, int xRange, int yRange) {
    int xtemp, ytemp, match;
    objPos tempObj, listEle;
    
    int randSpecial = rand() % 5; //randomly choose the special food

    //Generate 5 food objects and insert them into the array
    for (int i = 0; i < 5; i++) {
        if (i==randSpecial) {
            tempObj = objPos(0, 0, '$'); //If the current food being generated is the spacial food, make it have the special char
        }
        else {
            tempObj = objPos(0, 0, 'O'); //If not the special food, make it with the normal char
        }
        do {
            match = 1;
            xtemp = (rand() % (xRange)); //This range is from 0 to range-1
            ytemp = (rand() % (yRange));

            if (xtemp == 0 || ytemp == 0) {
                match = 0;
            }
 
            if (xtemp == blockOff->x && ytemp == blockOff->y) { //If the randomly generated x and y valuse match the player, repete the do while loop
                match = 0;
            }
            for (int j = 0; j < i; j++) {
                returnPos->getElement(listEle, j);
                if (xtemp == listEle.x && ytemp == listEle.y) { 
                    //If the randomly generated x and y valuse match the previous foop positions, repete the do while loop
                    match = 0;
                }
            }
        } while(!match);
 
        //If we have broken out of the do while loop, the temp x and y values dont conflict with anything - so we can use them
        tempObj.x = xtemp;
        tempObj.y = ytemp;
        returnPos->insertHead(tempObj);
    }
}

void Food::generateFood(objPosArrayList* returnPos, objPosArrayList* blockOff, int xRange, int yRange) {
    int listSize = blockOff->getSize();
    objPos listEle, tempObj;
    int xtemp, ytemp, match;
    
    int randSpecial = rand() % 5; //randomly choose the special food

    //generate 5 random food positions and insert them into the array
    for (int i = 0; i < 5; i++) {
        if (i == randSpecial) {
            tempObj = objPos(0, 0, '$'); //If the current food being generated is the spacial food, make it have the special char
        }
        else {
            tempObj = objPos(0, 0, 'O'); //If not the special food, make it with the normal char
        }
        do {
            match = 1;
            xtemp = (rand() % (xRange)); //This range is from 0 to range-1
            ytemp = (rand() % (yRange));

            if (xtemp == 0 || ytemp == 0) {
                match = 0;
            }
            
            for (int j = 0; j < listSize; j++) {
                blockOff->getElement(listEle, j);
                if (xtemp == listEle.x && ytemp == listEle.y) { //If the randomly generated x and y valuse match the player, repete the do while loop
                    match = 0;
                }
            }
            for (int j = 0; j < i; j++) {
                returnPos->getElement(listEle, j);
                if (xtemp == listEle.x && ytemp == listEle.y) { 
                    //If the randomly generated x and y valuse match the previous foop positions, repete the do while loop
                    match = 0;
                }
            }
        } while(!match);
 
        //If we have broken out of the do while loop, the temp x and y values dont conflict with anything - so we can use them
        tempObj.x = xtemp;
        tempObj.y = ytemp;
        returnPos->insertHead(tempObj);
    }
}
 
void Food::getFoodPos(objPos &returnPos, int index) {
    foodBucket->getElement(returnPos,index);
}

int Food::getSizeBucket() {
    return foodBucket->getSize();
}

void Food::getFoodBucketList(objPosArrayList* returnBucket) {
    objPos tempLoc;
    for (int i = 0; i < 5; i++) {
        foodBucket->getElement(tempLoc,i);
        returnBucket->insertHead(tempLoc);
    }
}

void Food::setFoodBucket(objPosArrayList* setBucket) {
    for (int i = 0; i < 5; i++) { //remove all of the current positions
        foodBucket->removeHead();
    }
    objPos tempLoc;
    for (int i = 0; i < 5; i++) {
        setBucket->getElement(tempLoc, i);
        foodBucket->insertHead(tempLoc);
    }
}