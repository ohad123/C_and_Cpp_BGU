/* Assignment C++: 3
   Author: Ohad Adi, ID: 315636753
           Tslil Sardam, ID:209488717
*/

#include "Shape.h"


Shape::Shape(string color) /* constructor */
{
    if ((color != "red") && (color != "blue") && (color != "green"))
    {
        throw  "Exception: color must be red green or blue";
    }
    this->color = color;
}

string Shape::getColor() const {
    return this->color;
}

bool Shape::operator==(const Shape &other) const {
    if(this->color == other.getColor())
        return true;
    else
        return false;
}

Shape::Shape(){} /* default constructor */
Shape::~Shape(){} /* destructor */

ostream& operator<<(ostream& os, const Shape& b){
    b.toOs(os);
    return os;
}