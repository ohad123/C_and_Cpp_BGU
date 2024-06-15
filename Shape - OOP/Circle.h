/* Assignment C++: 3
   Author: Ohad Adi, ID: 315636753
           Tslil Sardam, ID:209488717
*/

#ifndef ASSIGNMENT3_CIRCLE_H
#define ASSIGNMENT3_CIRCLE_H
#include "Shape.h"
using namespace std;
class Circle:public Shape{
private:
    double radius;
public:
    Circle();
    Circle(string color, double radius);
    Circle(const Circle& circ);
    virtual double getArea() const;
    virtual double getPerimeter() const;
    double getRadius() const;
    virtual bool operator == (const Shape& item)const;
    virtual void toOs(ostream& os) const override;
    virtual ~Circle();
};

#endif //ASSIGNMENT3_CIRCLE_H
