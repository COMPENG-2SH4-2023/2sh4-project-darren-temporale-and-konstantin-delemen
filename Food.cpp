#include "Food.h"

#include <stdlib.h>
 
Food::Food(){
    //Default Symbol = O

    foodPos = objPos(0,0,'O');
   
    objPos tempPlayer(30/2,15/2,'O');
    generateFood(foodPos,tempPlayer,30,15);//generating positions from the default game size
}
 
Food::Food(char s, objPos &blockOff, int xRange, int yRange){
    foodPos = objPos(0,0,s);
   
    generateFood(foodPos, blockOff, xRange, yRange);
}
 
Food::Food(Food &o){
    foodPos = o.foodPos;
}

void Food::generateFood(objPos &returnPos, objPos blockOff, int xRange, int yRange){
    int xtemp, ytemp, match;
    do{
            match = 1;
            xtemp = (rand() % (xRange));//This range is from 0 to range-1
            ytemp = (rand() % (yRange));

            if(xtemp == 0 || ytemp == 0){
                match = 0;
            }
 
            if(xtemp == blockOff.x && ytemp == blockOff.y){ //If the randomly generated x and y valuse match the player, repete the do while loop
                match = 0;
            }
        } while(!match);
 
        //If we have broken out of the do while loop, the temp x and y values dont conflict with anything - so we can use them
        returnPos.x = xtemp;
        returnPos.y = ytemp;
}
 
void Food::getFoodPos(objPos &returnPos){
    returnPos = foodPos;
}