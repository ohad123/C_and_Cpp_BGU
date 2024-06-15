/* Assignment C++: 1
   Author: Ohad Adi, ID: 315636753
           Tslil Sardam, ID:209488717
*/


#include "DispenserType.h"

DispenserType::DispenserType(int numberOfItems, int cost) {
    this->numberOfItems = numberOfItems;
    this->cost = cost;
}

DispenserType::~DispenserType() {}

int DispenserType::getNoOfItems() const {
    return this->numberOfItems;
}

int DispenserType::getCost() const {
    return this->cost;

}

void DispenserType::makeSale() {
    this->numberOfItems -= 1;
}
