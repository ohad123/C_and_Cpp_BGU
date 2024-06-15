/* Assignment C++: 1
   Author: Ohad Adi, ID: 315636753
           Tslil Sardam, ID:209488717
*/
#include "CashRegister.h"

CashRegister::CashRegister() {
    this->cashOnHands = 0;
}
CashRegister::CashRegister(int amount) {
    this->cashOnHands = amount;
}

int CashRegister::getCurrentBalance() const {
    return this->cashOnHands;
}
void CashRegister::acceptAmount(int pay){
    this->cashOnHands += pay;
}

