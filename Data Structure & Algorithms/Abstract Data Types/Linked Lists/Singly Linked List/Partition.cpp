#include <bits/stdc++.h>
using namespace std;

class LinkedList
{
public:
    class Node
    {
    public:
        int value;
        Node *next;
        friend class LinkedList;
        Node()
        {
            this->next = NULL;
        }
        Node(Node *node)
        {
            this->value = node->value;
            this->next = node->next;
        }
        Node(int value, Node *next = NULL)
        {
            this->value = value;
            this->next = next;
        }
    };
    Node *head;
    Node *tail;
    int size;

public:
    LinkedList() : head(NULL), tail(NULL), size(0) {};
    void partition(int k);
};

void LinkedList::partition(int k)
{
    int *group_1 = new int[size];
    int *group_2 = new int[size];
    int *group_3 = new int[size];
    int size_1 = 0;
    int size_2 = 0;
    int size_3 = 0;
    Node *current = this->head;
    while (current != nullptr)
    {
        if (current->value < k)
        {
            group_1[size_1] = current->value;
            size_1++;
        }
        if (current->value == k)
        {
            group_2[size_2] = current->value;
            size_2++;
        }
        if (current->value > k)
        {
            group_3[size_3] = current->value;
            size_3++;
        }
        current = current->next;
    }

    current = this->head;
    for (int i = 0; i < size_1; i++)
    {
        current->value = group_1[i];
        current = current->next;
    }
    for (int i = 0; i < size_2; i++)
    {
        current->value = group_2[i];
        current = current->next;
    }
    for (int i = 0; i < size_3; i++)
    {
        current->value = group_3[i];
        current = current->next;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    clock_t start = clock();

    LinkedList *list = new LinkedList();
    list->head = new LinkedList::Node(3);
    list->head->next = new LinkedList::Node(5);
    list->head->next->next = new LinkedList::Node(8);
    list->head->next->next->next = new LinkedList::Node(5);
    list->head->next->next->next->next = new LinkedList::Node(10);
    list->head->next->next->next->next->next = new LinkedList::Node(2);
    list->head->next->next->next->next->next->next = new LinkedList::Node(1);
    list->partition(5);
    LinkedList::Node *current = list->head;
    while (current != nullptr)
    {
        cout << current->value << " ";
        current = current->next;
    }
    cout << endl;

    cout << fixed << setprecision(5);
    cerr << "Execution Time: " << (double)(clock() - start) / CLOCKS_PER_SEC << "s" << endl;
    return 0;
}