#include "Player.h"


Player::Player(GameMechs* thisGMRef) // constructor that takes a pointer to a GameMechs object
{
    mainGameMechsRef = thisGMRef; // store the pointer as a member variable
    myDir = STOP; // initialize the direction to stop

    // more actions to be included
    playerPosList = new objPosArrayList(); // create a new list to store the player's positions
    objPos temp(mainGameMechsRef->getBoardSizeX() / 2, mainGameMechsRef->getBoardSizeY() / 2, '*'); // create a temporary objPos object at the center of the board
    playerPosList->insertHead(temp); // insert the object at the head of the list
}

Player::~Player() // destructor that deletes any heap members
{
    // delete any heap members here
    delete playerPosList; // delete the list of player’s positions
}

Player::Player(Player &o){
    mainGameMechsRef = o.mainGameMechsRef;
    myDir = o.myDir;
    playerPosList = o.playerPosList;
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

void Player::movePlayer(Food *foodObj) // a method that moves the player according to the direction and checks for collisions with food or itself
{
    objPos head; // declare a variable to store the head position 
    getPlayerPos(head); // get the head position from the list

    int X = head.x; // get the x coordinate of the head
    int Y = head.y; // get the y coordinate of the head
    switch (myDir) { // switch on the direction
            case UP: // if it is up
            Y--; // decrement the y coordinate
            break;
        case DOWN: // if it is down
            Y++; // increment the y coordinate
            break;
        case LEFT: // if it is left
            X--; // decrement the x coordinate
            break;
        case RIGHT: // if it is right
            X++; // increment the x coordinate
            break;
        case STOP: // if it is stop
            break; // do nothing
    }

    int ySize = mainGameMechsRef->getBoardSizeY(); // get the board height from the GameMechs object
    int xSize = mainGameMechsRef->getBoardSizeX(); // get the board width from the GameMechs object

    if (Y == 0) { // if the y coordinate is at the top edge
        Y = ySize - 1; // wrap it around to the bottom edge
    }
    else if (Y == ySize) { // if the y coordinate is at the bottom edge
    Y = 1; // wrap it around to the top edge
    }
    if (X == 0) { // if the x coordinate is at the left edge
        X = xSize - 1; // wrap it around to the right edge
    }
    else if (X == xSize) { // if the x coordinate is at the right edge
        X = 1; // wrap it around to the left edge
    }

    objPos updatedHead(X,Y,'*'); // create a new objPos object with the updated coordinates and the symbol '*'

    objPos foodLoc; // declare a variable to store the food position
    foodObj->getFoodPos(foodLoc); // get the food position from the food object

    objPosArrayList *snakeBody = new objPosArrayList(); // declare a pointer to store the snake body list
    *snakeBody = objPosArrayList(); // initialize the pointer to a new list
    getPlayerPosList(snakeBody); // get the snake body list from the player object

    if(updatedHead.isPosEqual(&foodLoc))//checking for a collision with food
    {
        mainGameMechsRef->incrementScore(); // increment the score in the GameMechs object

        foodObj->generateFood(foodObj->foodPos, snakeBody, mainGameMechsRef->getBoardSizeX(), mainGameMechsRef->getBoardSizeY()); // generate a new food position that does not overlap with the snake body

        playerPosList->insertHead(updatedHead); // insert the updated head position at the head of the list
    }
    else{ // if there is no collision with food
        playerPosList->insertHead(updatedHead); // insert the updated head position at the head of the list
        playerPosList->removeTail(); // remove the tail position from the list
    }


    if(snakeBody->suicideCheck()){ // check if the snake has collided with itself
        mainGameMechsRef->setLoseTrue(); // set the lose flag to true in the GameMechs object
        mainGameMechsRef->setExitTrue(); // set the exit flag to true in the GameMechs object
    }
}

void Player::growSnake() // a method that grows the snake by adding a new tail position
{
    objPos tail; // declare a variable to store the tail positio
    playerPosList->getTailElement(tail); // get the tail position from the list

    objPos newTail(tail.x, tail.y, '*'); // create a new objPos object with the same coordinates and symbol as the tail

    playerPosList->insertTail(newTail); // insert the new tail position at the tail of the list

}

