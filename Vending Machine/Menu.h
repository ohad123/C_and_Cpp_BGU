/* Assignment C++: 1
   Author: Ohad Adi, ID: 315636753
           Tslil Sardam, ID:209488717
*/
#ifndef MENU_H
#define MENU_H

#include "VendingMachine.h"
#include "Stack.h"



class Menu {
private:
    int input;
    Stack best_stack_ever;
    VendingMachine best_vendingmachine_ever;
    void print_shopMenu() const;
    void print_stackMenu() const;

public:
   Menu();
   ~Menu();
   void mainMenu();
   void shopMenu();
   void stackMenu();

};

#endif