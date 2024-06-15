/* Assignment C++: 1
   Author: Ohad Adi, ID: 315636753
           Tslil Sardam, ID:209488717
*/
#ifndef STACK_H
#define STACK_H

#include "StackNode.h"
#include <iostream>
using namespace std;


class Stack {
private:
    StackNode* top;
public:
    Stack(); /* Initialize top to NULL. */
    void push(int element); /* Inserts a new element at the top of the stack. */
    void pop(); /* Removes the top element on the stack. If stack is empty, print “Stack is empty”. */
    bool isEmpty() const; /* Returns true if the stack is empty; otherwise, it returns false */
    int peek() const; /* Returns the top element present in the stack without modifying the stack.
    In case where the stack is empty, return INT_MIN (need to include <climits)>).
    The return type is integer. */
    ~Stack();
};

#endif