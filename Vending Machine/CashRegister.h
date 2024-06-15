/* Assignment C++: 1
   Author: Ohad Adi, ID: 315636753
           Tslil Sardam, ID:209488717
*/
#ifndef CASHREGISTER_H
#define CASHREGISTER_H

#include <iostream>
using namespace std;
class CashRegister {
    private:
        int cashOnHands;
    public:
        CashRegister(); /* initiate the cash in the register to 0.*/
        CashRegister(int amount); /* initiate the cash in the register to a specific amount.*/
        int getCurrentBalance() const; /* returns value of cashOnHand.*/
        void acceptAmount(int pay) ;/* receive the amount deposited by the customer and update the amount in the register(update cashOnHands).*/

};

#endif