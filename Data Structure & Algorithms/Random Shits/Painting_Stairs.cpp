#include <bits/stdc++.h>
using namespace std;

bool isNumber(string s)
{
    for (char c : s)
        if (!isdigit(c))
            return false;
    return true;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    clock_t start = clock();

    string str;
    cout << "Enter a positive integer: ";
    do
    {
        cin >> str;
        if (!isNumber(str))
            cout << "Invalid input. Please enter a positive integer: ";
    } while (!isNumber(str));
    while (!str.empty() && str[0] == '0')
        str = str.substr(1);

    long long sum = 0;
    stack<int> digit;
    if (str.length() == 1)
        sum = 1;
    else if (str.length() == 2)
        sum = 1 - (str[0] - '0') * 2 + str.length();
    else
    {
        int digits = 3;
        sum = 18;
        digit.push(str[str.length() - 2] - '0');
        for (int i = str.length() - 3; i >= 0; i--)
            if (i != 0)
            {
                sum += digits * pow(10, digits - 1);
                digit.push(str[i] - '0');
                digits++;
            }
            else
            {
                sum += digits * (str[0] - '0' - 1) * pow(10, digits - 2);
                while (!digit.empty())
                {
                    sum += digit.size() > 1 ? digits * digit.top() * pow(10, digit.size() - 1) : digit.top() != 0 ? digits * (digit.top() + 1)
                                                                                                                  : digits * digit.top();
                    digit.pop();
                }
            }
        sum += str.length() + 1;
    }

    cout << "\nResult: " << sum << endl;

    cerr << "Executed time: " << (clock() - start) / (double)CLOCKS_PER_SEC << endl;

    return 0;
}