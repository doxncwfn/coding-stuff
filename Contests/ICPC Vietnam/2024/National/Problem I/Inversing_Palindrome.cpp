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
    int n;
    string s1, s2;
    cin >> n >> s1 >> s2;

    vector<bool> flag(n);
    int ones_1 = 0, ones_2 = 0;
    for (int i = 0; i < n; i++)
    {
        ones_1 += (s1[i] == '1');
        ones_2 += (s2[i] == '1');
        flag[i] = (s1[i] == s2[i]);
    }

    if (ones_1 % 2 != ones_2 % 2)
    {
        cout << "NO" << endl;
        return;
    }

    bool inMismatch = false;
    int mismatchCount = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] != b[i]) {
            if (!inMismatch) mismatchCount++;
            inMismatch = true;
        } else {
            inMismatch = false;
        }
    }

    cout << (inMismatch ? "YES" : "NO") << endl
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