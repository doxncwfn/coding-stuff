//https://web.facebook.com/codingcompetitions/hacker-cup/2024/round-1/problems/A
/*
    Problem Statement
When he's not busy fighting with Dr. Robotnik, Sonic makes a living delivering submarine sandwiches via an empty subway tunnel.
The tunnel goes past N stations, numbered from 1 to N.
Station i is located i miles away from Sonic, who plans to run from one end of the tunnel to the other, tossing a sandwich to an awaiting customer at every station.

At each station, a customer is scheduled to meet Sonic within an expected delivery window.
Sonic can deliver a sandwich to station i only if he arrives within the inclusive interval [A_i, B_i] seconds.

Chasing Dr. Robotnik is tiring enough, so Sonic doesn't want to exert himself more than he has to.
If he runs at a constant speed, what’s the minimum speed, in miles per second, that will allow him to deliver to every station?
If no such constant speed exists, output -1.

Your answer will be accepted if it is within an absolute or relative error of 10^-6 (even if the expected answer is -1).

    Constraints
- 1 <= T <= 95
- 1 <= N <= 1,000,000
- 0 <= A_i < B_i <= 1,000,000
The sum of N across all test cases is at most 5,000,000.
    Input Format
Input begins with an integer T, the number of test cases.
Each case starts with a line containing the integer N.
Then, N lines follow, the i-th of which contains the integers A_i and B_i.
    Output Format
For the i-th test case, print "Case #i: "
followed by the minimum constant speed, in miles per second,
that Sonic can run that will get him to each door while it's open,
or -1 if no such constant speed exists.
*/
#include </Users/macbook/C++/Contests/set_up.h>

void solve(int test_case)
{
    int n;
    cin >> n;
    double min = -INT_MAX, max = INT_MAX;
    double result = 0;
    ;
    vt<pair<int, int>> intervals(n);
    for (int i = 0; i < n; i++)
    {
        cin >> intervals[i].first >> intervals[i].second;
        if (result != -1)
        {
            double mx = 1.0 * (i + 1) / intervals[i].first;
            double mn = 1.0 * (i + 1) / intervals[i].second;
            if (mx < max)
                max = mx;
            if (mn > min)
                min = mn;
            if (min > max)
                result = -1;
        }
    }
    if (result != -1)
        result = min;

    cout << "Case #" << test_case << ": " << result << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("Subsonic Subway Input - Meta Hacker Cup 2024.txt", "r", stdin);
    freopen("Subsonic Subway Output - Meta Hacker Cup 2024.txt", "w", stdout);

    int test_cases;
    cin >> test_cases;
    for (int test_case = 1; test_case <= test_cases; test_case++)
        solve(test_case);

    return 0;
}