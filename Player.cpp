#include "Player.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    // more actions to be included
}


Player::~Player()
{
    // delete any heap members here
}

void Player::getPlayerPos(objPos &returnPos)
{
    // return the reference to the playerPos array list
    playerPos.getHeadElement(returnPos);
}

void Player::updatePlayerDir()
{
    // PPA3 input processing logic
    if (mainGameMechsRef.getInput() != 0) {
        switch (mainGameMechsRef.getInput()) {
            case ' ':
                mainGameMechsRef.setExitTrue();
                break;
            case 'w':
                if(myDir != DOWN){
                    myDir = UP;
                }
                break;
            case 's':
                if(myDir != UP){
                    myDir = DOWN;
                }
                break;
            case 'a':
                if(myDir != RIGHT){
                    myDir = LEFT;
                }
                break;
            case 'd':
                if(myDir != LEFT){
                    myDir = RIGHT;
                }
                break;
            default:
                break;
        }
    mainGameMechsRef.clearInput();
    }
}

void Player::movePlayer()
{
    switch (myDir) {
            case STOP:
                break;
            case(UP):
                mainGameMechsRef->getBoardSizeY--;
                break;
            case(LEFT):
                mainGameMechsRef->getBoardSizeX--;
                break;
            case(DOWN):
                mainGameMechsRef->getBoardSizeY++;
                break;
            case(RIGHT):
                mainGameMechsRef->getBoardSizeX++;
                break;
            default:
                break;
    }
    switch(mainGameMechsRef->getBoardSizeY) {
        case(0):
            mainGameMechsRef->getBoardSizeY = ySize-1;
            break;
        case(ySize):
            mainGameMechsRef->getBoardSizeY = 1;
            break;
        default:
            break;
    }
    switch(mainGameMechsRef->getBoardSizeX) {
        case(0):
            mainGameMechsRef->getBoardSizeX = xSize-1;
            break;
        case(xSize):
            mainGameMechsRef->getBoardSizeX = 1;
            break;
        default:
            break;
    }
}

