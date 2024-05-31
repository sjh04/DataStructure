#include <iostream>

using namespace std;

struct myStack
{
    int data;
    myStack *next;
};

myStack* creatStack()
{
    myStack *s = new myStack;
    s->next = NULL;
    return s;
}

bool push(myStack *s, int e)
{
    myStack *p = new myStack;
    p->data = e;
    p->next = s->next;
    s->next = p;
    return true;
}

int pop(myStack *s)
{
    if(!s->next)
    {
        cout << "Stack is empty." << endl;
        return -1;
    }
    myStack *p = s->next;
    s->next = p->next;
    int e = p->data;
    delete p;
    return e;
}

int main()
{
    myStack *s = creatStack();
    push(s, 1);
    push(s, 2);
    push(s, 3);
    cout << pop(s) << endl;
    cout << pop(s) << endl;
    cout << pop(s) << endl;
    cout << pop(s) << endl;
    return 0;
}