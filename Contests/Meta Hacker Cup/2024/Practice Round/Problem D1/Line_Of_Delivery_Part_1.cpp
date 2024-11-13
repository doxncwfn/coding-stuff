// URL: https://www.facebook.com/codingcompetitions/hacker-cup/2024/practice-round/problems/D1
/*
    Problem Statement
Candice is playing a solitaire game of curling on a 1-dimensional sheet of ice, using stones of negligible size.
She will throw N stones, numbered 1 to N, from position 0, targeting a position G units to the right.
In curling, although we say a stone is “thrown,” it’s actually slid along the ice.

The ith stone will be thrown with energy Ei and will travel Ei units to the right unless it collides with another stone.
If it collides with another stone, it transfers its remaining energy to the stone it hits.
Formally, this process repeats until all stones are stationary:

If the moving stone is at the same position as a stationary stone, the moving stone stops.
The stone it hits then becomes the moving stone with the remaining energy of the previous moving stone.

Otherwise, the moving stone moves 1 unit to the right, and its energy is reduced by 1.
If the moving stone’s energy becomes 0, it becomes stationary.

After all of the stones are thrown, which stone ends up closest to the goal position G, and how far away from the goal is it?

    Constraints
1 ≤ T ≤ 85
1 ≤ N ≤ 300,000
1 ≤ Ei, G ≤ 1,000,000
In each test case, no two stones are thrown with the same energy.
The sum of N across all test cases is at most 2,000,000.

    Input Format
Input begins with an integer T, the number of test cases.
Each case starts with a line containing the integers N and G.
Then N lines follow, each containing Ei for the ith stone.

    Output Format
For the ith test case, print "Case #i: " followed by the index of the stone that ends up closest to the goal G and how far away it is from G.
If there’s a tie, output the stone with the lowest index.

    Sample Explanation

- In the first case, no stones collide.
    The stones end up at positions 7 and 2, respectively, so the first stone is the closest to the goal (5) and is 2 units away.

- In the second case:
    The third stone collides with the second stone, stopping at position 5.
    The second stone then continues on to position 7.
    The final positions of the stones, in order, are [9, 7, 5].
    The third stone is closest to the goal (1) and ends up 4 units away.
- In the third case:
    The final positions of the stones are [9, 8, 7, 6].
    The third stone ends up exactly on the goal.

- In the fourth case, both stones are equally distant from the goal.
    We break ties by picking the stone with the lower index.
*/

#include <bits/stdc++.h>
using namespace std;

#define vt vector
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define mp make_pair
#define fi first
#define se second

#define endl '\n'

struct point
{
    double x, y;
};
double Euclidian_distance(point a, point b) { return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y)); }
bool collinear(point a, point b, point c) { return (b.y - a.y) * (c.x - b.x) == (c.y - b.y) * (b.x - a.x); }

#define FOR(i, a, b) for (int i = a; i < b; i++)
#define ROF(i, a, b) for (int i = a; i >= b; i--)
#define trav(a, x) for (auto &a : x)

string decimalToBinary(int n)
{
    string binary = "";
    while (n > 0)
    {
        binary = to_string(n % 2) + binary;
        n /= 2;
    }
    return binary;
}

void solve(int test_case)
{
    int N, goal;
    cin >> N >> goal;
    vt<int> energy(N);
    for (int &e : energy)
        cin >> e;

    sort(all(energy));

    int idx = 0;
    for (int i = 1; i < N; i++)
        if (abs(goal - energy[i]) <= abs(goal - energy[idx]))
            idx = i;

    cout << "Case #" << test_case << ": " << N - idx << " " << abs(energy[idx] - goal) << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("Line of Delivery Part 1 Input.txt", "r", stdin);
    freopen("Line of Delivery Part 1 Output.txt", "w", stdout);

    int test_cases;
    cin >> test_cases;
    for (int test_case = 1; test_case <= test_cases; test_case++)
        solve(test_case);

    return 0;
}