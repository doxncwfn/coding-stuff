#include <iostream>
using namespace std;

class max_heap
{
private:
    int capacity;
    int current_size;
    int *arr;

public:
    max_heap(int capacity)
    {
        this->capacity = capacity;
        this->current_size = 0;
        this->arr = new int[capacity];
    }
    int parent(int i) { return (i - 1) / 2; } // return parent index
    int left(int i) { return 2 * i + 1; }     // return left index
    int right(int i) { return 2 * i + 2; }    // return right index

    void heapify(int i)
    {
        int l = left(i);
        int r = right(i);
        int largest = i;
        if (l < current_size && arr[l] > arr[largest])
            largest = l;
        if (r < current_size && arr[r] > arr[largest])
            largest = r;
        if (largest != i)
        {
            swap(arr[i], arr[largest]);
            heapify(largest);
        }
    }
};