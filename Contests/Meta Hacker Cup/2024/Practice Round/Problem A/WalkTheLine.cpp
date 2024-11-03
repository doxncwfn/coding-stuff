// URL: https://www.facebook.com/codingcompetitions/hacker-cup/2024/practice-round/problems/B

/*
        Problem Statement
There is an old narrow bridge that a group of N travelers wishes to cross at night.
The bridge can only support the weight of at most 2 people.
Crossers must stay together and use the group’s only flashlight while on the bridge.
Traveler i can cross the bridge in Si seconds alone.
The group brought along a very lightweight wheelbarrow. There are two ways to cross:
- Traveler i can cross the bridge alone in Si seconds optionally bringing the wheelbarrow or
- Two travelers i and j can both cross in Si seconds if traveler j rides in the wheelbarrow
Any group crossing the bridge must bring the flashlight and it can be returned to the initial side following the same rules as above.
The question is whether there is a strategy for all travelers to cross the bridge within K seconds

         Constraints
1 ≤ T ≤ 95
1 ≤ N ≤ 1000
1 ≤ Si K ≤ 1000000000

         Input Format
- The first line contains an integer T the number of test cases
- Each test case begins with a line containing the integers N and K
- Then N lines follow with the ith line containing the integer Si

         Output Format
For the ith test case print "Case #i: " followed by "YES" if all travelers can cross the bridge within K seconds or "NO" if they cannot

         Sample Explanation
- In the first case a possible strategy is
     Traveler 3 carries traveler 4 across and then returns alone
     Traveler 2 carries traveler 3 across and then returns alone
     Traveler 1 carries traveler 2 across
     This takes a total time of 5 + 5 + 2 + 2 + 1 = 15 seconds
- In the second case there is no strategy that allows all 4 travelers to cross within 4 seconds
- In the third case both travelers can cross in exactly 22 seconds if they travel together
*/

#include </Users/macbook/C++/Contests/set_up.h>

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("Walk The Line Input - Meta Hacker Cup 2024.txt", "r", stdin);
    freopen("Walk The Line Output - Meta Hacker Cup 2024.txt", "w", stdout);

    int test_cases;
    cin >> test_cases;

    for (int i = 0; i < test_cases; i++)
    {
        int n;
        int64_t k;
        cin >> n >> k;

        vector<int64_t> a(n);
        for (auto &x : a)
            cin >> x;

        sort(a.begin(), a.end());
        int64_t t = max((2 * n - 3), 1) * a[0];
        cout << "Case #" << i + 1 << ": " << (t <= k ? "YES" : "NO") << endl;
    };

    return 0;
}