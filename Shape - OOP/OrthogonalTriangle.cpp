/* Assignment C++: 3
   Author: Ohad Adi, ID: 315636753
           Tslil Sardam, ID:209488717
*/

#include "OrthogonalTriangle.h"

OrthogonalTriangle::OrthogonalTriangle() {};
OrthogonalTriangle::OrthogonalTriangle(string color, double side): Shape(color){
    if(color != "red" && color != "blue" && color != "green") {
        throw "Exception: color must be red green or blue";
    }
    else{
        this->side = side;
    }
}

double OrthogonalTriangle::getPerimeter() const {
    return (this->side + this->side + sqrt(pow(this->side, 2) + pow(this->side, 2)));
}

double OrthogonalTriangle::getArea() const {
    return (pow(this->side, 2) / 2);
}

void OrthogonalTriangle::draw() const {
    for (int i = 0; i < this->side; ++i) {
        for (int j = 0; j <= i; ++j) {
            cout << "* ";
        }
        cout << endl;
    }
}

OrthogonalTriangle::OrthogonalTriangle(OrthogonalTriangle &triangle):Shape(triangle.getColor()) {
    this->side = triangle.getSide();
}

bool OrthogonalTriangle::operator==(const Shape &item) const {
    if (!Shape::operator==(item))
        return false;
    const OrthogonalTriangle* temp = dynamic_cast<const OrthogonalTriangle*>(&item);
    if(!temp)
        return false;

    if(this->side == temp->side)
        return true;
    else
        return false;
}

void OrthogonalTriangle::toOs(ostream &os) const {
    os << "OrthogonalTriangle details: color=" << this->getColor() << ", side=" << this->getSide() << endl;
    os << "area= " << this->getArea() << ", perimeter=" << this->getPerimeter() << endl;
    this->draw();
}

OrthogonalTriangle::~OrthogonalTriangle() {}