/* Assignment C++: 3
   Author: Ohad Adi, ID: 315636753
           Tslil Sardam, ID:209488717
*/

#include "Circle.h"

Circle::Circle() {};
Circle::Circle(string color, double radius):Shape(color) {
    if(radius <= 0){
        throw "Exception: The radius must be positive!";
    }
    else{
        this->radius = radius;
    }
}

double Circle::getArea() const {
    return (M_PI * this->radius * this->radius);
}

double Circle::getPerimeter() const {
    return (M_PI * this->radius * 2);
}

Circle::Circle(const Circle &circ): Shape(circ.getColor()) { /* copy constructor */
    this->radius = circ.getRadius();
}

double Circle::getRadius() const {
    return this->radius;
}

bool Circle::operator==(const Shape &item) const {
    if (!Shape::operator==(item))
        return false;
    const Circle* temp = dynamic_cast<const Circle*>(&item);
    if(!temp)
        return false;

    if(this->radius == temp->getRadius())
         return true;
    else
        return false;
}
void Circle::toOs(ostream &os) const {
    os << "Circle details: color=" << this->getColor() << ", radius=" << this->getRadius() << endl;
    os << "area= " << this->getArea() << ", perimeter=" << this->getPerimeter() << endl;

}

Circle::~Circle(){}