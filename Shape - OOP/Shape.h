/* Assignment C++: 3
   Author: Ohad Adi, ID: 315636753
           Tslil Sardam, ID:209488717
*/


#ifndef ASSIGNMENT3_SHAPE_H
#define ASSIGNMENT3_SHAPE_H
#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

class Shape{
private:
    string color;
public:
    Shape(string color);
    Shape();
    string getColor() const;
    virtual double getPerimeter() const = 0;
    virtual double getArea() const = 0;
    virtual bool operator == (const Shape& other)const;
    virtual ~Shape();
    virtual void toOs(ostream& os) const {};
    friend ostream& operator<<(ostream& os, const Shape& b);

};









#endif //ASSIGNMENT3_SHAPE_H
