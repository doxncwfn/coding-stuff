#include <bits/stdc++.h>
using namespace std;

template <class T>
class DLinkedList
{
public:
    class Node
    {
    private:
        T data;
        Node *next;
        Node *previous;
        friend class DLinkedList<T>;

    public:
        Node()
        {
            this->previous = NULL;
            this->next = NULL;
        }

        Node(const T &data)
        {
            this->data = data;
            this->previous = NULL;
            this->next = NULL;
        }
    };

protected:
    Node *head;
    Node *tail;
    int count;

public:
    DLinkedList();
    ~DLinkedList();
    void add(const T &e);
    void add(int index, const T &e);
    int size();
    bool empty();
    T get(int index);
    void set(int index, const T &e);
    int indexOf(const T &item);
    bool contains(const T &item);
    T removeAt(int index);
    bool removeItem(const T &item);
    void clear();

    void print()
    {
        Node *current = head;
        while (current)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

template <class T>
void DLinkedList<T>::add(const T &e)
{
    if (!head)
    {
        Node *tmp = new Node(e);
        head = tail = tmp;
        count++;
        return;
    }
    Node *tmp = new Node(e);
    tmp->previous = tail;
    tail->next = tmp;
    tail = tmp;
    count++;
}

template <class T>
void DLinkedList<T>::add(int index, const T &e)
{
    if (index < 0 || index > count)
        throw std::out_of_range("Index out of range");

    Node *newNode = new Node(e);

    if (index == 0)
    {
        newNode->next = head;
        if (head)
            head->previous = newNode;
        head = newNode;
        if (!tail)
            tail = newNode;
    }
    else if (index == count)
    {
        newNode->previous = tail;
        if (tail)
            tail->next = newNode;
        tail = newNode;
        if (!head)
            head = newNode;
    }
    else
    {
        Node *current = head;
        for (int i = 0; i < index; i++)
            current = current->next;
        newNode->next = current;
        newNode->previous = current->previous;
        if (current->previous)
            current->previous->next = newNode;
        current->previous = newNode;
    }
    count++;
}

template <class T>
int DLinkedList<T>::size()
{
    return this->count;
}

template <class T>
T DLinkedList<T>::get(int index)
{
    if (index < 0 || index > count)
        throw std::out_of_range("Index out of range");
    Node *current = head;
    for (int i = 0; i < index; i++)
        current = current->next;
    return current->data;
}

template <class T>
void DLinkedList<T>::set(int index, const T &e)
{
    if (index < 0 || index > count)
        throw std::out_of_range("Index out of range");

    Node *current = head;
    for (int i = 0; i < index; i++)
        current = current->next;
    current->data = e;
}

template <class T>
bool DLinkedList<T>::empty()
{
    return (!head && !tail) || count == 0;
}

template <class T>
int DLinkedList<T>::indexOf(const T &item)
{
    Node *current = head;
    for (int i = 0; i < count; i++)
    {
        if (current->data == item)
            return i;
        current = current->next;
    }
    return -1;
}

template <class T>
bool DLinkedList<T>::contains(const T &item)
{
    return indexOf(item) != -1;
}

template <class T>
T DLinkedList<T>::removeAt(int index)
{
    if (index < 0 || index >= count)
        throw std::out_of_range("Index is out of range");

    Node *tmp = nullptr;
    T item;
    if (index == 0)
    {
        item = head->data;
        tmp = head;
        head = head->next;
        if (head)
            head->previous = nullptr;
        else
            tail = nullptr;
    }
    else if (index == count - 1)
    {
        item = tail->data;
        tmp = tail;
        tail = tail->previous;
        if (tail)
            tail->next = nullptr;
        else
            head = nullptr;
    }
    else
    {
        Node *current = head;
        for (int i = 0; i < index; i++)
            current = current->next;
        tmp = current;
        item = current->data;
        current->previous->next = current->next;
        current->next->previous = current->previous;
    }
    delete tmp;
    count--;
    return item;
}

template <class T>
bool DLinkedList<T>::removeItem(const T &item)
{
    Node *current = head;
    int index = 0;
    while (current)
    {
        if (current->data == item)
        {
            removeAt(index);
            return true;
        }
        current = current->next;
        index++;
    }
    return false;
}

template <class T>
void DLinkedList<T>::clear()
{
    while (count)
        removeAt(0);
}