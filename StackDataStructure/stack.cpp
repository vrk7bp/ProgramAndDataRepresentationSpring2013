//Venkata-Gautam Kanumuru, vrk7bp, stack.cpp, February 6th 2013

#include <iostream>
#include <string>
#include "stack.h"

using namespace std;

stack::stack() {
  //*storage = new int[3]; //
  //topValue = storage[0];
  currentSize = 0;
  trackPosition = -1;
  arrayTracker = 3; //
}

void updateArray();

void stack::push(int x) {
  updateArray();
  storage[currentSize] = x;
  //*topValue = (*storage)[currentSize];
  trackPosition++;
  currentSize++;
}

int stack::top() {
  //return (*storage)[currentSize-1];
  return storage[trackPosition];
}

void stack::pop() {
  //*topValue = (*storage)[currentSize - 2];
  storage[currentSize - 1] = 0;
  trackPosition--;
  currentSize--;
}

bool stack::empty() {
  if(currentSize == 0) {
    return true;
  }
  else
    return false;
}

void stack::updateArray() {
  int tracker = currentSize + 1;
  int* oldArray = storage;
  storage = new int[arrayTracker + 6]; //
  for(int x = 0; x < arrayTracker; x++) {
    storage[x] = oldArray[x];
  }

  //delete [] oldArray;
  /* int newArray [arrayTracker + 6]; //
  if(tracker >= arrayTracker) {
    for(int x = 0; x < arrayTracker; x++) {
      int intermediate = (*storage)[x];
      newArray[x] = intermediate;
    }
    *storage = newArray;
    arrayTracker += 6; //
    } */
}

void stack::printArray() {
  for(int x = 0 ; x < arrayTracker; x++) {
    cout << storage[x] << endl;
  }
}
