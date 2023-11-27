#ifndef OBJPOS_H
#define OBJPOS_H

class objPos
{
    public:
        int x;
        int y;
        char symbol;

        objPos();
        objPos(objPos &o); // copy constructor
        objPos(int xPos, int yPos, char sym);

        void setObjPos(objPos o);        
        void setObjPos(int xPos, int yPos, char sym);  
        void getObjPos(objPos &returnPos);
        char getSymbol();

        bool isPosEqual(const objPos* refPos);
        
        char getSymbolIfPosEqual(const objPos* refPos);
};

class foodPos : public objPos{//Need to go over class inheratence again and see if this is right
    public:

        foodPos():objPos();//create a new food with the default symbol 'O'
        foodPos(char s):objPos(); //create a new food with specified symbol
        foodPos(foodPos &o);

        //~foodPos();//there is nothing within foodPos on the heap

        void getFoodPos(returnPos:objPos&);
        void generateFood(blockOff:objPos,xRange,yRange);
};

#endif