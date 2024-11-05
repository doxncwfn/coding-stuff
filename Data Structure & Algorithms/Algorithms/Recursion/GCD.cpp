#include <iostream>
using namespace std;

int findGCD(int a, int b)
{
    if (b == 0)
        return a;
    return findGCD(b, a % b);
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << "GCD of " << a << " and " << b << " is " << findGCD(a, b) << endl;
    return 0;
}