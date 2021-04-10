#include "Queue.h"
#include <iostream>

//Constructor
Queue::Queue() {
  first = last = nullptr;
  queueCount = 0;
}

//Insertion
void Queue::Expand(int value) {
  Node* oldLast = last;
  Node* prevLast = last->GetPrev();
  last = new Node(value);
  last->SetState(true);
  last->SetNext(oldLast);
  last->SetPrev(prevLast);
  prevLast->SetNext(last);
  oldLast->SetPrev(last);
  if (oldLast == head) {
    head = last;
    head->SetNext(oldLast);
    head->SetPrev(tail);
  }
  IncreaseListSize();
}
void Queue::Replace(int value) {
  last = last->GetPrev();
  last->SetState(true);
  last->SetData(value);
}
void Queue::Push(int value) {
  if (listSize == 0) {
    InsertInitial(value);
    head->SetState(true);
    first = last = tail;
  }
  else if (queueCount == 0) {
    tail->SetState(true);
    tail->SetData(value);
    first = last = tail;
  }
  else if (queueCount == listSize)
    Expand(value);
  else
    Replace(value);
  IncreaseQueueCount();
}

//Deletion
void Queue::Pop() {
  if (listSize == 0 || queueCount == 0) {
    std::cout << "NULL" << std::endl;
    return;
  }
  std::cout << first->GetData() << std::endl;
  first->SetState(false);
  first = first->GetPrev();
  DecreaseQueueCount();
}
void Queue::DeleteStart() {
  if (!head)
    return;
  else {
    if (head == tail)
      head = tail = first = last = nullptr;
    else {
      Node* tmp = head;
      head = head->GetNext();
      head->SetPrev(tail);
      tail->SetNext(head);
      if (tmp->GetState()) {
        DecreaseQueueCount();
        if (queueCount == 0)
          first = last = nullptr;
        else {
          if (tmp == first)
            first = tmp->GetPrev();
          else if (tmp == last)
            last = tmp->GetNext();
        }
      }
    }
    listSize--;
  }
}
void Queue::DeleteEnd() {
  if (!head)
    return;
  else {
    if (head == tail)
      head = tail = first = last = nullptr;
    else {
      Node* tmp = tail;
      tail = tail->GetPrev();
      tail->SetNext(head);
      head->SetPrev(tail);
      if (tmp->GetState()) {
        DecreaseQueueCount();
        if (queueCount == 0) // If last element of list if start of queue or sizeOfQueue = 0
          first = last = nullptr;
        else if (tmp == first)
          first = first->GetPrev();
        else if (tmp == last) // If last element of list is end of queue.
            last = last->GetNext();
      }
    }
    listSize--;
  }
}
Node* Queue::DeleteEmptyElement(Node* curr) {
  if (curr == head) {
    head = head->GetNext();
    head->SetPrev(tail);
    tail->SetNext(head);
  }
  else if (curr == tail) {
    tail = tail->GetPrev();
    tail->SetNext(head);
    head->SetPrev(tail);
  }
  else {
    Node* next = curr->GetNext();
    Node* prev = curr->GetPrev();
    next->SetPrev(prev);
    prev->SetNext(next);
  }
  DecreaseListSize();
  curr = curr->GetNext();
  return curr;
}
void Queue::GarbageHard() {
  if (queueCount == 0) {
    head = tail = nullptr;
    listSize = 0;
    delete head;
    delete tail;
  }
  else {
    Node* curr = head;
    while (curr != tail) {
      if (!curr->GetState())
        curr = DeleteEmptyElement(curr);
      else
        curr = curr->GetNext();
    }
    if (!curr->GetState())
      DeleteEmptyElement(curr);
  }
}

//Setters
void Queue::GarbageSoft() {
  if (listSize == 0)
    return;
  else {
    Node* curr = head;
    while (curr != tail) {
      if (!curr->GetState())
        curr->SetData(0);
      curr = curr->GetNext();
    }
    if (!curr->GetState())
      curr->SetData(0);
  }
}
/*void Queue::SetFirst(Node *node) {
  first = node;
}
void Queue::SetLast(Node *node) {
  last = node;
}*/
void Queue::IncreaseQueueCount() {
  queueCount++;
}
void Queue::DecreaseQueueCount() {
  queueCount--;
}

//Getters
/*unsigned Queue::GetQueueCount() const {
  return queueCount;
}*/
/*Node* Queue::GetFirst() const {
  return first;
}
Node* Queue::GetLast() const {
  return last;
}*/

//Logging
void Queue::PrintQueueCount() const {
  std::cout << queueCount << std::endl;
}
void Queue::PrintQueue() const {
  if (queueCount == 0)
    std::cout << "NULL" << std::endl;
  else {
    Node* curr = first;
    while (curr != last) {
      if (curr->GetState())
        std::cout << curr->GetData() << " ";
      curr = curr->GetPrev();
    }
    if (curr->GetState())
      std::cout << curr->GetData() << std::endl;
  }
}
/*void Queue::PrintFullInfo() const {
  PrintQueueCount();
  PrintListSize();
  if (GetHead())
    std::cout << "Head: " << GetHead()->GetData() << std::endl;
  else
    std::cout << "Head: NULL" << std::endl;
  if (GetTail())
    std::cout << "Tail: " << GetTail()->GetData() << std::endl;
  else
    std::cout << "Tail: NULL" << std::endl;
  if (GetFirst())
    std::cout << "First: " << GetFirst()->GetData() << std::endl;
  else
    std::cout << "First: NULL" << std::endl;
  if (GetLast())
    std::cout << "Last: " << GetLast()->GetData() << std::endl;
  else
    std::cout << "Last: NULL" << std::endl;
}*/
Queue::~Queue() {
  first = last = nullptr;
  queueCount = 0;
}