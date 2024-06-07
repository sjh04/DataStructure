#include <iostream>

using namespace std;

#define MAXISIZE 100
#define INCREASESIZE 10

struct myListNode
{
    int data;
    myListNode *next;
};

myListNode* createList(int e)
{
    myListNode *head = new myListNode;
    head->data = e;
    head->next = NULL;
    return head;
}

bool insertList(myListNode *head, int i, int e)
{
    myListNode *p = head;
    int j = 0;
    while(p && j < i-1)
    {
        p = p->next;
        j++;
    }
    if(!p || j > i-1)
    {
        return false;
    }
    myListNode *q = new myListNode;
    q->data = e;
    q->next = p->next;
    p->next = q;
    return true;
}

bool deleteList(myListNode *head, int i, int &e)
{
    myListNode *p = head;
    int j = 0;
    while(p->next && j < i-1)
    {
        p = p->next;
        j++;
    }
    if(!p->next || j > i-1)
    {
        return false;
    }
    myListNode *q = p->next;
    e = q->data;
    p->next = q->next;
    delete q;
    return true;
}

int locateElem(myListNode *head, int e)
{
    myListNode *p = head->next;
    int i=1;
    while(p && p->data != e)
    {
        p = p->next;
        i++;
    }
    if(p)
    {
        return i;
    }
    return 0;
}

int getElem(myListNode *head, int i)
{
    myListNode *p = head->next;
    int j = 1;
    while(p && j < i)
    {
        p = p->next;
        j++;
    }
    if(!p || j > i)
    {
        return 0;
    }
    return p->data;
}

int main()
{
    myListNode *head = createList(0);
    for(int i = 1; i <= 10; i++)
    {
        insertList(head, i, i);
    }
    cout << "The 5th element is: " << getElem(head, 5) << endl;
    cout << "The location of 5 is: " << locateElem(head, 5) << endl;
    int e;
    deleteList(head, 5, e);
    cout << "The 5th element is: " << getElem(head, 5) << endl;
    cout << "The location of 5 is: " << locateElem(head, 5) << endl;
    return 0;
}