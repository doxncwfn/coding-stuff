/*
 * @lc app=leetcode id=3307 lang=cpp
 *
 * [3307] Find the K-th Character in String Game II
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    char kthCharacter(long long k, vector<int> &operations)
    {
        int mutations = 0;
        for (int op = log2(k); op >= 0; --op)
            if (k > 1LL << op)
            {
                k -= 1LL << op;
                mutations += operations[op];
            }
        return 'a' + mutations % 26;
    }
};
// @lc code=end
