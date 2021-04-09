#ifndef INC_3__LIST_BASED_FIFO_QUEUE_NODE_H
#define INC_3__LIST_BASED_FIFO_QUEUE_NODE_H


class Node {
private:
  int data;
  Node* prev;
  Node* next;
  bool isQueued;
public:
  explicit Node(int value);
  void SetData(int value);
  void SetState(bool state);
  void SetNext(Node* next);
  void SetPrev(Node* prev);
  Node* GetPrev() const;
  Node* GetNext() const;
  int GetData() const;
  bool GetState() const;
  ~Node();
};


#endif
