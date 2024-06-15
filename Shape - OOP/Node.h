/* Assignment C++: 3
   Author: Ohad Adi, ID: 315636753
           Tslil Sardam, ID:209488717
*/


#ifndef ASSIGNMENT3_NODE_H
#define ASSIGNMENT3_NODE_H
#include "Circle.h"
#include "Square.h"
#include "OrthogonalTriangle.h"
#include<iostream>
using namespace std;
template<class T>
class Node {
private:
    T data; /* The data stored in the node */
    Node<T>  *next; /* A pointer to the next node in the linked list */

public:
    Node(T data) { // constructor
        this->data = data;
        this->next = nullptr;
    }

    T& getData() {
        return this->data;
    }

    Node<T>* getNext() const {
        return this->next;
    }

    void setNext(Node<T>* New) {
        this->next = New;
    }

    Node(){}

};

#endif //ASSIGNMENT3_NODE_H
