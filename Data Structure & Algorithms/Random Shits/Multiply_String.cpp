#include <bits/stdc++.h>
using namespace std;

string multiply(string a, string b)
{
    if (a == "0" || b =="0")
        return "0";

    vector<int> result(a.size() + b.size(), 0);
    for (int i = 0; i < a.size(); i++)
        for (int j = 0; j < b.size(); j++)
        {
            int mul = (a[i] - '0') * (b[i] - '0');
            int sum = mul + result[i + j + 1];

            result[i + j + 1] = sum % 10;
            result[i + j] += sum / 10;
        }

    string resultStr;
    bool flag = true;
    for (int digit : result)
    {
        if (digit != 0) flag = false;
        if (!flag) resultStr.push_back(digit + '0');
    }

    return resultStr;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    clock_t start = clock();

    string a, b;
    cin >> a >> b;
    cout << multiply(a, b) << endl;
    cerr << "Executed time: " << (clock() - start) / (double)CLOCKS_PER_SEC << endl;

    return 0;
}