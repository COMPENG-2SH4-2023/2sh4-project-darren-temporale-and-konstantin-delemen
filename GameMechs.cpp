#include "GameMechs.h"

GameMechs::GameMechs()
{

}

GameMechs::GameMechs(int boardX, int boardY)
{

}

// do you need a destructor?



bool GameMechs::getExitFlagStatus()
{
    return exitFlag;
}

char GameMechs::getInput()
{
    return input;
}

int GameMechs::getBoardSizeX()
{
    return boardSizeX;
}

int GameMechs::getBoardSizeY()
{
    return boardSizeY;
}


void GameMechs::setExitTrue()
{
    exitFlag = 1;
}

void GameMechs::setInput(char this_input)
{

}

void GameMechs::clearInput()
{

}


