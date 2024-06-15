/* Assignment C++: 1
   Author: Ohad Adi, ID: 315636753
           Tslil Sardam, ID:209488717
*/


#include "StackNode.h"
#include <iostream>
using namespace std;


StackNode::StackNode(int data, StackNode *next) {
    this->data = data;
    this->next = next;
}

void StackNode::update_data(int data) {
    this->data = data;
}

void StackNode::update_next(StackNode *next) {
    this->next = next;
}

int StackNode:: get_data() const {
    return this->data;
}

StackNode * StackNode:: get_next() const{
    return this->next;
}

StackNode::~StackNode() {}