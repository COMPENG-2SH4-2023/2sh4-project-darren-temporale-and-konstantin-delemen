#ifndef GAMEMECHS_H
#define GAMEMECHS_H

#include <cstdlib>
#include <time.h>

#include "objPos.h"
#include "objPosArrayList.h"

using namespace std;


class GameMechs
{
    private:
        char input;
        bool exitFlag;

        bool loseFlag;  

        int score;
        
        int boardSizeX;
        int boardSizeY;

    public:
        GameMechs();
        GameMechs(int boardX, int boardY);

        GameMechs(GameMechs &o);

        bool getExitFlagStatus();
        bool getLoseFlagStatus();
        void setExitTrue();
        void setLoseTrue();

        char getInput();
        void setInput(char this_input);
        void clearInput();

        int getScore();
        void incrementScore();//increment the score by 1
        void incrementScore(int val);//increment the score by val

        int getBoardSizeX();
        int getBoardSizeY();

        void printBoard(objPos &playerLoc, objPosArrayList *snakeLoc, objPosArrayList *foodLoc);

};

#endif