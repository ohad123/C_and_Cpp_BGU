/* Assignment C++: 3
   Author: Ohad Adi, ID: 315636753
           Tslil Sardam, ID:209488717
*/

#include "Square.h"

Square::Square(string color, double side): Shape(color){
    if (side <= 0){
        throw "Exception: The side must be positive";
    }
    else{
        this->side = side;
    }
}

double Square::getPerimeter() const {
    return (4 * this->side);
}

double Square::getArea() const {
    return (this->side * this->side);
}

void Square::draw() const {
    for (int i = 0; i < this->side; ++i) {
        for (int j = 0; j < this->side; ++j) {
            cout << "* ";
        }
        cout << endl;
    }
}

Square::Square(const Square &square):Shape(square.getColor()){
    this->side = square.getSide();
}

bool Square::operator==(const Shape &item) const {
    if (!Shape::operator==(item))
        return false;
    const Square* temp = dynamic_cast<const Square*>(&item);
    if(!temp)
        return false;

    if(this->side == temp->side)
        return true;
    else
        return false;
}

void Square::toOs(ostream &os) const {
    os << "Square details: color=" << this->getColor() << ", side length=" << this->getSide() << endl;
    os << "area= " << this->getArea() << ", perimeter=" << this->getPerimeter() << endl;
    this->draw();
}

Square::~Square() {}



