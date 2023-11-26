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
    delete mainGameMechsRef;
}

void Player::getPlayerPos(objPos &returnPos)
{
    // return the reference to the playerPos array list

}

void Player::updatePlayerDir()
{
    // PPA3 input processing logic
     switch (gameMech.getInput()) {
            case 'w':
                myDir = UP;
                break;
            case 's':
                myDir = DOWN;
                break;
            case 'a':
                myDir = LEFT;
                break;
            case 'd':
                myDir = RIGHT;
                break;
            default:
                myDir = STOP;
                break;
        }
    gameMech.clearInput();
}

void Player::movePlayer()
{
    // PPA3 Finite State Machine logic
}

