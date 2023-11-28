#include "objPosArrayList.h"

// Paste your CUTE Tested implementation here.
// Paste your CUTE Tested implementation here.
// Paste your CUTE Tested implementation here.


objPosArrayList::objPosArrayList() {
    sizeArray = ARRAY_MAX_CAP;
    sizeList = 0;
    aList = new objPos[sizeArray];
}

objPosArrayList::~objPosArrayList() {
    delete[] aList;
}

int objPosArrayList::getSize() {
    return sizeList;
}

void objPosArrayList::insertHead(objPos thisPos) {
    for (int i = sizeList - 1; i >= 0; i--) {
        aList[i + 1] = aList[i];
    }
    aList[0] = thisPos;
    sizeList++;
}

void objPosArrayList::insertTail(objPos thisPos) {
    aList[sizeList - 1] = thisPos;
    sizeList++;
}

void objPosArrayList::removeHead() {
    for (int i = 1; i < sizeList; i++) {
        aList[i - 1] = aList[i];
    }
    removeTail();
}

void objPosArrayList::removeTail() {
    aList[sizeList - 1].x = 0;
    aList[sizeList - 1].y = 0;
    aList[sizeList - 1].symbol = 0;
    sizeList--;
}

void objPosArrayList::getHeadElement(objPos &returnPos) {
    returnPos.x = aList[0].x;
    returnPos.y = aList[0].y;
    returnPos.symbol = aList[0].symbol;
}

void objPosArrayList::getTailElement(objPos &returnPos) {
    returnPos.x = aList[sizeList - 1].x;
    returnPos.y = aList[sizeList - 1].y;
    returnPos.symbol = aList[sizeList - 1].symbol;
}

void objPosArrayList::getElement(objPos &returnPos, int index) {
    returnPos.x = aList[index].x;
    returnPos.y = aList[index].y;
    returnPos.symbol = aList[index].symbol;
}

