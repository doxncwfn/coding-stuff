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
#define sz(x) (int)x.size()
#define endl '\n'
using namespace std;

int main()
{
    optimize();

    int n, k, p;
    while(cin >> n >> k >> p)
    {
        vector<vector<int>> rows(n), cols(n);
        int n_rooks = 0;
        for (int i = 0; i < n; i++)
        {
            string row;
            cin >> row;
            for (int j = 0; j < n; j++)
                if (row[j] == 'R')
                {
                    rows[i].push_back(j);
                    cols[j].push_back(i);
                    n_rooks++;
                }
        }
        vector<int> free_rows, free_cols;
        vector<int> has_rows, has_cols;
        for (int i = 0; i < n; i++)
        {
            rows[i].empty() ? free_rows.push_back(i) : has_rows.push_back(i);
            cols[i].empty() ? free_cols.push_back(i) : has_cols.push_back(i);
        }

        int more_rooks = k;
        n_rooks += k;
        int num = 2 * n_rooks - p;
        if (num > 2 * n)
        {
            cout << "NO\n";
            continue;
        }

        int need = num - 2 * n + sz(free_rows) + sz(free_cols);
        int fr_rows = 0, fr_cols = 0;

        if (need > 0)
            for (int fr_r = 0; fr_r <= sz(free_rows); fr_r++)
            {
                int fr_c = need - fr_r;
                if (more_rooks < max(fr_r, fr_c))
                    continue;
                if (fr_r == 0 && has_rows.empty())
                    continue;
                if (fr_r > sz(free_rows))
                    continue;
                if (fr_c == 0 && has_cols.empty())
                    continue;
                if (fr_c > sz(free_cols))
                    continue;

                int64_t edges = int64_t(sz(has_rows) + fr_r) * (sz(has_cols) + fr_c);
                if (edges >= n_rooks)
                {
                    fr_rows = fr_r;
                    fr_cols = fr_c;
                    break;
                }
            }

        if (fr_rows + fr_cols != need)
        {
            cout << "NO\n";
            continue;
        }

        for (int i = 0; i < min(fr_rows, fr_cols); i++)
        {
            int r = has_rows.empty() ? free_rows[0] : has_rows[0];
            int c = free_cols[i];
            rows[r].push_back(c);
        }
    }

    return 0;
}