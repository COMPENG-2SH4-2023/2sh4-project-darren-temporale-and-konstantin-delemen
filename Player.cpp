#include "Player.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    // more actions to be included
    playerPosList = new objPosArrayList();
    //playerPosList->insertHead(objPos(0, 0, '@'));


}

Player::~Player()
{
    // delete any heap members here
    delete mainGameMechsRef;
    delete playerPosList;
}

void Player::getPlayerPos(objPos &returnPos)
{
    // return the reference to the playerPos array list
    playerPosList->getHeadElement(returnPos);
}

void Player::getPlayerPosList(objPosArrayList* &returnList)
{
    returnList = playerPosList;
}

void Player::updatePlayerDir()
{
    // PPA3 input processing logic
        switch (mainGameMechsRef->getInput()) {
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
    mainGameMechsRef->clearInput();
}

void Player::movePlayer()
{
    objPos head;
    getPlayerPos(head);

    int X = head.x;
    int Y = head.y;
    switch (myDir) {
            case UP:
            Y--;
            break;
        case DOWN:
            Y++;
            break;
        case LEFT:
            X--;
            break;
        case RIGHT:
            X++;
            break;
        case STOP:
            break;
    }

    //playerPosList->insertHead(objPos(X, Y, '@'));

    playerPosList->removeTail();
    /*
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
    */
}

