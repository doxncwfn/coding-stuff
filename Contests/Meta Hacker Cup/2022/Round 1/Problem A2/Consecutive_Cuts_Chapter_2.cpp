// URL: https://www.facebook.com/codingcompetitions/hacker-cup/2022/round-1/problems/A2
/*
Let's cut to the chase. You have a deck of N face-up cards,
each displaying a not necessarily unique integer between 1 and 10^9.

Cutting the deck once consists of taking a stack of between
1 and N−1 (inclusive) cards from the top and moving it to the
bottom in the same order. For example, for the deck [5, 1, 2, 4, 3]
ordered from top to bottom, cutting 2 cards from the top would yield
[2, 4, 3, 5, 1].

Initially, the ith card from the top is Ai. Is it possible to cut
the deck exactly K times to reorder the deck such that the ith card
from the top is Bi for all i?

Constraints:
- 1 ≤ T ≤ 200 (number of test cases)
- 2 ≤ N ≤ 500,000 (number of cards)
- 0 ≤ K ≤ 10^9 (number of cuts)
- 1 ≤ Ai, Bi ≤ N (card values)

A and B are each permutations of 1..N.
The sum of N across all test cases is at most 5,000,000.

Input Format:
- Input begins with an integer T, the number of test cases.
- For each test case:
  - A line with two space-separated integers N and K.
  - A line with N space-separated integers, A1, ..., AN (initial order).
  - A line with N space-separated integers, B1, ..., BN (target order).

Output Format:
- For the ith test case, print "Case #i: " followed by "YES" if it's possible
  to cut the deck K times to change the deck from Ai to Bi, or "NO" otherwise.

Sample Explanation:
- In the first case, it's possible to get to the new order with K = 1 cut
  (cutting 2 cards from the top).
- In the second case, it's impossible to change [3, 1, 4, 2] to [1, 2, 3, 4]
  with any number of cuts.
- In the third case, it's impossible for the deck to be in a different order
  after K = 0 cuts.
*/

#include </Users/macbook/C++/Contests/set_up.h>

void check(int n, vector<int> a, vector<int> b, bool duplicate, bool &possible)
{
    vector<int> start_idxs;
    for (int i = 0; i < n; i++)
        if (a[i] == b[0])
            start_idxs.push_back(i);

    vector<bool> rotation(n, false);
    for (int &start_idx : start_idxs)
    {
        bool possible_rotation = true;
        for (int i = 0; i < n; i++)
            if (a[(start_idx + i) % n] != b[i])
            {
                possible_rotation = false;
                break;
            }
        if (possible_rotation)
            rotation[start_idx] = true;
    }

    for (bool x : rotation)
        if (x)
        {
            possible = true;
            break;
        }
}

void solve(int test_case)
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    bool duplicate = false;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        for (auto &x : a) // check for duplication
            if (!duplicate && x == a[i])
                duplicate = true;
    }
    for (int i = 0; i < n; i++)
        cin >> b[i];

    bool possible = false;
    if (k == 0)
        possible = (a == b);
    else if (k == 1)
    {
        if (duplicate)
        {
            if (a == b)
                possible = true;
            else
                check(n, a, b, duplicate, possible);
        }
        else
        {
            int start_idx;
            for (int i = 0; i < n; i++)
                if (a[i] == b[0])
                {
                    start_idx = i;
                    break;
                }
            bool rotation = true;

            for (int i = 0; i < n && !rotation; i++)
                if (b[i] != a[(i + start_idx) % n])
                {
                    rotation = false;
                    break;
                }
            possible = rotation;
        }
    }
    else if (n == 2)
        possible = duplicate ? true : (a[0] != b[0] && k % 2 == 1);
    else
        check(n, a, b, duplicate, possible);

    cout << "Case #" << test_case << ": " << (possible ? "YES" : "NO") << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("Consecutive Cuts Chapter 2 Input - Meta Hacker Cup 2022.txt", "r", stdin);
    freopen("Consecutive Cuts Chapter 2 Output - Meta Hacker Cup 2022.txt", "w", stdout);

    int test_cases;
    cin >> test_cases;
    for (int test_case = 1; test_case <= test_cases; test_case++)
        solve(test_case);

    return 0;
}