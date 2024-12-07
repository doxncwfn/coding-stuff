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

long long countBetween(string a, string b, int l)
{
    if (l <= (int) a.size() && a.size() < b.size())
        return 0;

    if (l == (int) a.size() && a.size() == b.size())
        return b[a.size() - 1] - a[a.size() - 1] - 1;

    long long result = 1;

    for (int i = 0; i < l; i++)
    {
        char x = i < (int) a.size() ? a[i] : (i >= (int) b.size() ? 'a' - 1 : 'a');
        char y = i < (int) b.size() ? b[i] : 'z';

        result *= x < y ? (y - x) : 1;
    }

    return result;
}

int main()
{
    optimize();

    int q, n, p;
    cin >> q >> n >> p;
    vector<int> ds(n);
    for (int i = 0; i < n; i++)
    {
        cin >> ds[i];
        ds[i] -= 6;
    }
    sort(ds.begin(), ds.end());

    string s; cin >> s;
    string w; cin >> w;

    int result = 0;

    string a = "", b = "";
    for (int i = 0; i < q; i++)
    {
        int sum = 0;
        w[i] == 'A' ? a += s[i] : b += s[i];

        int tmp = 0;
        for (int d : ds)
            if (d < (int) min(a.size(), b.size()))
                tmp++;
            else
                sum += countBetween(a, b, d) % p;

        while(tmp--)
            ds.erase(ds.begin());

        result ^= (sum % p * (i + 1));
    }

    cout << result << endl;

    return 0;
}