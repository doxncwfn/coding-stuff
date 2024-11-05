#include <iostream>
using namespace std;

int helper(const string &s, int index, int open, int close)
{
    int n = s.length();
    if (index >= n)
        return open + close;

    if (s[index] == '(')
        return helper(s, index + 1, open + 1, close);
    else if (open > 0)
        return helper(s, index + 1, open - 1, close);
    else
        return helper(s, index + 1, open, close + 1);
}

int mininumBracketAdd(string s)
{
    return helper(s, 0, 0, 0);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    clock_t start = clock();

    string s;
    cin >> s;
    cout << mininumBracketAdd(s) << endl;

    cerr << "Executed time: " << (clock() - start) / (double)CLOCKS_PER_SEC << endl;

    return 0;
}