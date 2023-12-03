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
 
GameMechs *gameMech;
Food *food;
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
 
    //This all gets the elements that the food has to avoid
    objPos tempPlayerPos(0, 0, 's');
    player->getPlayerPos(tempPlayerPos);
    int x = gameMech->getBoardSizeX();
    int y = gameMech->getBoardSizeY();
    food = new Food('O', tempPlayerPos, x, y); //then create a new food object using the default symbol O

    MacUILib_init();
}
 
void GetInput(void)
{
    if(MacUILib_hasChar()) {
        gameMech->setInput(MacUILib_getChar());
    }
}
 
void RunLogic(void)
{
    player->updatePlayerDir();
    player->movePlayer(food);
}

void DrawScreen(void)
{
    MacUILib_clearScreen();
    
    objPosArrayList tempFoodList;
    food->getFoodBucketList(&tempFoodList);
    objPosArrayList *snakeBody;
    player->getPlayerPosList(snakeBody);

    objPos tempPlayerPos;
    player->getPlayerPos(tempPlayerPos);
 
    if (!gameMech->getLoseFlagStatus()) {
        //If the lose flag is false, print the gameboard
        gameMech->printBoard(tempPlayerPos,snakeBody, &tempFoodList);
        MacUILib_printf("Press W A S D To Move, Eat The Food To Grow\n");
        MacUILib_printf("Score: %d", gameMech->getScore());
    }
    else {
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
    delete food;
 
    delete player;

    delete gameMech;
 
    MacUILib_uninit();
}