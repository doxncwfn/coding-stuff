class Solution
{
public:
    // long long findScore(vector<int>& nums)
    // {
    //     long long score = 0;
    //     vector<bool> marked(nums.size(), false);
    //     while (find(marked.begin(), marked.end(), false) != marked.end())
    //     {
    //         int min = INT_MAX, idx = 0;
    //         for (int i = 0; i < nums.size(); i++)
    //             if (!marked[i])
    //                 if (nums[i] < min)
    //                 {
    //                     min = nums[i];
    //                     idx = i;
    //                 }

    //         score += min;
    //         marked[idx] = true;
    //         if (idx > 0)
    //             marked[idx - 1] = true;
    //         if (idx < nums.size() - 1)
    //             marked[idx + 1] = true;
    //     }

    //     return score;
    // }
    long long findScore(vector<int>& nums)
    {
        long long score = 0;
        int n = nums.size();
        deque<int> q;

        // Traverse through the array
        for (int i = 0; i < n; i++)
        {
            // If queue is not empty and the current number is greater than or equal to the last in queue
            if (!q.empty() && nums[i] >= q.back())
            {
                bool skip = false;
                // Process the elements in the queue
                while (!q.empty())
                {
                    int add = q.back();
                    q.pop_back();
                    if (!skip)
                        score += add;

                    skip = !skip;
                }
                continue;
            }

            // Add current element to the queue
            q.push_back(nums[i]);
        }

        // Final processing of remaining elements in the queue
        bool skip = false;
        while (!q.empty())
        {
            int add = q.back();
            q.pop_back();
            if (!skip)
                score += add;

            skip = !skip;
        }

        return score;
    }
};