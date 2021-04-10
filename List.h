#ifndef INC_3__LIST_BASED_FIFO_QUEUE_LIST_H
#define INC_3__LIST_BASED_FIFO_QUEUE_LIST_H
#include "Node.h"

class List {
protected:
  Node* head;
  Node* tail;
  unsigned listSize;
  void InsertInitial(int value);
  void Print(Node* start, Node* end) const;
public:
  List();
  void InsertStart(int value);
  void InsertEnd(int value);
  virtual void DeleteStart();
  virtual void DeleteEnd();
  void SetHead(int value);
  void SetTail(int value);
  void IncreaseListSize();
  void DecreaseListSize();
  unsigned GetListSize() const;
  Node* GetHead() const;
  Node* GetTail() const;
  void PrintForward() const;
  void PrintBackward() const;
  void PrintListSize() const;
  virtual ~List();
};


#endif
