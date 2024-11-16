/*
 * @lc app=leetcode id=468 lang=cpp
 *
 * [468] Validate IP Address
 */

// @lc code=start
class Solution
{
public:
    string validIPAddress(string queryIP)
    {
        if (queryIP.find('.') != string::npos)
        {
            if (isIPv4(queryIP))
                return "IPv4";
        }
        else if (queryIP.find(':') != string::npos)
        {
            if (isIPv6(queryIP))
                return "IPv6";
        }

        return "Neither";
    }

    bool isIPv4(string queryIP)
    {
        stringstream ss(queryIP);
        string temp;
        int count = 0;

        while (getline(ss, temp, '.'))
        {
            count++;
            if (count > 4 || temp.empty() || temp.size() > 3 || (temp.size() > 1 && temp[0] == '0'))
                return false;

            for (char c : temp)
                if (!isdigit(c))
                    return false;

            int num = stoi(temp);
            if (num < 0 || num > 255)
                return false;
        }

        return count == 4 && queryIP.back() != '.';
    }

    bool isIPv6(string queryIP)
    {
        stringstream ss(queryIP);
        string temp;
        int count = 0;

        while (getline(ss, temp, ':'))
        {
            count++;
            if (count > 8 || temp.empty() || temp.size() > 4)
                return false;

            for (char c : temp)
                if (!isxdigit(c))
                    return false;
        }

        return count == 8 && queryIP.back() != ':';
    }
};
// @lc code=end

