#include <bits/stdc++.h>
using namespace std;

int sumOfMaxSubarray(std::vector<int> &nums, int k)
{
    if (nums.empty() || k <= 0)
        return 0;

    deque<int> dq;
    int sum = 0;
    for (int i = 0; i < nums.size(); ++i)
    {
        if (!dq.empty() && dq.front() <= i - k)
            dq.pop_front();

        while (!dq.empty() && nums[dq.back()] <= nums[i])
            dq.pop_back();

        dq.push_back(i);

        if (i >= k - 1)
            sum += nums[dq.front()];
    }

    return sum;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    clock_t start = clock();

    vector<int> nums{1, 2, 4, 3, 6};
    int k = 3;
    cout << sumOfMaxSubarray(nums, k);

    cerr << "Executed time: " << (clock() - start) / (double)CLOCKS_PER_SEC << endl;

    return 0;
}