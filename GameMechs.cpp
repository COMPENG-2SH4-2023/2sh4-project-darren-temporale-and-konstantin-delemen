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

void GameMechs::setLoseTrue(){
    loseFlag = 1;
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

void GameMechs::incrementScore(int val){
    score += val;
}

int GameMechs::getBoardSizeX(){
    return boardSizeX;
}

int GameMechs::getBoardSizeY(){
    return boardSizeY;
}

void GameMechs::printBoard(objPos &playerLoc, objPosArrayList *snakeLoc, objPosArrayList *foodLoc){
    int i, j, k, objPrinted = 0;
    objPos tempSnakeEle;
    objPos tempFoodPos;
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
            else{
                objPrinted = 0;
                for(int k=0; k<foodLoc->getSize();k++){//Iterate through each food object position
                    foodLoc->getElement(tempFoodPos, k);

                    if(i == tempFoodPos.y && j == tempFoodPos.x){
                        //If we are at the location of the food, print the food
                        MacUILib_printf("%c", tempFoodPos.symbol);
                        objPrinted = 1;
                    }
                }
                if(objPrinted==0){//If we havent printed a food object, check if we need to print a part of the snake
                    for(int k=0;k<(snakeLoc->getSize());k++){
                        snakeLoc->getElement(tempSnakeEle, k);
                        if(i == tempSnakeEle.y && j == tempSnakeEle.x){
                            objPrinted = 1;
                            MacUILib_printf("%c", tempSnakeEle.symbol);
                        }
                    }
                    if(objPrinted==0){//if we still havent printed anything, then print a space char
                        MacUILib_printf(" ");
                    }
                }
            }
        }
        MacUILib_printf("\n");
    }
}