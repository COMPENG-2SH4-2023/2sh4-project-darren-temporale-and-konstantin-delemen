#include "objPosArrayList.h"

// Paste your CUTE Tested implementation here.
// Paste your CUTE Tested implementation here.
// Paste your CUTE Tested implementation here.


objPosArrayList::objPosArrayList() {
    sizeArray = ARRAY_MAX_CAP; // initialize the size of the array to the maximum capacity
    sizeList = 0; // initialize the size of the list to zero
    aList = new objPos[sizeArray]; // dynamically allocate memory for the array of objPos objects
}

objPosArrayList::~objPosArrayList() {
    delete[] aList; // free the memory allocated for the array
}

int objPosArrayList::getSize() {
    return sizeList; // return the current size of the list
}

void objPosArrayList::insertHead(objPos thisPos) {
    for (int i = sizeList - 1; i >= 0; i--) { // loop from the end of the list to the beginning
        aList[i + 1] = aList[i]; // shift each element one position to the right
    }
    aList[0] = thisPos; // insert the given objPos object at the head of the list
    sizeList++; // increment the size of the list
}

void objPosArrayList::insertTail(objPos thisPos) {
    aList[sizeList - 1] = thisPos; // insert the given objPos object at the tail of the list
    sizeList++; // increment the size of the list
}

void objPosArrayList::removeHead() {
    for (int i = 1; i < sizeList; i++) { // loop from the second element to the end of the list
        aList[i - 1] = aList[i]; // shift each element one position to the left
    }
    removeTail(); // remove the last element of the list
}

void objPosArrayList::removeTail() {
    aList[sizeList - 1].x = 0; // set the x coordinate of the last element to zero
    aList[sizeList - 1].y = 0; // set the y coordinate of the last element to zero
    aList[sizeList - 1].symbol = 0; // set the symbol of the last element to zero
    sizeList--; // decrement the size of the list
}

void objPosArrayList::getHeadElement(objPos &returnPos) {
    returnPos.x = aList[0].x; // copy the x coordinate of the head element to the returnPos object
    returnPos.y = aList[0].y; // copy the y coordinate of the head element to the returnPos object
    returnPos.symbol = aList[0].symbol; // copy the symbol of the head element to the returnPos object
}

void objPosArrayList::getTailElement(objPos &returnPos) {
    returnPos.x = aList[sizeList - 1].x; // copy the x coordinate of the tail element to the returnPos object
    returnPos.y = aList[sizeList - 1].y; // copy the y coordinate of the tail element to the returnPos object
    returnPos.symbol = aList[sizeList - 1].symbol; // copy the symbol of the tail element to the returnPos object
}

void objPosArrayList::getElement(objPos &returnPos, int index) {
    returnPos.x = aList[index].x; // copy the x coordinate of the element at the given index to the returnPos object
    returnPos.y = aList[index].y; // copy the y coordinate of the element at the given index to the returnPos object
    returnPos.symbol = aList[index].symbol; // copy the symbol of the element at the given index to the returnPos object
}


bool objPosArrayList::suicideCheck(){
    objPos headLoc;

    getHeadElement(headLoc);

    //Compare the location of the snake head to the location of each body part, if theu are the same there has been a collision

    for(int i=1; i<sizeList;i++){
        if(aList[i].x == headLoc.x && aList[i].y == headLoc.y){ //If the randomly generated x and y valuse match the player, repete the do while loop
            return 1;
        }
    }

    return 0;
}