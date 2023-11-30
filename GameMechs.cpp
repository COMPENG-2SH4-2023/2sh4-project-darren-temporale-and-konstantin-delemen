#include "GameMechs.h"
#include "MacUILib.h"

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

void GameMechs::printBoard(objPos &playerLoc, objPosArrayList *snakeLoc, objPos foodLoc){
    int i, j, k, objPrinted = 0;
    objPos tempSnakeEle;
    for(i = 0; i <= getBoardSizeY(); i++){
        for(j = 0; j <= getBoardSizeX(); j++){
            if(i == 0 || i == getBoardSizeY() || j == 0 || j == getBoardSizeX()){
                //If we are currently at the boarders, print those symbols
                if(i == 0 || i == getBoardSizeY()){
                    MacUILib_printf("%c", '-');
                }
                else{
                    MacUILib_printf("%c", '|');
                }
            }
            else if(i == foodLoc.y && j == foodLoc.x){
                //If we are at the location of the food, print the food
                MacUILib_printf("%c", foodLoc.symbol);
            }
            else {
                objPrinted = 0;
                for(int k=0;k<(snakeLoc->getSize());k++){
                    snakeLoc->getElement(tempSnakeEle, k);
                    if(i == tempSnakeEle.y && j == tempSnakeEle.x){
                        objPrinted = 1;
                        MacUILib_printf("%c", tempSnakeEle.symbol);
                    }
                }
                if(objPrinted==0){
                    MacUILib_printf(" ");
                }
            }
        }
        MacUILib_printf("\n");
    }
}