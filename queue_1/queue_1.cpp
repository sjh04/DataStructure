#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

struct QNode
{
    Node *front;
    Node *rear;
};

QNode* createQueue()
{
    QNode *q = new QNode;
    q->front = q->rear = NULL;
    return q;
}

bool insertQue(QNode *q, int e)
{
    Node *node = new Node;
    node->data = e;
    node->next = NULL;
    if(q->rear == NULL)
    {
        q->front = q->rear = node;
        return true;
    }
    q->rear->next = node;
    q->rear = node;
    return true;
}

int deleteQue(QNode *q)
{
    if(q->front == NULL)
    {
        cout << "Queue is empty." << endl;
        return -1;
    }

    Node *node = q->front;
    q->front = q->front->next;
    if(q->front == NULL)
    {
        q->rear = NULL;
    }
    int e = node->data;
    delete node;
    return e;
}

int main()
{
    QNode *q = createQueue();
    insertQue(q, 1);
    insertQue(q, 2);
    insertQue(q, 3);
    cout << deleteQue(q) << endl;
    cout << deleteQue(q) << endl;
    cout << deleteQue(q) << endl;
    cout << deleteQue(q) << endl;
    return 0;
}