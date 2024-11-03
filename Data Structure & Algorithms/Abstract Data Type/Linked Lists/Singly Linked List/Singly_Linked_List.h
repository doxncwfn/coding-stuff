#include <bits/stdc++.h>
using namespace std;

template <class T>
class SLinkedList
{
protected:
    Node *head;
    Node *tail;
    int count;

public:
    SLinkedList() : head(NULL), tail(NULL), count(0) {};
    ~SLinkedList();
    void add(const T &e);
    void add(int index, const T &e);
    T removeAt(int index);
    bool removeItem(const T &removeItem);
    bool empty();
    int size();
    void clear();
    T get(int index);
    void set(int index, const T &e);
    int indexOf(const T &item);
    bool contains(const T &item);
    string toString();
    SLinkedList(const SLinkedList &list)
    {
        this->count = 0;
        this->head = NULL;
        this->tail = NULL;
    }
    Iterator begin()
    {
        return Iterator(this, true);
    }
    Iterator end()
    {
        return Iterator(this, false);
    }

public:
    class Node
    {
    private:
        T data;
        Node *next;
        friend class SLinkedList<T>;

    public:
        Node()
        {
            next = 0;
        }
        Node(Node *next)
        {
            this->next = next;
        }
        Node(T data, Node *next = NULL)
        {
            this->data = data;
            this->next = next;
        }
    };
    class Iterator
    {
    private:
        SLinkedList<T> *pList;
        Node *current;
        int index; // corresponding with current node
    public:
        Iterator(SLinkedList<T> *pList, bool begin);
        Iterator &operator=(const Iterator &iterator);
        void set(const T &e);
        T &operator*();
        bool operator!=(const Iterator &iterator);
        void remove();

        Iterator &operator++();

        Iterator operator++(int);
    };
};
template <class T>
void SLinkedList<T>::add(const T &e)
{
    Node *newNode = new Node(e, nullptr);
    if (tail == nullptr)
        head = tail = newNode;
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
    count++;
}

template <class T>
void SLinkedList<T>::add(int index, const T &e)
{
    if (index == 0)
    {
        Node *newNode = new Node(e, head);
        head = newNode;
        if (count == 0)
            tail = head;
    }
    else
    {
        Node *prev = head;
        for (int i = 0; i < index - 1; ++i)
            prev = prev->next;
        Node *newNode = new Node(e, prev->next);
        prev->next = newNode;
        if (newNode->next == nullptr)
            tail = newNode;
    }
    count++;
}

template <class T>
int SLinkedList<T>::size()
{
    if (head == nullptr)
        return 0;
    int c = 0;
    Node *current = head;
    while (current != nullptr)
    {
        current = current->next;
        c++;
    }
    return c;
}

template <class T>
T SLinkedList<T>::get(int index)
{
    if (index >= count)
        throw std::out_of_range("");
    Node *current = head;
    int tmp = 0;
    while (tmp < index)
    {
        current = current->next;
        tmp++;
    }
    return current->data;
}

template <class T>
void SLinkedList<T>::set(int index, const T &e)
{
    if (index >= count)
        throw std::out_of_range("");
    Node *current = head;
    int tmp = 0;
    while (tmp < index)
    {
        current = current->next;
        tmp++;
    }
    current->data = e;
}

template <class T>
bool SLinkedList<T>::empty()
{
    return head == nullptr || count == 0;
}

template <class T>
int SLinkedList<T>::indexOf(const T &item)
{
    Node *current = head;
    int index = 0;
    while (current != nullptr)
    {
        if (current->data == item)
            return index;
        current = current->next;
        index++;
    }
    return -1;
}

template <class T>
bool SLinkedList<T>::contains(const T &item)
{
    return indexOf(item) != -1;
}

template <class T>
T SLinkedList<T>::removeAt(int index)
{
    Node *toDelete = nullptr;
    T data;

    if (index == 0)
    {
        toDelete = head;
        data = head->data;
        head = head->next;
        if (head == nullptr)
            tail = nullptr;
    }
    else
    {
        Node *prev = head;
        for (int i = 0; i < index - 1; ++i)
            prev = prev->next;
        toDelete = prev->next;
        data = toDelete->data;
        prev->next = toDelete->next;
        if (toDelete->next == nullptr)
            tail = prev;
    }
    delete toDelete;
    count--;
    return data;
}

template <class T>
bool SLinkedList<T>::removeItem(const T &item)
{
    Node *current = head;
    Node *prev = nullptr;

    while (current != nullptr)
    {
        if (current->data == item)
        {
            if (prev == nullptr)
            {
                head = current->next;
                if (head == nullptr)
                    tail = nullptr;
            }
            else
            {
                prev->next = current->next;
                if (current->next == nullptr)
                    tail = prev;
            }
            delete current;
            count--;
            return true;
        }
        prev = current;
        current = current->next;
    }

    return false;
}

template <class T>
void SLinkedList<T>::clear()
{
    Node *current = head;
    while (current != nullptr)
    {
        Node *temp = current->next;
        delete current;
        current = temp;
    }
    head = tail = nullptr;
    count = 0;
}

template <class T>
SLinkedList<T>::Iterator::Iterator() : current(nullptr), index(-1), pList(nullptr) {}

template <class T>
SLinkedList<T>::Iterator::Iterator(SLinkedList<T> *pList, bool begin)
{
    this->pList = pList;
    if (begin)
    {
        if (pList && pList->head)
        {
            this->current = pList->head;
            this->index = 0;
        }
        else
        {
            this->current = nullptr;
            this->index = -1;
        }
    }
    else
    {
        this->current = nullptr;
        this->index = pList ? pList->size() : 0;
    }
}

template <class T>
typename SLinkedList<T>::Iterator &SLinkedList<T>::Iterator::operator=(const Iterator &iterator)
{
    this->current = iterator.current;
    this->index = iterator.index;
    this->pList = iterator.pList;
    return *this;
}

template <class T>
void SLinkedList<T>::Iterator::remove()
{
    if (!current)
        throw std::out_of_range("Segmentation fault!");

    if (current == pList->head)
    {
        pList->head = current->next;
        delete current;
        current = nullptr;
        index = -1;
        pList->count--;
    }
    else
    {
        Node *prev = pList->head;
        while (prev->next != current)
            prev = prev->next;
        prev->next = current->next;
        delete current;
        current = prev;
        index--;
        pList->count--;
    }
}

template <class T>
void SLinkedList<T>::Iterator::set(const T &e)
{
    if (!current)
        throw std::out_of_range("Segmentation fault!");
    current->data = e;
}

template <class T>
T &SLinkedList<T>::Iterator::operator*()
{
    if (!current)
        throw std::out_of_range("Segmentation fault!");
    return current->data;
}

template <class T>
bool SLinkedList<T>::Iterator::operator!=(const Iterator &iterator)
{
    return current != iterator.current || index != iterator.index;
}

template <class T>
typename SLinkedList<T>::Iterator &SLinkedList<T>::Iterator::operator++()
{
    if (!current)
        throw std::out_of_range("Segmentation fault!");

    if (current->next)
    {
        current = current->next;
        index++;
    }
    else
    {
        current = nullptr;
        index = pList->size();
    }
    return *this;
}

template <class T>
typename SLinkedList<T>::Iterator SLinkedList<T>::Iterator::operator++(int)
{
    Iterator temp = *this;
    ++(*this);
    return temp;
}