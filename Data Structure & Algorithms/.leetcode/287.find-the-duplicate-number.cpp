/*
 * @lc app=leetcode id=287 lang=cpp
 *
 * [287] Find the Duplicate Number
 */

// @lc code=start
class Solution
{
public:
    int binarySearch(int arr[], int low, int high, int x)
    {
        if (high >= low)
        {
            int mid = low + (high - low) / 2;
            if (arr[mid] == x)
                return mid;

            if (arr[mid] > x)
                return binarySearch(arr, low, mid - 1, x);

            return binarySearch(arr, mid + 1, high, x);
        }
    return -1;
    }

    int findDuplicate(vector<int>& nums)
    {
        // sort(nums.begin(), nums.end());
        // for (int i = 0; i < (int)nums.size() - 1; i++)
        //     if (nums[i] == nums[i + 1])
        //         return nums[i];
        for (int i = 0; i < (int)nums.size(); i++)
            if (binarySearch(nums, i, nums.size() - i, nums[i]) != -1)
                return nums[i];
    }
};
// @lc code=end

