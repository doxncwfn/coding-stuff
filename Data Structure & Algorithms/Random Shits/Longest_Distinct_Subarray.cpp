#pragma GCC optimize("O3")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

#define ll long long

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // clock_t start_timer = clock();

    int n;
    cin >> n;
    vector<int> array(n);
    for (auto &x : array)
        cin >> x;

    unordered_map<int, ll> last_occurrence;
    ll max_len = 0;
    ll start = 0;
    for (ll end = 0; end < n; end++)
    {
        if (last_occurrence.find(array[end]) != last_occurrence.end())
            start = max(start, last_occurrence[array[end]] + 1);
        last_occurrence[array[end]] = end;
        max_len = max(max_len, end - start + 1);
    }

    cout << max_len << endl;

    // cerr << "Executed time: " << (clock() - start_timer) / (double)CLOCKS_PER_SEC << endl;

    return 0;
}