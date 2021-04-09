#include <iostream>
#include "Queue.h"
int main() {
  auto* q = new Queue();
  q->Push(10);
  q->Push(11);
  q->Push(12);
  q->PrintBackward();
  q->PrintQueue();
  q->InsertStart(1);
  q->InsertEnd(6);
  q->InsertStart(2);
  q->InsertStart(3);
  q->InsertEnd(5);
  q->InsertEnd(4);
  q->PrintBackward();
  q->PrintQueue();
  q->Push(13);
  q->Push(14);
  q->Push(15);
  q->Push(16);
  q->Push(17);
  q->PrintForward();
  q->PrintQueue();
  q->PrintFullInfo();



  q->DeleteEnd();
  q->PrintForward();
  q->PrintQueue();
  q->PrintFullInfo();

  q->DeleteEnd();
  q->PrintForward();
  q->PrintQueue();
  q->PrintFullInfo();

  std::cout << "START DELETION" << std::endl;

  q->DeleteStart();
  q->PrintForward();
  q->PrintQueue();
  q->PrintFullInfo();

  q->DeleteStart();
  q->PrintForward();
  q->PrintQueue();
  q->PrintFullInfo();

  q->GarbageSoft();
  q->PrintForward();
  q->PrintQueue();
  q->PrintFullInfo();
  return 0;
}
