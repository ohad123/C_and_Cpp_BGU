/* Assignment C++: 1
   Author: Ohad Adi, ID: 315636753
           Tslil Sardam, ID:209488717
*/
#ifndef STACKNODE_H
#define STACKNODE_H

#include <iostream>
using namespace std;

class StackNode{
private:
    int data;
    StackNode* next;

public:
    StackNode(int data = 0, StackNode* next = NULL);
    void update_next(StackNode* next);
    void update_data(int data);
    int get_data() const;
    StackNode * get_next() const;
    ~StackNode();
};

#endif