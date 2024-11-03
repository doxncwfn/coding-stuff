#include <bits/stdc++.h>
using namespace std;

void interleave(queue<int> &q)
{
    if (q.empty())
        return;

    stack<int> first_half;
    int half_size = q.size() / 2;

    for (int i = 0; i < half_size; ++i)
    {
        first_half.push(q.front());
        q.pop();
    }

    while (!first_half.empty())
    {
        q.push(first_half.top());
        first_half.pop();
    }

    for (int i = 0; i < half_size; ++i)
    {
        q.push(q.front());
        q.pop();
    }

    for (int i = 0; i < half_size; ++i)
    {
        first_half.push(q.front());
        q.pop();
    }

    while (!first_half.empty())
    {
        q.push(first_half.top());
        first_half.pop();
        q.push(q.front());
        q.pop();
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    clock_t start = clock();

    queue<int> q;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int element;
        cin >> element;
        q.push(element);
    }

    interleave(q);

    while (!q.empty())
    {
        cout << q.front() << ' ';
        q.pop();
    }

    cerr << "Executed time: " << (clock() - start) / (double)CLOCKS_PER_SEC << endl;

    return 0;
}