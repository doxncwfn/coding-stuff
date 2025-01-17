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

int countPaths1(vector<vector<int>> &grid)
{
    int rows = grid.size();
    int cols = grid[0].size();

    vector<vector<int>> dp(rows, vector<int>(cols, 0));
    dp[0][0] = 1;

    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            if (grid[i][j] == 1)
                dp[i][j] = 0;
            else
            {
                if (i > 0)
                    dp[i][j] += dp[i - 1][j];
                if (j > 0)
                    dp[i][j] += dp[i][j - 1];
            }

    return dp[rows - 1][cols - 1];
}

int countPaths2(vector<vector<int>> &grid)
{
    int rows = grid.size();
    int cols = grid[0].size();

    vector<int> dp(cols, 0);

    dp[0] = 1;

    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            if (grid[i][j] == 1)
                dp[j] = 0;
            else if (j > 0)
                dp[j] += dp[j - 1];

    return dp[cols - 1];
}

int countPaths3(vector<vector<int>> &grid)
{
    int rows = grid.size();
    int cols = grid[0].size();

    vector<int> dp(cols, 0);
    dp[0] = 1;

    for (int i = 0; i < rows; ++i)
    {
        bool hasPath = false;
        for (int j = 0; j < cols; ++j)
        {
            if (grid[i][j] == 1)
                dp[j] = 0;
            else
            {
                if (j > 0)
                    dp[j] += dp[j - 1];
                if (dp[j] > 0)
                    hasPath = true;
            }
        }
        if (!hasPath)
            return 0;
    }

    return dp[cols - 1];
}

int main()
{
    optimize();

    int rows, cols, n;
    cin >> rows >> cols >> n;
    vector<vector<int>> matrix(rows, vector<int>(cols, 0));
    vector<pair<int, int>> blocks(n);
    for (auto &block : blocks)
    {
        cin >> block.first >> block.second;
        matrix[block.first - 1][block.second - 1] = 1;
    }

    cout << countPaths3(matrix) << endl;

    return 0;
}