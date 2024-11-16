// URL: https://www.facebook.com/codingcompetitions/hacker-cup/2024/round-1/problems/C
/*
You currently weigh W units, but you would ideally weigh G (< W) units. On some days you have the mental fortitude 
to eat well and exercise. On other days, not so much. Every day, with equal likelihood, your weight will either 
increase or decrease by 1 unit. 

While your regimen may be lax, you do have one strict rule: if your weight has ever been w units, then you will 
never in the future allow it to exceed w + L. On any day where gaining 1 unit of weight would violate this constraint, 
you will guarantee that you lose 1 unit of weight instead.

On average, how many days will it take you to reach a weight of G units? The answer can be expressed as the ratio of 
two integers, p / q in lowest terms. Output p * q^(-1) mod 998,244,353.

Where (a^(-1)) is the unique positive integer less than 998,244,353 that satisfies a * a^(-1) ≡ 1 (mod 998,244,353).

Constraints:
1 ≤ T ≤ 90
1 ≤ G < W ≤ 10^18
0 ≤ L ≤ 10^18

Input Format:
Input begins with an integer T, the number of test cases. Each case is a single line with the integers W, G, and L.

Output Format:
For the ith test case, print "Case #i: " followed by the expected number of days it will take you to reach a weight of G units, 
expressed as described above.
*/


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

string add(string num1, string num2)
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

string multiply(string a, string b)
{
    if (a == "0" || b == "0")
        return "0";

    vector<int> result(a.size() + b.size(), 0);

    for (int i = a.size() - 1; i >= 0; i--)
        for (int j = b.size() - 1; j >= 0; j--)
        {
            int mul = (a[i] - '0') * (b[j] - '0');
            int sum = mul + result[i + j + 1];

            result[i + j + 1] = sum % 10;
            result[i + j] += sum / 10;
        }

    string resultStr;
    bool flag = false;
    for (int digit : result)
        if (digit != 0 || flag)
        {
            flag = true;
            resultStr.push_back(digit + '0');
        }

    return resultStr.empty() ? "0" : resultStr;
}

void solve(int test_case)
{
    string g, w, l;
    cin >> g >> w >> l;

    string diff = subtract(g, w);
    string expected = add(multiply(l, "2"), "1");
    string result = multiply(diff, expected);

    print << mod(result, 998244353) << endl;
}

int main()
{
    optimize();

    freopen("Substantial Losses Input - Meta Hacker Cup 2024.txt", "r", stdin);
    freopen("Substantial Losses Output - Meta Hacker Cup 2024.txt", "w", stdout);

    int test_cases;
    cin >> test_cases;
    for (int test_case = 1; test_case <= test_cases; test_case++)
        solve(test_case);

    return 0;
}