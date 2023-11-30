#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "Player.h"
#include "Food.h"
 
#include "time.h"
#include <stdlib.h>
 
 
using namespace std;
 
#define DELAY_CONST 100000
 
GameMechs *gameMech; //I am open to better names for this
Food *food; //I am open to better names for this
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
    food = new Food('O', tempPlayerPos, x, y); //using the default symbol  O
 
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
    objPos foodLoc;
    food->getFoodPos(foodLoc);

    if(snakeHead.isPosEqual(&foodLoc))
    {
        gameMech->incrementScore();

        food->generateFood(food->foodPos,snakeHead, gameMech->getBoardSizeX(), gameMech->getBoardSizeY());

        player->growSnake();
    }
}

void DrawScreen(void)
{
    MacUILib_clearScreen();
    
    objPos tempFood;
    food->getFoodPos(tempFood);
    objPosArrayList *snakeBody = new objPosArrayList();
    player->getPlayerPosList(snakeBody);

    objPos tempPlayerPos;
    player->getPlayerPos(tempPlayerPos);
 
    gameMech->printBoard(tempPlayerPos,snakeBody, tempFood);
}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}

 
void CleanUp(void)
{
    MacUILib_clearScreen();  
 
    delete food;
 
    delete player;

    delete gameMech;
 
    MacUILib_uninit();
}