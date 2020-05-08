#include <iostream>
#include "src/circDeque.h"

void test(CircularDeque deque){
    deque.pushBack(88);
    deque.printAll();
}

int main() {
//    auto deque = CircularDeque(10);
//
//    deque.pushBack(12);
//    deque.pushBack(3);
//    deque.pushFront(5);
//    deque.pushBack(1);
//    deque.pushFront(14);
//    deque.pushFront(10);
//    deque.pushFront(6);
//    deque.print();
//
//    auto deque1 = CircularDeque(5);
//
//    /// Appropriation test
//    deque1 = deque;
//    deque1.print();
//
//    /// Copy test
//    test(deque);
//
//    try {
//        std::cout << deque.popBack() << std::endl;
//        std::cout << deque.popFront() << std::endl;
//    } catch (std::string exception){
//        std::cout << exception;
//    }
//
//    deque.print();

    CircularDeque deque(15);

    for (int i=1;i<7;i++){
        deque.pushBack(i);
        deque.pushBack(i*5);
        deque.popFront();
    }

    deque.print();
    std::cout<<"L="<<deque.getLength()<<std::endl;

    CircularDeque d(deque);

    deque.print();
    std::cout<<"L="<<deque.getLength()<<std::endl;

    d.print();
    std::cout<<"L="<<d.getLength()<<std::endl;

    d=d;

    d.print();
    std::cout<<"L="<<d.getLength()<<std::endl;

    return 0;
}
