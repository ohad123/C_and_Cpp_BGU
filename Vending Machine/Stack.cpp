/* Assignment C++: 1
   Author: Ohad Adi, ID: 315636753
           Tslil Sardam, ID:209488717
*/


#include "Stack.h"
#include <climits>
#include <iostream>
using namespace std;

Stack::Stack(){
    this->top = NULL;
}

void Stack::push(int num)
{
    StackNode* NewSN = new StackNode;
    StackNode* temp;
    temp = top;
    top = NewSN;
    top->update_data(num);
    top->update_next(temp);
}

void Stack::pop()
{
    if (isEmpty())
        cout << "Stack empty" << endl;
    else
    {
        if (top->get_next() == NULL)	/* there is only one object in the stack */
        {
            cout << "Removing " << top->get_data() << endl;
            delete top;
            top = NULL;
        }
        else
        {
            StackNode* sec = top->get_next();
            cout << "Removing " << top->get_data() << endl;
            delete top;
            top = sec;
        }
    }
}

bool Stack::isEmpty() const
{
    if (top == NULL)
        return true;
    else
        return false;
}

int Stack::peek() const
{
    if (isEmpty()) {
        return INT_MIN;
    }
    else
    {
        return top->get_data();
    }

}


Stack::~Stack() {
    while (!isEmpty()) {
        StackNode *sec = top->get_next();
        delete top;
        top = sec;
    }
}