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

class foodPos : public objPos{
    public:

        foodPos();//new food with the default symbol 'O' and position using default game size
        foodPos(char s, objPos &blockOff, int xRange, int yRange); //new food with specified symbol, playerPos, and game board size
        
        //foodPos(foodPos &o);//I think the copy function is inherited

        //~foodPos();//there is nothing within foodPos on the heap

        void getFoodPos(objPos &returnPos);
        void generateFood(objPos blockOff, int xRange, int yRange);
};

#endif