// URL: https://www.facebook.com/codingcompetitions/hacker-cup/2024/practice-round/problems/A
/*
    Problem Statement
You have found a solution to an implementation-heavy geometry problem that requires typing out N lines of code.
Annoyingly you only have a P percent chance of typing out any given line without a mistake and your code will only be accepted if all N lines are correct.
The chance of making a mistake in one line is independent of the chance of making a mistake in any other line.
You realize there might be a solution which only requires N minus 1 lines each also having a P percent chance of being typed correctly.
However instead of thinking about that you could also just type out the N-line solution more carefully to increase P.
How much would P have to increase to yield the same chance of success as needing to type one fewer line of code

    Constraints
1 ≤ T ≤ 100
2 ≤ N ≤ 1000
1 ≤ P ≤ 99

 Input Format

Input begins with an integer T the number of test cases
Each test case is a single line containing the integers N and P

    Output Format
For the ith test case print "Case #i: " followed by
how much higher P would need to be to make spending your time typing carefully
be as successful as typing one line fewer with your original P
Your answer will be accepted if it is within an absolute or relative error of 10^(-6)

Sample Explanation
In the first case you initially need to type 2 lines.
You can either type just 1 line with a 50 percent success rate
or you could improve your typing accuracy to approximately 70.710678 percent
at which point you would have a 50 percent squared chance of successfully typing the original 2 lines.
So you would need to increase P by 70.710678 minus 50 which equals 20.710678 for both approaches to have an equal chance of success
*/

#include </Users/macbook/C++/Contests/set_up.h>

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("Line by Line Input - Meta Hacker Cup 2024.txt", "r", stdin);
    freopen("Line by Line Output - Meta Hacker Cup 2024.txt", "w", stdout);

    int test_cases;
    cin >> test_cases;

    for (int i = 0; i < test_cases; i++)
    {
        int n, p;
        cin >> n >> p;
        double pctg = 0.01 * p;
        double q = pow(pctg, 1 - 1.0 / n); // p^(n-1) = q^n
        cout << "Case #" << i << ": " << fixed << setprecision(15) << 100 * (q - pctg) << endl;
    };
    return 0;
}