#include "objPos.h"

objPos::objPos()
{
    x = 0;
    y = 0;
    symbol = 0; //NULL
}

objPos::objPos(objPos &o)
{
    x = o.x;
    y = o.y;
    symbol = o.symbol;
}


objPos::objPos(int xPos, int yPos, char sym)
{
    x = xPos;
    y = yPos;
    symbol = sym;
}

void objPos::setObjPos(objPos o)
{
    x = o.x;
    y = o.y;
    symbol = o.symbol;
}

void objPos::setObjPos(int xPos, int yPos, char sym)
{
    x = xPos;
    y = yPos;
    symbol = sym;
}

void objPos::getObjPos(objPos &returnPos)
{
    returnPos.setObjPos(x, y, symbol);
}

char objPos::getSymbol()
{
    return symbol;
}

bool objPos::isPosEqual(const objPos* refPos)
{
    return (refPos->x == x && refPos->y == y);
}

char objPos::getSymbolIfPosEqual(const objPos* refPos)
{
    if(isPosEqual(refPos))
        return getSymbol();
    else
        return 0;
}


//========Food SubClass===========

foodPos::foodPos():objPos(){
    symbol = 'O';
    //need to generate the initial position - need player pos and game board size
    x = 5;
    y = 5;
}

foodPos::foodPos(char s):objPos(){
    symbol = s;
    //again need to generate the position
    x = 5;
    y = 5;
}

foodPos::foodPos(foodPos &o){
    x = o.x;
    y = o.y;
    symbol = o.symbol;
}

void foodPos::generateFood(blockOff:objPos,xRange,yRange){
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

        //If we have broken out of the do while loop, the temp x and y values dont match anything else in use - so add them to the list
        this.x = xtemp;
        this.y = ytemp;
}

void foodPos::getFoodPos(returnPos:objPos&){
    returnPos.x = x;
    returnPos.y = y;
    returnPos.symbol = '\0';
}