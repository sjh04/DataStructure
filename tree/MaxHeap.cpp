#include <iostream>

using namespace std;

#define MaxData 1000

struct MaxHeap
{
    int *data;
    int size;
    int capacity;
};

MaxHeap *createHeap(int capacity)
{
    MaxHeap *heap = new MaxHeap();
    heap->data = new int[capacity];
    heap->size = 0;
    heap->capacity = capacity;
    heap->data[0] = MaxData;
    return heap;
}

bool isFull(MaxHeap *heap)
{
    return heap->size == heap->capacity;
}

bool isEmpty(MaxHeap *heap)
{
    return heap->size == 0;
}

bool insertHeap(MaxHeap *heap, int e)
{
    if (isFull(heap))
    {
        cout << "Heap is full" << endl;
        return false;
    }
    int i = ++heap->size;
    for (; heap->data[i / 2] < e; i /= 2)
    {
        heap->data[i] = heap->data[i / 2];
    }
    heap->data[i] = e;
    return true;
}

int deleteMax(MaxHeap *heap)
{
    if (isEmpty(heap))
    {
        cout << "Heap is empty" << endl;
        return -1;
    }

    int parent, child;
    int maxItem, temp;
    maxItem = heap->data[1];
    temp = heap->data[heap->size--];
    for (parent = 1; parent * 2 <= heap->size; parent = child)
    {
        child = parent * 2;
        if ((child != heap->size) && (heap->data[child] < heap->data[child + 1]))
        {
            child++;
        }
        if (temp >= heap->data[child])
        {
            break;
        }
        else
        {
            heap->data[parent] = heap->data[child];
        }
    }
    heap->data[parent] = temp;
    return maxItem;
}

void PercDown(MaxHeap *heap, int p)
{
    int parent, child;
    int temp = heap->data[p];
    for (parent = p; parent * 2 <= heap->size; parent = child)
    {
        child = parent * 2;
        if ((child != heap->size) && (heap->data[child] < heap->data[child + 1]))
        {
            child++;
        }
        if (temp >= heap->data[child])
        {
            break;
        }
        else
        {
            heap->data[parent] = heap->data[child];
        }
    }
    heap->data[parent] = temp;
}

void buildHeap(MaxHeap *heap)
{
    for (int i = heap->size / 2; i > 0; i--)
    {
        PercDown(heap, i);
    }
}

void printHeap(MaxHeap *heap)
{
    for (int i = 1; i <= heap->size; i++)
    {
        cout << heap->data[i] << " ";
    }
    cout << endl;
}

int main()
{
    MaxHeap *heap = createHeap(10);
    insertHeap(heap, 10);
    insertHeap(heap, 20);
    insertHeap(heap, 30);
    insertHeap(heap, 40);
    insertHeap(heap, 50);
    insertHeap(heap, 60);
    insertHeap(heap, 70);
    insertHeap(heap, 80);
    insertHeap(heap, 90);
    insertHeap(heap, 100);
    printHeap(heap);
    buildHeap(heap);
    printHeap(heap);
    deleteMax(heap);
    printHeap(heap);
    return 0;
}