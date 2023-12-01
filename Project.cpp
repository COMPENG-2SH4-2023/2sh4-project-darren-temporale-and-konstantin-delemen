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

    objPosArrayList *snakeBody = new objPosArrayList();
    player->getPlayerPosList(snakeBody);

    if(snakeHead.isPosEqual(&foodLoc))//checking for a collision with food
    {
        gameMech->incrementScore();

        food->generateFood(food->foodPos, snakeBody, gameMech->getBoardSizeX(), gameMech->getBoardSizeY());

        player->growSnake();
    }

    if(snakeBody->suicideCheck()){
        gameMech->setLoseTrue();
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
 
    if(!gameMech->getLoseFlagStatus()){
        //If the lose flag is false, print the gameboard
        gameMech->printBoard(tempPlayerPos,snakeBody, tempFood);
        MacUILib_printf("Press W A S D To Move, Eat The Food To Grow\n");
        MacUILib_printf("Score: %d", gameMech->getScore());
        //Is there other things that should be printed out here?
    }
    else{
        MacUILib_printf("\n   You Died!\n\n   Game Over\n\n");
        MacUILib_printf("   Score: %d\n", gameMech->getScore());
        gameMech->setExitTrue();
    }
}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}

 
void CleanUp(void)
{
    //MacUILib_clearScreen();  
 
    delete food;
 
    delete player;

    delete gameMech;
 
    MacUILib_uninit();
}