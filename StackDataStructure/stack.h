//Venkata-Gautam Kanumuru, vrk7bp, stack.h, February 6th, 2013

#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <string>

using namespace std;

class stack {
 public:
  stack();
  void push(int x);
  int top();
  void pop();
  bool empty();
  void updateArray();
  void printArray();

 private:
  int storage [3];
  int *topValue;
  int currentSize;
  int arrayTracker;
  int trackPosition;
  
};
#endif
