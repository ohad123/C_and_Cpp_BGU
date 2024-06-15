/* Assignment C++: 1
   Author: Ohad Adi, ID: 315636753
           Tslil Sardam, ID:209488717
*/

#include <iostream>
#include "Menu.h"
using namespace std;

Menu::Menu() {}

void Menu::mainMenu() {
    do {
        cout << "(1) Beverage Machine" << endl;
        cout << "(2) Integer Stack" << endl;
        cout << "(3) Exit" << endl;
        cin >> this->input;

        switch (this->input) {

            case 1:
                shopMenu();
                break;

            case 2:
                stackMenu();
                break;

            case 3:
                cout << "Goodbye!" << endl;
                return;
                break;

            default:
                cout << "Invalid selection." << endl;

        }
    }while (this->input != 3);
}

void Menu::shopMenu() {
    int shop_inp;
    best_vendingmachine_ever = VendingMachine();

    do{
        print_shopMenu();
        cin>>shop_inp;

        switch (shop_inp) {
            case 1:
                best_vendingmachine_ever.sellProduct('w');
                break;
            case 2:
                best_vendingmachine_ever.sellProduct('c');
                break;
            case 3:
                best_vendingmachine_ever.sellProduct('g');
                break;
            case 4:
                cout<<"Thank you!"<<endl;
                best_vendingmachine_ever.~VendingMachine();
                return;
            default:
                cout<<"Invalid selection."<<endl;

        }

    }while(shop_inp!=4);
}

void Menu::stackMenu() {
    int stack_inp;
    do{
        print_stackMenu();
        cin>>stack_inp;
        switch (stack_inp) {
            case 1:
                int num;
                cout<<"Please insert the new element:"<<endl;
                cin>>num;
                best_stack_ever.push(num);
                break;
            case 2:
                best_stack_ever.pop();
                break;
            case 3:
                cout << "The first element is: " <<  best_stack_ever.peek() << endl;
                break;
            case 4:
                if (best_stack_ever.isEmpty()){
                    cout<<"The stack is empty"<<endl;
                }
                else{
                    cout<<"The stack is not empty"<<endl;
                }
                break;
            case 5:
                cout<<"Thank you!"<<endl;
                best_stack_ever.~Stack();
                return;
            default:
                cout<<"Invalid selection."<<endl;

        }
    } while(true);
}

void Menu::print_shopMenu() const {
    cout<<"*** Beverage Machine ***"<<endl<<endl;
    cout<<"Inventory details:"<<endl;
    cout<<"Water:       "<<best_vendingmachine_ever.get_water()<<endl;
    cout<<"Cola:        "<<best_vendingmachine_ever.get_cola()<<endl;
    cout<<"Grape juice: "<<best_vendingmachine_ever.get_grapes()<<endl<<endl;
    cout<<"To select an item, enter"<<endl;
    cout<<"1 For Water"<<endl;
    cout<<"2 For Cola"<<endl;
    cout<<"3 For Grape juice"<<endl;
    cout<<"4 To exit"<<endl;
}

void Menu::print_stackMenu() const {
    cout<<"*** Manage your integer stack ***"<<endl;
    cout<<"1 Push new element"<<endl;
    cout<<"2 Pop element"<<endl;
    cout<<"3 Show the first element"<<endl;
    cout<<"4 Check if empty"<<endl;
    cout<<"5 to exit"<<endl;
}

Menu::~Menu() {}