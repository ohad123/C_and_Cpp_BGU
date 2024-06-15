/* Assignment C++: 3
   Author: Ohad Adi, ID: 315636753
           Tslil Sardam, ID:209488717
*/

#ifndef ASSIGNMENT3_SQUARE_H
#define ASSIGNMENT3_SQUARE_H
#include <iostream>
#include <string>
#include <cstring>
#include "Shape.h"

using namespace std;
class Square : public Shape{
private:
    double side;
public:
    Square(string color, double side);
    Square();
    double getSide() const { return side; }
    void draw() const;
    virtual ~Square();
    virtual double getArea() const;
    virtual double  getPerimeter() const;
    Square (const Square& square);
    virtual bool operator == (const Shape& item) const;
    virtual void toOs(ostream& os) const override;
};
#endif //ASSIGNMENT3_SQUARE_H
