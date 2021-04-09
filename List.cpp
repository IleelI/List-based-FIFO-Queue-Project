#include "List.h"
#include <iostream>

List::List() {
  head = tail = nullptr;
  listSize = 0;
}

//Insertion
void List::InsertInitial(int value) {
  Node* node = new Node(value);
  node->SetNext(node);
  node->SetPrev(node);
  head = tail = node;
  listSize++;
}
void List::InsertStart(int value) {
  if (!head)
    InsertInitial(value);
  else {
    Node* tmp = head;
    head = new Node(value);
    head->SetNext(tmp);
    head->SetPrev(tail);
    tail->SetNext(head);
    tmp->SetPrev(head);
    listSize++;
  }
}
void List::InsertEnd(int value) {
  if (!head)
    InsertInitial(value);
  else {
    Node* tmp = tail;
    tail = new Node(value);
    tail->SetNext(head);
    tail->SetPrev(tmp);
    tmp->SetNext(tail);
    head->SetPrev(tail);
    listSize++;
  }
}
//Deletion
void List::DeleteStart() {
  if (!head)
    return;
  else {
    if (head == tail)
      head = tail = nullptr;
    else {
      head = head->GetNext();
      head->SetPrev(tail);
      tail->SetNext(head);
    }
    listSize--;
  }
}
void List::DeleteEnd() {
  if (!head)
    return;
  else {
    if (head == tail)
      head = tail = nullptr;
    else {
      tail = tail->GetPrev();
      tail->SetNext(head);
      head->SetPrev(tail);
    }
    listSize--;
  }
}

//Setters
void List::SetHead(int value) {
  head->SetData(value);
}
void List::SetTail(int value) {
  tail->SetData(value);
}
void List::IncreaseListSize() {
  listSize++;
}
void List::DecreaseListSize() {
  listSize--;
}

//Getters
unsigned List::GetListSize() const {
  return listSize;
}
Node* List::GetHead() const {
  return head;
}
Node* List::GetTail() const {
 return tail;
}

//Logging
void List::Print(Node* start, Node* end) const {
  if (!start)
    std::cout << "NULL" << std::endl;
  else {
    Node* curr = start;
    while (curr != end) {
      std::cout << curr->GetData() << " ";
      curr = (end == tail) ? curr->GetNext() : curr->GetPrev();
    }
    std::cout << curr->GetData() << std::endl;
  }
}
void List::PrintForward() const {
  Print(head,tail);
}
void List::PrintBackward() const {
  Print(tail,head);
}
void List::PrintListSize() const {
  std::cout << listSize << std::endl;
}
//Deconstructor
List::~List() {
  head = tail = nullptr;
  delete head;
  delete tail;
  listSize = 0;
}