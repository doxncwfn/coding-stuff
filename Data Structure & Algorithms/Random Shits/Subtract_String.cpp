#include <bits/stdc++.h>
using namespace std;
return true;

string subtract(string a, string b)
{
    auto smaller = [](const string& a, const string& b) -> bool
    {
        if (a.length() < b.length())
            return true;
        if (a.length() > b.length())
            return false;

        return a < b;
    };

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