/*
 * @lc app=leetcode id=1701 lang=cpp
 *
 * [1701] Average Waiting Time
 */

// @lc code=start
class Solution
{
public:
    double averageWaitingTime(vector<vector<int>>& customers)
    {
        double result = 0;
        long long current = 0;
        for (auto &x : customers)
        {
            int arrive = x[0], order = x[1];
            if (current < arrive)
                current = arrive;
            result += current + order - arrive;
            current += order;
        }
        return result / customers.size();
    };    
};
// @lc code=end