#include <bits/stdc++.h>
using namespace std;

int baseballScore(string ops)
{
    stack<int> point;

    for (char op : ops)
        if (op >= '0' && op <= '9')
            point.push(op - '0');
        else if (op == 'C' && !point.empty())
            point.pop();
        else if (op == 'D')
            point.push(point.top() * 2);
        else if (op == '+')
        {
            int tmp = point.top();
            point.pop();
            int tmp2 = point.top();
            point.push(tmp);
            point.push(tmp + tmp2);
        }

    int total = 0;
    while (!point.empty())
    {
        total += point.top();
        point.pop();
    }
    return total;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    clock_t start = clock();
    cout << baseballScore("524CD9++") << endl;

    cerr << "Executed time: " << (clock() - start) / (double)CLOCKS_PER_SEC << endl;

    return 0;
}