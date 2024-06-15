/* Assignment C++: 1
   Author: Ohad Adi, ID: 315636753
           Tslil Sardam, ID:209488717
*/
#ifndef VENDINGMACHINE_H
#define VENDINGMACHINE_H

#include <iostream>
#include"DispenserType.h"
#include"CashRegister.h"

using namespace std;

class VendingMachine{
    private:
        DispenserType waterDis;
        DispenserType colaDis;
        DispenserType grapesDis;
        CashRegister counter;
        int dispenser_sell_product(DispenserType& Dispenser);

    public:
        VendingMachine (); /* Initialize the dispensers with the next values:
                water(10,5), cola(5,7), grapes(4,6) */
        int sellProduct(char product); /* Receive the first character of the wanted product (e.g. ‘w’ for water).
        Ask from the client to pay for the product unless the product is sold out.
        Take care of different cases of payment, such as if the client didn't pay
        enough (see executable) . */
        int get_water() const;
        int get_cola() const;
        int get_grapes() const;
        ~VendingMachine ();

};

#endif