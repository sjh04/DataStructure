#include <iostream>
#define MAXSIZE 100

using namespace std;

struct myStack
{
    int data[MAXSIZE];
    int top;
};

myStack* creatStack()
{
    myStack *s = new myStack;
    s->top = -1;
    return s;
}

bool push(myStack *s, int e)
{
    if(s->top == MAXSIZE - 1)
    {
        cout << "Stack is full." << endl;
        return false;
    }
    s->data[++s->top] = e;
    return true;
}

int pop(myStack *s)
{
    if(s->top == -1)
    {
        cout << "Stack is empty." << endl;
        return -1;
    }
    return s->data[s->top--];
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