#include <bits/stdc++.h>
using namespace std;

int StoI(string s)
{
    int sum = 0;
    for (int i = s.length() - 1; i >= 0; i--)
        sum += (s[i] - '0') * pow(10, (s.length() - (i + 1)));
    return sum;
}

int evaluatePostfix(string expr)
{
    stack<int> value;
    stringstream ss(expr);
    string token;

    while (ss >> token)
    {
        if (isdigit(token[0]) || (token.length() > 1 && isdigit(token[1])))
            value.push(StoI(token));
        else
        {
            int b = value.top();
            value.pop();
            int a = value.top();
            value.pop();
            switch (token[0])
            {
            case '+':
                value.push(a + b);
                break;
            case '-':
                value.push(a - b);
                break;
            case '*':
                value.push(a * b);
                break;
            case '/':
                value.push(a / b);
                break;
            }
        }
    }
    return value.top();
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    clock_t start = clock();
    string expr = "100 200 + 2 / 5 * 7 +";
    cout << evaluatePostfix(expr) << endl;

    cerr << "Executed time: " << (clock() - start) / (double)CLOCKS_PER_SEC << endl;

    return 0;
}