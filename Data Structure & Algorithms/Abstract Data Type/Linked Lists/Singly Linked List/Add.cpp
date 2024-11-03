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

static int carry = 0;
LLNode *addLinkedList(LLNode *l0, LLNode *l1)
{
    if (!l0 && !l1 && carry == 0)
        return nullptr;
    int sum = carry;
    if (l0)
    {
        sum += l0->val;
        l0 = l0->next;
    }
    if (l1)
    {
        sum += l1->val;
        l1 = l1->next;
    }
    LLNode *tmp = new LLNode(sum % 10);
    carry = sum / 10;
    tmp->next = addLinkedList(l0, l1);

    return tmp;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    clock_t start = clock();

    LLNode *l0 = new LLNode(2, new LLNode(4, new LLNode(3)));
    LLNode *l1 = new LLNode(5, new LLNode(6, new LLNode(4)));
    LLNode *sum = addLinkedList(l0, l1);
    sum->print();
    l0->free();
    l1->free();
    sum->free();

    cerr << "Time: " << 1000 * (clock() - start) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}