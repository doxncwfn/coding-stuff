#include <iostream>
using namespace std;

static int index = 0;

string inner(string substr, int n)
{
    if (n == 0)
        return "";
    return substr + inner(substr, n - 1);
}

string expand(const string &s)
{
    string result = "";
    if (index == (int)s.length())
        return result;

    if (isdigit(s[index]))
    {
        int times = s[index] - '0';
        index += 2;
        string substr = expand(s);
        result += inner(substr, times);
        index++;
        result += expand(s);
    }
    else if (s[index] == ')')
        return result;
    else
    {
        result += s[index++];
        result += expand(s);
    }

    return result;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    clock_t start = clock();
    string s;
    cin >> s;
    cout << expand(s) << endl;

    cerr << "Execution Time: " << (double)(clock() - start) / CLOCKS_PER_SEC << endl;
    return 0;
}