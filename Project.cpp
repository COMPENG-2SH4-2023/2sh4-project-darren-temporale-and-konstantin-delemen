#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"

#include "time.h"
#include <stdlib.h>


using namespace std;

#define DELAY_CONST 100000

GameMechs *gameMech; //I am open to better names for this
foodPos *food; //I am open to better names for this

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

    food = new foodPos(); //using the default symbol

    MacUILib_init();
    MacUILib_clearScreen();

    srand(time(NULL));

    //exitFlag = false;
    gameMech<-setExitFlagTrue();
}

void GetInput(void)
{
   if(MacUILib_hasChar()){
        gameMech<-setInput(MacUILib_getChar());
   }
}

void RunLogic(void)
{
    


    gameMech.incrementScore();
}

void DrawScreen(void)
{
    MacUILib_clearScreen();    
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
  
    MacUILib_uninit();
}
