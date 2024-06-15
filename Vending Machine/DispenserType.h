/* Assignment C++: 1
   Author: Ohad Adi, ID: 315636753
           Tslil Sardam, ID:209488717
*/
#ifndef DISPENSERTYPE_H
#define DISPENSERTYPE_H

#include <iostream>
using namespace std;

class DispenserType{
    private:
        int numberOfItems;
        int cost;
    public:
        DispenserType(int numberOfItems, int cost);
        int getNoOfItems() const; /* Return the value of numberOfItems*/
        int getCost() const;	/*Return the value of cost*/
        void makeSale(); /* Reduce the number of items by 1*/
        ~DispenserType();

};

#endif