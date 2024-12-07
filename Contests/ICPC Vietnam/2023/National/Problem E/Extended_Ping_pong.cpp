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
#define endl '\n'
using namespace std;

void solve(int test_case)
{
    int n, a, b;
    cin >> n >> a >> b;

    if (max(a, b) < n || abs(a - b) < 2)
    {
        cout << 0 << endl;
        return;
    }

    int result = 0;
    int m = a + b;
    for (int mask = 0; mask < (1 << m); mask++)
    {
        if (__builtin_popcount(mask) != b)
            continue;

        bool check = true;
        int cur_a = 0, cur_b = 0;
        for (int i = 0; i + 1 < m; i++)
        {
            (mask >> i) & 1 ? cur_a++ : cur_b++;
            if (max(cur_a, cur_b) >= n && abs(cur_a - cur_b) >= 2)
            {
                check = false;
                break;
            }
        }
        if (check)
            result++;
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