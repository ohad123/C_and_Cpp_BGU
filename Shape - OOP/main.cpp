#include <iostream>
#include <ostream>
#include "Menu.h"


using namespace std;
int main() {
    LinkedList<Shape*> lst;
    Shape* itm1= new Circle("red", 3);
    Shape* itm2= new Circle("blue", 8);
    Shape* itm3= new Square("red", 3);
    Shape* itm4= new Circle("green", 2);
    Shape* itm5= new Square("red", 3);
    Shape* itm6= new Square("red", 660);
    lst.insert(itm1);
    lst.insert(itm2);
    lst.insert(itm3);
    lst.insert(itm4);
    if (!(*itm1==*itm2))
        cout<<"success1"<<endl;
    if(lst.search(itm3))
        cout<<"success2"<<endl;
    if(lst.search(itm5))
        cout<<"success3"<<endl;
    if(!lst.search(itm6))
        cout<<"success4"<<endl;
    if(*itm3==*itm5)
        cout<<"success5"<<endl;
    if(*itm3==*itm1)
        cout<<"success5"<<endl;
    cout<<*lst.deleteNode(itm2);

    return 0;
}
