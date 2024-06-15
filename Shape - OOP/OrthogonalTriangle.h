/* Assignment C++: 3
   Author: Ohad Adi, ID: 315636753
           Tslil Sardam, ID:209488717
*/

#ifndef ASSIGNMENT3_ORTHOGONALTRIANGLE_H
#define ASSIGNMENT3_ORTHOGONALTRIANGLE_H
#include "Shape.h"
using namespace std;
class OrthogonalTriangle :public Shape{
private:
    double side;
public:
    OrthogonalTriangle(string color, double side);
    OrthogonalTriangle();
    double getSide() const { return side; }
    void draw() const;
    virtual ~OrthogonalTriangle();
    virtual double getArea()const;
    virtual double getPerimeter()const;
    OrthogonalTriangle(OrthogonalTriangle& triangle);
    virtual bool operator == (const Shape& item)const;
    virtual void toOs(ostream& os) const override;
    /*
    virtual char* getColor() const { return ((Shape*)this)->getColor(); }
    virtual void toOs(ostream& os) const;
    virtual void beforOs(ostream& os) const;

*/
};

#endif //ASSIGNMENT3_ORTHOGONALTRIANGLE_H
