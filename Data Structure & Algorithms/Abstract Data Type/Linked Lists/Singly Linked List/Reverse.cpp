#include <bits/stdc++.h>
using namespace std;

class LLNode
{
public:
    int val;
    LLNode *next;
    LLNode()
    {
        val = 0;
        next = nullptr;
    }
    LLNode(int val, LLNode *next)
    {
        this->val = val;
        this->next = next;
    }
    void print()
    {
        LLNode *temp = this;
        while (temp != nullptr)
        {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void free()
    {
        LLNode *temp = this;
        while (temp != nullptr)
        {
            LLNode *del = temp;
            temp = temp->next;
            delete del;
        }
    }
};

LLNode *reverseLinkedList(LLNode *head)
{
    LLNode *prev = nullptr;
    LLNode *current = head;
    LLNode *next = nullptr;

    while (current != nullptr)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

int main()
{
    array<int, 5> arr = {1, 2, 3, 4, 5};
    int n = arr.size();

    LLNode *head = new LLNode(arr[0], nullptr);
    LLNode *temp = head;
    for (int i = 1; i < n; i++)
    {
        temp->next = new LLNode(arr[i], nullptr);
        temp = temp->next;
    }

    head->print();
    head = reverseLinkedList(head);
    head->print();

    head->free();

    return 0;
}