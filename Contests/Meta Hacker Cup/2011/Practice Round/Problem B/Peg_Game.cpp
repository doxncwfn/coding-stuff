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
void solve(int test_case)
{
    int r, c, k, m;
    cin >> r >> c >> k >> m;
    vt<vt<int>> dp(r, vt<int>(c, 0));
    while (m--)
    {
        int x, y;
        cin >> x >> y;
        dp[x - 1][y - 1] = 1;
    }

    int start;
    double probability = 1;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
            if (dp[i][j] == 1)
            {
                start = j;
                break;
            }

        for (int j = start; j < c; j++)
            if (dp[i][j] == 1)
            {
                probability *= 0.5;
                dp[i][j] = 0;
            }
            else
                dp[i][j] = probability;
        probability = 1;
    }

    print << start << " " << precision(probability, 6) << endl;
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