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
#define sz(x) (int)x.size()
#define debug(x) cout << "[" << #x << "] = " << (x) << endl;
#define print cout << "Case #" << test_case << ": "
#define optimize()                \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define precision(x, digit) fixed << setprecision(digit) << x
#define endl '\n'
using namespace std;

void solve(int test_case)
{
    int n;
    cin >> n;
    string s, a;
    cin >> s >> a;

    if (n < sz(s))
    {
        cout << "Oh no!" << endl;
        return;
    }

    vector<bool> ch(n, false);
    for (int i = 0; i < sz(a); i++)
        ch[a[i] - 'a'] = true;

    for (int i = 0; i < sz(s); i++)
        if (!ch[s[i] - 'a'])
        {
            cout << "Oh no!" << endl;
            return;
        }

    cout << (sz(a) % 2 ? "Chikapu" : "Bash") << endl;
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