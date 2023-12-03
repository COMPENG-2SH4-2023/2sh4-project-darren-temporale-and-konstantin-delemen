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

    playerPosList = new objPosArrayList();
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
        case 'w': //if the input is up and the player is not currently going down, set direction to up
            if(myDir != DOWN) {
                myDir = UP;
            }
            break;
        case 's': //if the input is down and the player is not currently going up, set direction to down
            if(myDir != UP) {
                myDir = DOWN;
            }
            break;
        case 'a': //if the input is left and the player is not currently going right, set direction to left
            if(myDir != RIGHT) {
                myDir = LEFT;
            }
            break;
        case 'd': //if the input is right and the player is not currently going left, set direction to right
            if(myDir != LEFT) {
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

    objPosArrayList* snakeBody; // declare a pointer to store the snake body list
    getPlayerPosList(snakeBody); // get the snake body list from the player object

    bool foodColl = false; //initialize a bool to know if there has been a food collision
    objPos foodLoc; // declare a variable to store the food position

    //check for a collision with each food element
    for (int i = 0; i < (foodObj->getSizeBucket()); i++) {
        foodObj->getFoodPos(foodLoc, i); // get the food position from the food object

        if (updatedHead.isPosEqual(&foodLoc)) { //checking for a collision with food
            if (foodLoc.getSymbol() == '$') {
                //If the collision is with the special food, then increment the score by 5, and reduce the snake size by 1
                
                mainGameMechsRef->incrementScore(5); // increment the score in the GameMechs object

                objPosArrayList tempFoodBucket; //A temporaty array list to hold the new food position values
                foodObj->generateFood(&tempFoodBucket, snakeBody, mainGameMechsRef->getBoardSizeX(), mainGameMechsRef->getBoardSizeY()); // generate a new food position that does not overlap with the snake body
                foodObj->setFoodBucket(&tempFoodBucket);

                playerPosList->insertHead(updatedHead); // insert the updated head position at the head of the list

                if (playerPosList->getSize() != 2) {
                    playerPosList->removeTail();
                    //only remove the tail twice (make the snake shorter) if the snake is longer than 1 object
                }
                playerPosList->removeTail();
                foodColl = true;
            }
            else { //If the collision is with a normal food
                mainGameMechsRef->incrementScore(); // increment the score in the GameMechs object

                objPosArrayList tempFoodBucket; //A temporaty array list to hold the new food position values
                foodObj->generateFood(&tempFoodBucket, snakeBody, mainGameMechsRef->getBoardSizeX(), mainGameMechsRef->getBoardSizeY()); // generate a new food position that does not overlap with the snake body
                foodObj->setFoodBucket(&tempFoodBucket);

                playerPosList->insertHead(updatedHead); // insert the updated head position at the head of the list

                foodColl = true;
            }
        }
    }
    if (!foodColl) { // if there is no collision with food
        playerPosList->insertHead(updatedHead); // insert the updated head position at the head of the list
        playerPosList->removeTail(); // remove the tail position from the list
    }


    if (snakeBody->suicideCheck()) { // check if the snake has collided with itself
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

