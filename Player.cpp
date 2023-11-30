#include "Player.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    // more actions to be included
    playerPosList = new objPosArrayList();
    objPos temp(mainGameMechsRef->getBoardSizeX() / 2, mainGameMechsRef->getBoardSizeY() / 2, '*'); // create a temporary objPos object
    playerPosList->insertHead(temp);


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
        case ' ':
            mainGameMechsRef->setExitTrue();
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

    int ySize = mainGameMechsRef->getBoardSizeY();
    int xSize = mainGameMechsRef->getBoardSizeX();
    
    if (Y == 0) {
        Y = ySize - 1;
    }
    else if (Y == ySize) {
    Y = 1;
    }
    if (X == 0) {
        X = xSize - 1;
    }
    else if (X == xSize) {
        X = 1;
    }

    objPos updatedHead(X,Y,'*');
    playerPosList->insertHead(updatedHead);

    playerPosList->removeTail();
}

void Player::growSnake()
{
    objPos tail;
    playerPosList->getTailElement(tail);

    objPos newTail(tail.x, tail.y, '*');

    playerPosList->insertTail(newTail);
}

