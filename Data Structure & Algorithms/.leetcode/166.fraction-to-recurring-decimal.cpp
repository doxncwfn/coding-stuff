/*
 * @lc app=leetcode id=166 lang=cpp
 *
 * [166] Fraction to Recurring Decimal
 */

// @lc code=start
#include <bits/stdc++.h>
class Solution
{
public:
    string fractionToDecimal(int numerator, int denominator)
    {
        string s = "";
        if (numerator == 0)
            return "0";
        if (numerator < 0 ^ denominator < 0)
            s += "-";
        long n = labs(numerator);
        long d = labs(denominator);
        s += to_string(n / d);
        long r = n % d;
        if (r == 0)
            return s;
        s += ".";
        unordered_map<long, int> m;
        while (r)
        {
            if (m.find(r) != m.end())
            {
                s.insert(m[r], 1, '(');
                s += ")";
                break;
            }
            m[r] = s.size();
            r *= 10;
            s += to_string(r / d);
            r %= d;
        }
        return s;
    }
};
// @lc code=end
