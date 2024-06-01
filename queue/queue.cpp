#include <iostream>
#define MAXSIZE 100

using namespace std;

struct myQueue
{
    int data[MAXSIZE];
    int front;
    int rear;
};

myQueue* creatQueue()
{
    myQueue *q = new myQueue;
    q->front = q->rear = 0;
    return q;
}

bool enQueue(myQueue *q, int e)
{
    if((q->rear + 1)%MAXSIZE == q->front)
    {
        cout << "Queue is full." << endl;
        return false;
    }
    q->data[q->rear] = e;
    q->rear = (q->rear + 1)%MAXSIZE;
    return true;
}

int deQueue(myQueue *q)
{
    if(q->front == q->rear)
    {
        cout << "Queue is empty." << endl;
        return -1;
    }
    int e = q->data[q->front];
    q->front = (q->front + 1)%MAXSIZE;
    return e;
}

int main()
{
    myQueue *q = creatQueue();
    enQueue(q, 1);
    enQueue(q, 2);
    enQueue(q, 3);
    cout << deQueue(q) << endl;
    cout << deQueue(q) << endl;
    cout << deQueue(q) << endl;
    cout << deQueue(q) << endl;
    return 0;
}