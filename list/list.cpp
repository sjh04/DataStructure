#include <iostream>

using namespace std;

#define MAXSIZE 100
#define INCREASESIZE 10

struct myList
{
    int *data;
    int length;
};

void initList(myList &l)
{
    l.length = 0;
    l.data = new int[MAXSIZE];
}

bool insertList(myList &l, int i, int e)
{
    if(i < 1 || i > l.length + 1)
    {
        return false;
    }
    if(l.length >= MAXSIZE)
    {
        return false;
    }
    for(int j = l.length; j >= i; j--)
    {
        l.data[j] = l.data[j-1];
    }
    l.data[i-1] = e;
    l.length++;
    return true;
}

bool deleteList(myList &l, int i, int &e)
{
    if(i < 1 || i > l.length)
    {
        return false;
    }
    e = l.data[i-1];
    for(int j = i; j < l.length; j++)
    {
        l.data[j-1] = l.data[j];
    }
    l.length--;
    return true;
}

int locateElem(myList l, int e)
{
    for(int i = 0; i < l.length; i++)
    {
        if(l.data[i] == e)
        {
            return i+1;
        }
    }
    return 0;
}

int getElem(myList l, int i)
{
    return l.data[i-1];
}

void printList(myList l)
{
    for(int i = 0; i < l.length; i++)
    {
        cout << l.data[i] << " ";
    }
    cout << endl;
}

int main()
{
    myList l;
    initList(l);
    insertList(l, 1, 1);
    insertList(l, 2, 2);
    insertList(l, 3, 3);
    insertList(l, 4, 4);
    insertList(l, 5, 5);
    printList(l);
    int e;
    deleteList(l, 3, e);
    cout << e << endl;
    printList(l);
    cout << locateElem(l, 4) << endl;
    cout << getElem(l, 2) << endl;
    return 0;
}