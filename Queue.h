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
public:
  Queue();
  void Push(int value);
  void Pop();
  void DeleteStart() override;
  void DeleteEnd() override;
  void GarbageSoft();
  void SetFirst(Node* node);
  void SetLast(Node* node);
  void IncreaseQueueCount();
  void DecreaseQueueCount();
  Node* GetFirst() const;
  Node* GetLast() const;
  unsigned GetQueueCount() const;
  void PrintQueue() const;
  void PrintQueueCount() const;
  void PrintFullInfo() const;
  ~Queue();
};



#endif