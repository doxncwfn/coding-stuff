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
#define print cout << "Case #" << test_case << ": "
#define optimize() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define precision(x, digit) fixed << setprecision(digit) << x
#define sz(v) (int)v.size()
#define endl '\n'
using namespace std;

void solve(int test_case)
{
    string str;
    cin >> str;
    int n = sz(str);

    int best = 0;
    int result = 0;
    for (int k = 2; k <= n; k++)
    {
        int count = 0;
        for (int i = 0; i < n; i += k)
        {
            int r = 0, p = 0, s = 0;
            for (int j = i; j < min(i + k, n); j++)
            {
                r += (str[j] == 'R');
                p += (str[j] == 'P');
                s += (str[j] == 'S');
            }
            count += max({r, p, s});
        }

        if (count >= best)
        {
            best = count;
            result = k;
        }
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