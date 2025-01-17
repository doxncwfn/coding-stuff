#include <bits/stdc++.h>
using namespace std;

string removeDuplicates(string str)
{
    if (str.empty())
        return str;

    stack<char> c;
    c.push(str[0]);
    for (int i = 1; i < (int)str.length(); i++)
        if (!c.empty() && str[i] == c.top())
            c.pop();
        else
            c.push(str[i]);

    string s = "";
    while (!c.empty())
    {
        s += c.top();
        c.pop();
    }

    stack<char> st;
    for (int i = 0; i < (int)s.length(); i++)
        st.push(s[i]);
    string result = "";
    while (!st.empty())
    {
        result += st.top();
        st.pop();
    }
    return result;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    clock_t start = clock();

    string str;
    cin >> str;
    cout << removeDuplicates(str) << endl;

    cerr << "Executed time: " << (clock() - start) / (double)CLOCKS_PER_SEC << endl;

    return 0;
}