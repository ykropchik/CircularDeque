//
// Created by YKROPCHIK on 24.04.2020.
//
#define SUCCESS true;
#define FAIL false;
#define EMPTYDEQUE "Empty deque"

class CircularDeque {
private:
    int *data;
    unsigned int leftBorder;
    unsigned int rightBorder;
    unsigned int maxSize;

public:
    explicit CircularDeque(unsigned int size);
    CircularDeque(const CircularDeque &deque);
    ~CircularDeque();
    bool pushBack(int item);
    bool pushFront(int item);
    int popBack();
    int popFront();
    unsigned int getLength();
    void print();
    void printAll();                                    // Для отладки

    CircularDeque& operator =(const CircularDeque &deque);
};

