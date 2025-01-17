#include <iostream>
#include <stack>
using namespace std;

bool isValidParentheses(string s)
{
    stack<char> store;
    store.push(s[0]);

    for (int i = 1; i < (int)s.length(); i++)
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            store.push(s[i]);
        else
            switch (s[i])
            {
            case ')':
                if (store.top() == '(')
                    store.pop();
                else
                    store.push(s[i]);
                break;
            case ']':
                if (store.top() == '[')
                    store.pop();
                else
                    store.push(s[i]);
                break;
            case '}':
                if (store.top() == '{')
                    store.pop();
                else
                    store.push(s[i]);
                break;
            }

    return store.empty();
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    clock_t start = clock();

    string s;
    cin >> s;
    cout << isValidParentheses(s) << endl;

    cerr << "Executed time: " << (clock() - start) / (double)CLOCKS_PER_SEC << endl;

    return 0;
}