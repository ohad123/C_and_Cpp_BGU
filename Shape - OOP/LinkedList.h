/* Assignment C++: 3
   Author: Ohad Adi, ID: 315636753
           Tslil Sardam, ID:209488717
*/


#ifndef ASSIGNMENT3_LINKEDLIST_H
#define ASSIGNMENT3_LINKEDLIST_H

using namespace std;
#include "Node.h"
#include <typeinfo>

template <class T>
class LinkedList {
private :
    Node<T> *head; /* A pointer to the first node in the linked list. */
public:
    LinkedList() { /* A default constructor that creates an empty linked list. */
        this->head = nullptr;
    }

    void insert(const T &item) {  /* his method should create a new Node object with the given data and insert it at the front of the linked list (at the top of the list). */
        Node<T> *node = new Node<T>(item);
        node->setNext(this->head);
        this->head = node;
    }

    T deleteNode() { /* This method should delete the first Node in the list (the last insertedNode) and return the data member of this Node. In case the list is empty, the function throws an exception. */
        if (!this->head) {
            throw "Exception: The List is empty!";
        } else {
            T data = this->head->getData(); /* use the copy constructor */
            Node<T> *temp = this->head;
            this->head = head->getNext();
            delete temp;
            return data;
        }
    }

    T deleteNode(const T &data) { /*This method should delete the first occurrence of a Node with the given data from the linked list and return the data member of this Node. If the Node is not found, the method should throw an exception.  */
        if (!this->head) {
            throw "Exception: The List is empty!";
        }
        Node<T> *temp = this->head;
        Node<T> *preTemp = nullptr;

        while (temp) {

            if (typeid(*data) == typeid(*temp->getData())) {
                if (*data == *temp->getData()) {
                    if (preTemp) {
                        preTemp->setNext(temp->getNext());
                        T retData = temp->getData();
                        delete temp;
                        return retData;
                    } else {
                        return deleteNode();
                    }
                }
            }
            preTemp = temp; /* save previous */
            temp = temp->getNext();
        }
        throw "Exception: Data not found";
    }

    bool search(const T& obj){
        if (!this->head) {
            throw "Exception: The List is empty!";
        }
        Node<T> *temp = this->head;

        while (temp) {
            if (typeid(obj) == typeid(temp->getData())) {
                Shape* check = temp->getData();
                if (*check == *obj) {
                    return true;
                }
            }
            temp = temp->getNext();
        }
        return false;
    }

    const T& getTop() const {
        if (!this->head) {
            throw "Exception: The List is empty!";
        }
        return this->head->getData();
    }

    Node<T>* getHead() const{
        return this->head;
    }


    friend ostream& operator<<(ostream& os, const LinkedList& lst){
        if (!(lst.getHead()))
            os << "The list is empty";

        Node<T>* obj = lst.getHead(); 

        while (obj)
        {
            os << (obj->getData()) << endl;
            obj = obj->getNext();

        }
        return os;

    }
    ~LinkedList() {
        Node<T> *obj = this->head;
        Node<T> *temp;

        while (obj) {
            temp = obj->getNext();
            delete obj->getData();
            delete obj;
            obj = temp;
        }
    }
};




#endif //ASSIGNMENT3_LINKEDLIST_H
