#include "Node.h"

//Constructor
Node::Node(int value) {
  data = value;
  prev = next = nullptr;
  isQueued = false;
}

//Setters
void Node::SetData(int value) {
  data = value;
}
void Node::SetState(bool state) {
  isQueued = state;
}
void Node::SetPrev(Node* newPrev) {
  prev = newPrev;
}
void Node::SetNext(Node *newNext) {
  next = newNext;
}
//Getters
int Node::GetData() const {
  return data;
}
bool Node::GetState() const {
  return isQueued;
}
Node* Node::GetPrev() const {
  return prev;
}
Node* Node::GetNext() const {
  return next;
}

//Deconstructor
Node::~Node() {
  data = 0;
  prev = next = nullptr;
  isQueued = false;
  delete prev;
  delete next;
}