#pragma GCC optimize("O3")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <utility>

using namespace std;

#define print cout << "Case #" << test_case << ": "
#define optimize() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define precision(x, digit) fixed << setprecision(digit) << x
#define endl '\n'

#define MOD 1e9+7
#define ll long long
#define vt vector
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define mp make_pair
#define fi first
#define se second

struct point { double x, y; };
struct circle { point center; double radius; };
double Euclidian_distance(point a, point b) { return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y)); }
bool collinear(point a, point b, point c) { return (b.y - a.y) * (c.x - b.x) == (c.y - b.y) * (b.x - a.x); }
bool is_on_circle(circle c, point p) { return Euclidian_distance(c.center, p) == c.radius; }

#define FOR(i, a, b) for (int i = a; i < b; i++)
#define ROF(i, a, b) for (int i = a; i >= b; i--)
#define trav(a, x) for (auto &a : x)

long long mod(const std::string largeInt, long long mod)
{
    long long result = 0;

    for (char digit : largeInt)
        result = (result * 10 + (digit - '0')) % mod;

    return result;
}

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

string addStrings(string num1, string num2)
{
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());

    string result;
    int carry = 0;
    for (int i = 0; i < max(num1.size(), num2.size()); i++)
    {
        int sum = carry;
        if (i < num1.size())
            sum += num1[i] - '0';
        if (i < num2.size())
            sum += num2[i] - '0';
        result.push_back(sum % 10 + '0');
        carry = sum / 10;
    }

    if (carry)
        result.push_back(carry + '0');

    reverse(result.begin(), result.end());

    return result;
}

string multiplyString(string a, string b)
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

void solve(int test_case)
{
    string s;
    int k;
    cin >> s >> k;

    bool last = true, digit = false, zero = false;
    vector<int> p;
    for (int i = (int)s.size() - 1; ~i; i--)
    {
        if (s[i] >= '0' && s[i] <= '9') // is digit
        {
            last = (zero && (i - 1 >= 0 && s[i - 1] == '?'));
            zero = (s[i] == '0');
            digit = true;
        }
        else
        {
            if (last && (i - 1 >= 0 && s[i - 1] == '?')) // pair of last two ?
            {
                p.pb(15);
                i--;
            }
            else if (digit)
            {
                p.pb(s[i] >= '7' ? 1 : 2)
            }

            digit = last = zero = false;
        }
    }

    string permutation = "1";
    for (int x : p)
        permutation = multiplyString(permutation, to_string(x));

    string decipher = "";
    string tmp = "1";
    for (int i = 0; i < (int)permutation.size(); i++)
    {

    }
    
    print << decipher << mod(permutation, 998244353) << endl;
}

int main()
{
    optimize();

    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);

    int test_cases;
    cin >> test_cases;
    for (int test_case = 1; test_case <= test_cases; test_case++)
        solve(test_case);

    return 0;
}