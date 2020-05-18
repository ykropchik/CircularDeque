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
     CircularDeque deque1(4);

  std::cout<<"L_deque="<<deque.getLength()<<std::endl;
deque.print();

    for (int i=1;i<8;i++){
    deque.pushFront(i);
      deque.pushFront(7*i);
     // deque.print();

   //  deque.popBack();
    }


    for (int i=1;i<8;i++){
    deque.popFront();
      deque.popFront();
     // deque.print();

   //  deque.popBack();
    }


    std::cout<<"L_deque="<<deque.getLength()<<std::endl;
deque.print();
    CircularDeque d(deque);


    std::cout<<"L_deque="<<deque.getLength()<<std::endl;
  deque.print();

    std::cout<<"L_d="<<d.getLength()<<std::endl;
  d.print();
  std::cout<<std::endl<<"-------- ====  -------------"<<std::endl;
    d=deque;
    deque1=d;

  //  deque1.popFront();

    std::cout<<"L_deque="<<deque.getLength()<<std::endl;
   deque.print();

      std::cout<<"L_deque1="<<deque1.getLength()<<std::endl;
   deque1.print() ;

    std::cout<<"L_d="<<d.getLength()<<std::endl;
   d.print();




    return 0;
}
