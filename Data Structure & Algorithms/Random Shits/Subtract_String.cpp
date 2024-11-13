#include <bits/stdc++.h>
using namespace std;

bool smaller(string a, string b)
{
    if (a.length() < b.length())
        return true;
    else if (a.length() > b.length())
        return false;
    // a.length() == b.length()
    for (int i = 0; i + 1 < a.length() && i + 1 < b.length(); i++)
    {
        if (a[i] < b[i])
            return false;
        if (a[i] > b[i])
            return true;
    }
    return true;
}

string subtract(string a, string b)
{
    bool negative = false;
    if (smaller(a, b))
    {
        swap(a, b);
        negative = true;
    }

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    int carry = 0;
    string result;
    for (int i = 0; i < a.length(); i++)
    {
        int sub = (a[i] - '0') - (i < b.length() ? b[i] - '0' : 0) - carry;
        if (sub < 0)
        {
            carry = 1;
            sub += 10;
        }
        else
            carry = 0;
        result.push_back(sub + '0');
    }
    while (result.length() > 1 && result.back() == '0')
        result.pop_back();
    reverse(result.begin(), result.end());

    return (negative ? "-" : "") + result;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    clock_t start = clock();

    string a, b;
    cin >> a >> b;

    cout << subtract(a, b) << endl;

    cerr << "Executed time: " << (clock() - start) / (double)CLOCKS_PER_SEC << endl;

    return 0;
}