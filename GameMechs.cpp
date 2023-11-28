#include "GameMechs.h"

GameMechs::GameMechs(){
    boardSizeX = 30;//default board sizes
    boardSizeY = 15;

    score = 0;

    exitFlag = 0;
    loseFlag = 0;

}

GameMechs::GameMechs(int boardX, int boardY){
    boardSizeX = boardX;
    boardSizeY = boardY;

    score = 0;

    exitFlag = 0;
    loseFlag = 0;
}

GameMechs::GameMechs(GameMechs &o){
    boardSizeX = o.boardSizeX;
    boardSizeY = o.boardSizeY;

    score = o.score;

    exitFlag = o.exitFlag;
    loseFlag = o.loseFlag;
}

// do you need a destructor?


bool GameMechs::getExitFlagStatus(){
    return exitFlag;
}

bool GameMechs::getLoseFlagStatus(){
    return loseFlag;
}

void GameMechs::setExitTrue(){
    exitFlag = 1;
}

char GameMechs::getInput(){
    return input;
}

void GameMechs::setInput(char this_input){
    input = this_input;
}

void GameMechs::clearInput(){
    input = '\0';
}

int GameMechs::getScore(){
    return score;
}

void GameMechs::incrementScore(){
    score++;
}

int GameMechs::getBoardSizeX(){
    return boardSizeX;
}

int GameMechs::getBoardSizeY(){
    return boardSizeY;
}
/*
bool GameMechs::detectCollFood(objPos playerPos, objPos foodPos){
    if(playerPos.y == foodPos.y && playerPos.x == foodPos.x){
        return 1;
    }
    else{
        return 0;
    }
}
 
bool GameMechs::detectCollBody(objPosArrayList snake){
    objPos sHead(0,0,'x');
    sHead.setObjPos(snake.aList[0]);
 
    objPos sBody(0,0,'x');
 
    for(int i=1;i<snake.sizeList;i++){
        sBody.setObjPos(snake.aList[i]);
        if(sHead.y == sBody.y && sHead.x = sBody.x){
            return 1;
        }
    }
    return 0;
}
*/