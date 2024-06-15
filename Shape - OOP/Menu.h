/* Assignment C++: 3
   Author: Ohad Adi, ID: 315636753
           Tslil Sardam, ID:209488717
*/


#ifndef ASSIGNMENT3_MENU_H
#define ASSIGNMENT3_MENU_H

#include "OrthogonalTriangle.h"
#include "Circle.h"
#include "Square.h"
#include "LinkedList.h"
#include "Shape.h"
#include <cstring>

class Menu{
private:
    int inp;
    void printMainMenu() const;
    void insert();
    void del();
    void print_top() const;
    LinkedList<Shape*> mainlist;
public:
    void mainMenu();

    ~Menu();
};

#endif // ASSIGNMENT3_MENU_H