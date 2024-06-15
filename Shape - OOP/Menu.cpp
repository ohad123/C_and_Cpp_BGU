/* Assignment C++: 3
   Author: Ohad Adi, ID: 315636753
           Tslil Sardam, ID:209488717
*/
#include "Menu.h"
using namespace std;
#include <cstring>

void Menu::mainMenu() {
    do{
        this->printMainMenu();
        cin>> this->inp;
        switch(inp){
            case 1:
                this->insert();
                break;

            case 2:
                this->del();
                break;

            case 3:
                this->print_top();
                break;

            case 4:
                this->mainlist.~LinkedList();
                break;

        }
    } while(this->inp != 4);




}

void Menu::printMainMenu() const {
    cout<<"======================================="<<endl;
    cout<<"<1> Add element to the list"<<endl;
    cout<<"<2> Remove the last shape from list"<<endl;
    cout<<"<3> Print the last shape"<<endl;
    cout<<"<4> Exit"<<endl;
    cout<<"======================================="<<endl;
}

void Menu::del() {
    try{
        Shape* p = this->mainlist.deleteNode();
        delete p;
    }
    catch(const char* exception) {
        cout << "Exception: The List is empty!" << endl;
        cout << "please try again" << endl;
    }
}

void Menu::insert() {
    int shp;
    double size;
    string color;
    cout<<"Choose 1 for Square, 2 for Circle, 3 for Triangle:";
    cin>>shp;
    do{
        switch(shp){
            case 1:
                cout<<"Enter square's color:";
                cin>>color;
                cout<<"Enter square's side length:";
                cin>>size;
                try {
                   Shape* p = new Square(color, size);
                   mainlist.insert(p);
                }
                catch (const char* exception){
                   cout<<exception<<endl;
                   cout << "please try again" << endl;
                   break;
                }
                return;

            case 2:
               cout << "Enter circle's color:";
               cin >> color;
               cout << "Enter circle's radius:";
               cin >> size;
               try {
                   Shape* p = new Circle(color, size);
                   mainlist.insert(p);
               }
               catch(const char* exception){
                   cout<<exception<<endl;
                   cout << "please try again" << endl;
                   break;
               }
               return;

           case 3:
               cout << "Enter Triangle's color:";
               cin >> color;
               cout << "Enter Triangle's side:";
               cin >> size;
               try {
                   Shape* p = new OrthogonalTriangle(color, size);
                   mainlist.insert(p);
               }
               catch(const char* exception){
                   cout<<exception<<endl;
                   cout << "please try again" << endl;
                   break;
               }
               return;

           default:
               cout<<"Invalid choice"<<endl;
               return;
       }
   } while(true);
}

void Menu::print_top() const {
    try{
        Shape* p = mainlist.getTop();
        cout<<*p;
    }
    catch (const char* exception){
        cout<<exception;
    }
}

Menu::~Menu() {}