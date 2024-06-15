/* Assignment C++: 1
   Author: Ohad Adi, ID: 315636753
           Tslil Sardam, ID:209488717
*/

#include <iostream>
#include "VendingMachine.h"
using namespace std;


VendingMachine::VendingMachine(): waterDis(10,5), colaDis(5,7), grapesDis(4,6){}

VendingMachine::~VendingMachine() {}

int VendingMachine::sellProduct(char product) {
    if (product== 'w'){
        dispenser_sell_product(waterDis);
    }

    if (product== 'c'){
        dispenser_sell_product(colaDis);
    }

    if (product== 'g'){
        dispenser_sell_product(grapesDis);
    }

    return 0;
}


int VendingMachine:: dispenser_sell_product(DispenserType& dispenser){
    int money1 = 0;
    int money2 = 0;

    if (dispenser.getNoOfItems() == 0){
        cout << "**Sorry, this item is sold out.**" << endl;
        return 0;
    }

    cout << "Please deposit " << dispenser.getCost() << " NIS" << endl;
    cin >> money1;
    if(money1 >= dispenser.getCost()){
        cout<<"Collect your item at the bottom and enjoy." << endl;
        cout<<"*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<<endl<<endl;
        counter.acceptAmount(money1);
        dispenser.makeSale();
    }
    else{
        int leftover = dispenser.getCost() - money1;
        cout << "Please deposit another " <<leftover<< " NIS" << endl;
        cin >> money2;
        if(money2 >= leftover){
            cout<<"Collect your item at the bottom and enjoy." << endl;
            cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl << endl;
            counter.acceptAmount(money1 + money2);
            dispenser.makeSale();
        }
        else {
            cout<<"The amount is not enough. Collect what you deposited."<<endl;
        }

    }

    return 0;
}

int VendingMachine::get_water() const {
    return waterDis.getNoOfItems();
}

int VendingMachine::get_cola() const {
    return colaDis.getNoOfItems();
}

int VendingMachine::get_grapes() const {
    return grapesDis.getNoOfItems();
}


