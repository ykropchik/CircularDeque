//
// Created by YKROPCHIK on 24.04.2020.
//
#include "circDeque.h"
#include "iostream"


CircularDeque::CircularDeque(unsigned int size) {
    this->maxSize = size;
    this->leftBorder = 0;
    this->rightBorder = size;
    this->data = new int[maxSize + 1];
}

CircularDeque::CircularDeque(const CircularDeque &deque) {
    maxSize = deque.maxSize;
    leftBorder = deque.leftBorder;
    rightBorder = deque.rightBorder;
    data = new int [maxSize + 1];
    for (int i = 0; i < maxSize + 1; ++i) {
        data[i] = deque.data[i];
    }
}

CircularDeque::~CircularDeque() {
    delete[] data;
}

bool CircularDeque::pushBack(int item) {
    if ((leftBorder - rightBorder == 2) || (rightBorder - leftBorder == (maxSize - 1))) {
        return FAIL;
    }

    if (rightBorder == maxSize) {
        rightBorder = 0;
    } else {
        rightBorder++;
    }

    data[rightBorder] = item;
    return SUCCESS;
}

bool CircularDeque::pushFront(int item) {
    if ((leftBorder - rightBorder == 2) || (rightBorder - leftBorder == (maxSize - 1))) {
        return FAIL;
    }

    if (leftBorder == 0) {
        leftBorder = maxSize;
    } else {
        leftBorder--;
    }

    data[leftBorder] = item;
    return SUCCESS;
}

int CircularDeque::popBack() {
    if ((leftBorder - rightBorder == 1) || (rightBorder - leftBorder == maxSize)) {
        throw EMPTYDEQUE;
    } else {
        if (rightBorder == 0){
            rightBorder = maxSize;
            return data[0];
        } else {
            return data[rightBorder--];
        }
    }
}

int CircularDeque::popFront() {
    if ((leftBorder - rightBorder == 1) || (rightBorder - leftBorder == maxSize)) {
        throw EMPTYDEQUE;
    } else {
        if (leftBorder == maxSize){
            leftBorder = 0;
            return data[maxSize];
        } else {
            return data[leftBorder++];
        }
    }
}

unsigned int CircularDeque::getLength() {
    if ((leftBorder - rightBorder == 1) || (rightBorder - leftBorder == maxSize)) {
        return 0;
    }

    if (rightBorder < leftBorder) {
        return maxSize + 2 - (leftBorder - rightBorder);
    } else {
        return rightBorder - leftBorder + 1;
    }
}

void CircularDeque::print() {
    if (rightBorder < leftBorder) {
        for (unsigned int i = leftBorder; i <= maxSize; ++i) {
            std::cout << data[i] << " ";
        }

        for (unsigned int j = 0; j <= rightBorder; ++j) {
            std::cout << data[j] << " ";
        }
    } else {
        for (unsigned int i = leftBorder; i <= rightBorder; ++i) {
            std::cout << data[i] << " ";
        }
    }


    std::cout << std::endl;

}

void CircularDeque::printAll() {
    for (int i = 0; i < maxSize+1; ++i) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
}

CircularDeque& CircularDeque::operator =(const CircularDeque &deque){
    if (this == &deque) {
        return *this;
    }
    bool added = true;

    if (deque.leftBorder > deque.rightBorder) {

        for (unsigned int i = deque.leftBorder; (i < deque.maxSize + 1) && (added); ++i) {
            added = this->pushBack(deque.data[i]);
        }

        for (unsigned int i = 0; (i < deque.rightBorder + 1) && (added); ++i) {
            added = this->pushBack(deque.data[i]);
        }
    } else {
        for (unsigned int i = deque.leftBorder; (i < deque.rightBorder + 1) && (added); ++i) {
            added = this->pushBack(deque.data[i]);
        }
    }

    return *this;
}
