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

bool check(string s)
{
    int n = s.length();
    for (int i = 0; i < n / 2; ++i)
        if (s[i] != s[n / 2 + i])
            return false;

    return true;
}

int main()
{
    optimize();

    int n;
    string z;
    cin >> n >> z;

    if (n % 2 == 0)
        cout << "No Solution";
    else
    {
        int s = (n - 1) / 2;
        vector<string> result;
        string temp;
        for (int i = 0; i < n; i++)
        {
            string tmp = z.substr(0, i) + z.substr(i + 1, n - i - 1);
            if (check(tmp))
                result.push_back(tmp.substr(0, s));
        }

        if (result.empty())
            cout << "No Solution";
        else if (sz(result) == 1)
            cout << result[0];
        else
            cout << "Multiple Solutions";
    }

    return 0;
}