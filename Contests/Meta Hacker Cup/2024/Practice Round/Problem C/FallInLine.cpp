// URL: https://www.facebook.com/codingcompetitions/hacker-cup/2024/practice-round/problems/C
/*
    Problem Statement
As the queen of an ant colony, it is your job to ensure that the entire colony works together.
Your colony has N worker ants, the ith of which is currently at coordinates Xi Yi.
To align the efforts of all of your worker ants, you would like them to all be on the same line on the plane.
How many of your ants need to move to get them to all lie on the same line?
As is frequently the case in management, you do not need an exact answer, but you do need some degree of accuracy.
If the true minimum number of ants that need to move is M, then any answer between M and 2 times M inclusive will be accepted.

    Constraints
1 ≤ T ≤ 75
2 ≤ N ≤ 1,000,000
0 ≤ absolute value of Xi and Yi ≤ 1,000,000,000

In each test case, no two ants will be at the same position.
The sum of N across all test cases is at most 4,000,000.

    Input Format
Input begins with an integer T, the number of test cases.
Each case starts with a line containing the integer N.
Then N lines follow, each containing the integers Xi and Yi for the ith ant.
Output Format
For the ith test case, print "Case #i: " followed by the number of ants you need to move to get all of the ants to lie on the same line.

    Sample Explanation
- In the first case, the 4 ants are all on the line y equals x, so no ants need to be moved.
Zero is the only answer that will be accepted for this case.
- In the second case, the 4 ants are at the vertices of a square, so every line contains at most 2 of the 4 ants.
Two ants need to be moved, so the answers 2, 3, and 4 will be accepted for this case.
- In the third case, ants 2, 4, 5, and 7 all lie on the line y equals three halves times x plus one.
Moving the other 3 ants is the optimal way to get all of the ants on a single line, so any answer between 3 and 6 inclusive will be accepted for this case.
*/

#include </Users/macbook/C++/Contests/set_up.h>

void solve(int test_case)
{
    int n;
    cin >> n;

    vector<point> ants(n);
    for (auto &ant : ants)
        cin >> ant.x >> ant.y;

    int mx = 0;
    int trials = 1000;

    for (int i = 0; i < trials && i < n; i++)
    {
        int a, b;
        do
        {
            a = rand() % n;
            b = rand() % n;
        } while (a == b);
        int count = 2;
        for (int k = 0; k < n; k++)
            if (k != a && k != b && collinear(ants[a], ants[b], ants[k]))
                count++;

        mx = max(count, mx);
    }

    cout << "Case #" << test_case << ": " << n - mx << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("Fall in Line Input - Meta Hacker Cup 2024.txt", "r", stdin);
    freopen("Fall in Line Output - Meta Hacker Cup 2024.txt", "w", stdout);

    int test_cases;
    cin >> test_cases;
    for (int test_case = 1; test_case <= test_cases; test_case++)
        solve(test_case);

    return 0;
}