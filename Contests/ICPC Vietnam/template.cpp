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
#define debug(x) cout << "[" << #x << "] = " << (x) << endl;
#define print cout << "Case #" << test_case << ": "
#define optimize()                \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define sz(x) (int)x.size()
#define precision(x, digit) fixed << setprecision(digit) << x
#define endl '\n'
using namespace std;

void solve(int test_case)
{
    // DO SOMETHING
}

int main()
{
    optimize();

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
        solve(i);

    return 0;
}