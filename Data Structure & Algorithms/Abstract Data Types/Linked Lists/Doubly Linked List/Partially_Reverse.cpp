#include "Doubly_Linked_List.h"

template <typename T>
DLinkedList<T> *reverse(DLinkedList<T> *head, int a, int b)
{
    if (!head || a > b)
        return nullptr;
    if (a == b)
        return head;

    DLinkedList<T> *current = head;
    DLinkedList<T> *A_prev = nullptr;
    DLinkedList<T> *A = nullptr;
    DLinkedList<T> *B = nullptr;
    DLinkedList<T> *B_next = nullptr;

    for (int i = 1; current && i <= b; i++)
    {
        if (i == a - 1)
            A_prev = current;
        if (i == a)
            A = current;
        if (i == b)
            B = current;
        current = current->next;
    }

    if (!A || !B)
        return head;

    B_next = B->next;
    DLinkedList<T> *prev = B_next;
    current = A;
    while (current != B_next)
    {
        DLinkedList<T> *next = current->next;
        current->next = prev;
        current->previous = next;
        prev = current;
        current = next;
    }

    if (A_prev)
        A_prev->next = B;
    else
        head = B;

    A->next = B_next;
    if (B_next)
        B_next->previous = A;

    return head;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    clock_t start = clock();

    DLinkedList<int> *list = new DLinkedList<int>();
    int size;
    cout << "Enter the size of the list: ";
    cin >> size;
    cout << "Enter the elements of the list: ";
    for (int i = 0; i < size; i++)
    {
        int x;
        cin >> x;
        list->add(x);
    }

    int a, b;
    cout << "Enter the range of the list to reverse: ";
    cin >> a >> b;

    DLinkedList<int> *head = reverse(list, a, b);
    list->print();

    cerr << "Executed time: " << (clock() - start) / (double)CLOCKS_PER_SEC << endl;

    return 0;
}