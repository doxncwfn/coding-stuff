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

void solve(int test_case)
{
    int n;
    cin >> n;
    vector<vector<int>> matrix(n, vector<int>(n));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> matrix[i][j];

    int result = 0;
    for (int c = 0; c < n; c++)
    {
        int mn = 0;
        for (int k = 0; k + c < n; k++)
            mn = min(mn, matrix[k][k + c]);

        result += abs(mn);
    }

    for (int r = 1; r < n; r++)
    {
        int mn = 0;
        for (int k = 0; k + r < n; k++)
            mn = min(mn, matrix[k + r][k]);

        result += abs(mn);
    }

    cout << result << endl;
}

int main()
{
    optimize();

    int test_cases;
    cin >> test_cases;
    for (int test_case = 1; test_case <= test_cases; test_case++)
        solve(test_case);

    return 0;
}