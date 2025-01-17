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
    LLNode(int val)
    {
        this->val = val;
        this->next = nullptr;
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

LLNode *rotateLinkedList(LLNode *head, int k)
{
    if (!head || k == 0)
        return head;

    LLNode *current = head;
    int length = 1;
    while (current->next != nullptr)
    {
        current = current->next;
        length++;
    }
    LLNode *tail = current;
    tail->next = head;

    k %= length;
    int shift = length - k;
    current = head;
    for (int i = 0; i < shift - 1; i++)
        current = current->next;
    head = current->next;
    current->next = nullptr;
    return head;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    clock_t start = clock();

    LLNode *head = new LLNode(1, new LLNode(2, new LLNode(3, new LLNode(4, new LLNode(5)))));
    head->print();
    head = rotateLinkedList(head, 2);
    head->print();
    head->free();

    cerr << "Execution time: " << (double)(clock() - start) / CLOCKS_PER_SEC << "s" << endl;

    return 0;
}