/* Assignment C++: 2
   Author: Ohad Adi, ID: 315636753
           Tslil Sardam, ID:209488717
*/

#include "Set.h"

Set::Set(){
        this->maxSize = 1000;
        arr = new int [maxSize];
        currentSize = 0;
}

Set::Set(int maxSize) {
    this->maxSize = maxSize;
    arr = new int[maxSize];
    currentSize = 0;
}

/* Copy ctor */
Set::Set(const Set &obj) {
    arr = new int [obj.maxSize]; /* Creating new arr for deep copy */
    for(int i = 0; i < obj.currentSize; i++){
        arr[i] = obj.arr[i];
    }
    maxSize = obj.maxSize;
    currentSize = obj.currentSize;
}

int Set::getCurrentSize() const {
    return currentSize;
}

const Set& Set::operator=(const Set& other){
    if(this!= &other) {
        int *temp = new int[other.maxSize];
        for (int i = 0; i < other.maxSize; i++) {
            temp[i] = other.arr[i]; /* Copy the current arr to the new one */
        }
        delete[] arr; /* Deleting the array to avoid a memory leak */
        this->arr = temp;
        this->currentSize = other.currentSize;
        this->maxSize = other.maxSize;
    }
    return *this;
}

Set& Set::operator+=(int num){
    /* Check if the element is already in the array */
    for(int i = 0; i < currentSize ; i++)
    {
        if (arr[i] == num)
        {
            return *this;
        }
    }

    /* Check if we are in the limit of the set */
    if(currentSize < maxSize)
    {
        arr[currentSize] = num;
        currentSize++;
        return *this;
    }
    else  /* Create new array with maxSize+1 space */
    {
        int* temp = new int[maxSize + 1];
        for(int i = 0; i < maxSize; i++)
        {
            temp[i] = arr[i]; /* Copy array */
        }
        temp[maxSize] = num;
        delete [] arr;
        this->arr = temp;
        maxSize ++;
        currentSize ++;
        return  *this;
    }
}

Set Set:: operator+(int num) const{
    Set newSet = *this; /* Copy ctor */
    newSet += num;
    return newSet;
}

Set operator+(int num, const Set& other) {
    return (other + num);
}

Set Set::operator+(const Set& other) const{
    Set newSet(currentSize + other.currentSize); /* Creating new object */
    /* Copy the and concatenate the arrays*/
    for (int i = 0; i < currentSize; i++) {
        newSet.arr[i] = arr[i];
    }
    for (int i = 0; i < other.currentSize; i++) {
        newSet.arr[i + currentSize] = other.arr[i];
    }
    newSet.currentSize = newSet.maxSize;
    return newSet;
}

bool Set:: operator>(const Set& other) const{
    if(currentSize > other.currentSize){
        return true;
    }
    else{
        return false;
    }
}

const int& Set::operator[](int i) const {
    return arr[i];
}

ostream& operator<<(ostream& os, const Set& set){
    os << "{" ;
    if(set.currentSize != 0)
        os << set.arr[0];
    for (int i = 1; i < set.currentSize; i++) {
        os << ", " << set.arr[i];
    }
    os << "}";
    return os;
}

Set::~Set()
{
    delete [] arr; /* Delete the memory of the array we allocated */
}