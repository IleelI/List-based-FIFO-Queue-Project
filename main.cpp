#include <iostream>
#include "Queue.h"
#define COMMAND_SIZE 255

int main() {
  Queue* q = new Queue();
  char* command = new char[COMMAND_SIZE];
  int query;
  while (std::cin >> command)  {
    if (strcmp(command, "PUSH") == 0) {
      std::cin >> query;
      q->Push(query);
    }
    else if (strcmp(command, "ADD_BEG")== 0) {
      std::cin >> query;
      q->InsertStart(query);
    }
    else if (strcmp(command, "ADD_END") == 0) {
      std::cin >> query;
      q->InsertEnd(query);
    }
    else if (strcmp(command, "POP") == 0)
      q->Pop();
    else if (strcmp(command, "GARBAGE_HARD") == 0)
      q->GarbageHard();
    else if (strcmp(command, "GARBAGE_SOFT") == 0)
      q->GarbageSoft();
    else if (strcmp(command, "DEL_BEG") == 0)
      q->DeleteStart();
    else if (strcmp(command, "DEL_END") == 0)
      q->DeleteEnd();
    else if (strcmp(command, "PRINT_QUEUE") == 0)
      q->PrintQueue();
    else if (strcmp(command, "COUNT") == 0)
      q->PrintQueueCount();
    else if (strcmp(command, "SIZE") == 0)
      q->PrintListSize();
    else if (strcmp(command, "PRINT_FORWARD") == 0)
      q->PrintForward();
    else if (strcmp(command, "PRINT_BACKWARD") == 0)
      q->PrintBackward();
  }
  delete[] command;
  delete q;
  return 0;
}
