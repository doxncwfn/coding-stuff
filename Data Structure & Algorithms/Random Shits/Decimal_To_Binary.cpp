#include <bits/stdc++.h>
using namespace std;

string decimalToBinary(int n)
{
    string binary = "";
    while (n > 0)
    {
        binary = to_string(n % 2) + binary;
        n /= 2;
    }
    return binary;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    clock_t start = clock();

    int n;
    cout << "Enter a decimal number: ";
    cin >> n;
    cout << "Binary representation: " << decimalToBinary(n) << endl;

    cerr << "Executed time: " << (clock() - start) / (double)CLOCKS_PER_SEC << endl;

    return 0;
}