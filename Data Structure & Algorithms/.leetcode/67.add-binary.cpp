/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string addBinary(string a, string b)
    {
        int i = a.length() - 1, j = b.length() - 1, carry = 0;
        string res = "";
        while (i >= 0 || j >= 0 || carry)
        {
            int sum = carry;
            if (i >= 0)
                sum += a[i] - '0';
            if (j >= 0)
                sum += b[j] - '0';
            res = to_string(sum % 2) + res;
            carry = sum / 2;
            i--;
            j--;
        }
        return res;
    }
};
// @lc code=end
