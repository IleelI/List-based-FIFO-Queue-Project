#ifndef INC_3__LIST_BASED_FIFO_QUEUE_QUEUE_H
#define INC_3__LIST_BASED_FIFO_QUEUE_QUEUE_H
#include "List.h"

class Queue : public List {
private:
  Node* first;
  Node* last;
  unsigned queueCount;
  void Expand(int value);
  void Replace(int value);
  Node* DeleteEmptyElement(Node* curr);
public:
  Queue();
  void Push(int value);
  void Pop();
  void InsertStart(int value) override;
  void InsertEnd(int value) override;
  void DeleteStart() override;
  void DeleteEnd() override;
  void GarbageSoft();
  void GarbageHard();
  void IncreaseQueueCount();
  void DecreaseQueueCount();
  void PrintQueue() const;
  void PrintQueueCount() const;
  ~Queue() override;
};



#endif