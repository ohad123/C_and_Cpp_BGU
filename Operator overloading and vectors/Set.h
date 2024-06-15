/* Assignment C++: 2
   Author: Ohad Adi, ID: 315636753
           Tslil Sardam, ID:209488717
*/
#ifndef __SET_H
#define __SET_H

#include <iostream>
using namespace std;

class Set{
private:
    int maxSize; /* Maximal number of elements. */
    int currentSize; /* Current number of elements. */
    int* arr;
public:
    Set(); /* Initialize maxSize to 1000 and allocate memory for an integer array with the size maxSize. */
    Set(int maxSize); /* Initialize maxSize and allocate memory for an integer array with the size maxSize. */
    int getCurrentSize() const; /* Return currentSize. */
    Set(const Set& obj); /* Copy constructor. */
    ~Set(); /* Default destructor */
    const Set& operator=(const Set& other);
    Set& operator+=(int num);
    Set operator+(int num) const;
    friend Set operator+(int num, const Set& other);
    Set operator+(const Set& other) const;
    bool operator>(const Set& other) const;
    const int& operator[](int i) const;
    friend ostream& operator<<(ostream& os, const Set& set);
};
#endif // __SET_H