/*
 * @lc app=leetcode id=1962 lang=cpp
 *
 * [1962] Remove Stones to Minimize the Total
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minStoneSum(vector<int> &piles, int k)
    {
        priority_queue<int> pq;
        for (int i = 0; i < (int)piles.size(); i++)
            pq.push(piles[i]);
        for (int i = 0; i < k; i++)
        {
            int top = pq.top();
            pq.pop();
            pq.push(top - top / 2);
        }
        int sum = 0;
        while (!pq.empty())
        {
            sum += pq.top();
            pq.pop();
        }
        return sum;
    }
};
// @lc code=end
