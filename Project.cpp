#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "Player.h"
 
#include "time.h"
#include <stdlib.h>
 
 
using namespace std;
 
#define DELAY_CONST 100000
 
GameMechs *gameMech; //I am open to better names for this
foodPos *food; //I am open to better names for this
Player *player;
 
void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);
 
 
 
int main(void)
{
 
    Initialize();
 
    while(!gameMech->getExitFlagStatus())  
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }
 
    CleanUp();
 
}
 
 
void Initialize(void)
{
    gameMech = new GameMechs();
    //this is using the default game size (30 by 15), specify in () if wawnt diff size
 
    player = new Player(gameMech);
 
    srand(time(NULL));
 
    objPos tempPlayerPos(0,0,'s');
    player->getPlayerPos(tempPlayerPos);//This all gets the elements that the food has to avoid
    int x = gameMech->getBoardSizeX();
    int y = gameMech->getBoardSizeY();
    food = new foodPos('O', tempPlayerPos, x, y); //using the default symbol
 
    MacUILib_init();
    //MacUILib_clearScreen();
}
 
void GetInput(void)
{
   if(MacUILib_hasChar()){
        gameMech->setInput(MacUILib_getChar());
   }
}
 
void RunLogic(void)
{
    player->updatePlayerDir();
    player->movePlayer();
    
    objPos snakeHead;
    player->getPlayerPos(snakeHead);
    objPos foodPos;
    food->getFoodPos(foodPos);

    if(snakeHead.isPosEqual(&foodPos))
    {
        gameMech->incrementScore();

        food->generateFood(snakeHead, gameMech->getBoardSizeX(), gameMech->getBoardSizeY());

        player->growSnake();
    }
}

void DrawScreen(void)
{
    MacUILib_clearScreen();
    int i, j, k, objPrinted = 0;
    objPos tempFood;
    food->getFoodPos(tempFood);
    objPosArrayList *snakeBody = new objPosArrayList();
    player->getPlayerPosList(snakeBody);
    objPos tempSnakeEle;
 
    for(i = 0; i <= gameMech->getBoardSizeY(); i++){
        for(j = 0; j <= gameMech->getBoardSizeX(); j++){
            if(i == 0 || i == gameMech->getBoardSizeY() || j == 0 || j == gameMech->getBoardSizeX()){
                //If we are currently at the boarders, print those symbols
                if(i == 0 || i == gameMech->getBoardSizeY()){
                    MacUILib_printf("%c", '-');
                }
                else{
                    MacUILib_printf("%c", '|');
                }
            }
            else if(i == tempFood.y && j == tempFood.x){
                //If we are at the location of the food, print the food
                    MacUILib_printf("%c", tempFood.symbol);
            }
            else {
                objPrinted = 0;
                for(int k=0;k<(snakeBody->getSize());k++){
                    snakeBody->getElement(tempSnakeEle, k);
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

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}

 
void CleanUp(void)
{
    MacUILib_clearScreen();  
 
    delete gameMech;
 
    delete food;
 
    delete player;
 
    MacUILib_uninit();
}