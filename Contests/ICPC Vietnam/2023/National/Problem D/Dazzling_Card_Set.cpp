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
#define optimize() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define precision(x, digit) fixed << setprecision(digit) << x
#define endl '\n'
using namespace std;

void solve(int test_case)
{
    int n;
    cin >> n;
    vector<int> a(n), last_app(n, -1);
    int invalid = -1;
    int64_t count = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i]--;
        invalid = max(invalid, last_app[a[i]]);
        last_app[a[i]] = i;
        count += i - invalid;
    }

    // int count = 0;
    // for (int i = 0; i < n; i++)
    // {
    //     set<int> s;
    //     s.insert(a[i]);
    //     count++;
    //     for (int j = i + 1; j < n; j++)
    //     {
    //         if (s.find(a[j]) == s.end())
    //         {
    //             s.insert(a[j]);
    //             count++;
    //         }
    //         else
    //             break;
    //     }
    // }

    cout << count << endl;
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