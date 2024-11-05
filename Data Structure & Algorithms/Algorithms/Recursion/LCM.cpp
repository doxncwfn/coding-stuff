#include <iostream>
using namespace std;

int findGCD(int a, int b)
{
    if (b == 0)
        return a;
    return findGCD(b, a % b);
}

int findLCM(int a, int b)
{
    if (a == 0 || b == 0)
        return 0;
    return abs(a * b) / findGCD(a, b);
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << "LCM of " << a << " and " << b << " is " << findLCM(a, b) << endl;
    return 0;
}