// URL: https://www.facebook.com/codingcompetitions/hacker-cup/2024/practice-round/problems/D2
/*
    Problem Statement
Candice is playing a solitaire game of curling on a 1-dimensional sheet of ice, using stones that are 1 unit wide.
She will throw N stones, numbered 1 to N, from position 0, targeting a position G units to the right.
In curling, although we say a stone is “thrown,” it is actually slid along the ice.

The ith stone will be thrown with energy Ei and will travel Ei units to the right unless it collides with another stone.
In the event of a collision, it transfers its remaining energy to the stone it hits.
This process is repeated formally until all stones are stationary:

If the moving stone is at position p and there is a stationary stone at position p + 1, the moving stone stops at position p.
The stone at position p + 1 then becomes the moving stone with the remaining energy of the previous moving stone.

Otherwise, the moving stone moves 1 unit to the right, and its energy is reduced by 1.
If the moving stone's energy becomes 0, it becomes stationary.

After all stones are thrown, determine which stone is closest to the goal position G and how far away it is from G.

    Constraints
1 ≤ T ≤ 80
1 ≤ N ≤ 300,000
1 ≤ G ≤ 1,000,000
N ≤ Ei ≤ 1,000,000

All stones are thrown with energy Ei ≥ N, ensuring that stones do not pile up near Candice, although the energies are not necessarily unique.
The sum of N across all test cases is at most 2,000,000.

    Input Format

Input begins with an integer T, the number of test cases.
Each case starts with a line containing the integers N and G.
Then N lines follow, each containing Ei for the ith stone.
Output Format
For the ith test case, print "Case #i: " followed by the index of the stone that ends up closest to the goal G and how far away it is from G.
If there is a tie, output the stone with the lowest index.

    Sample Explanation

- In the third sample case:
    The first stone stops at position 8, and the second stone stops at position 7.
    The third stone starts with an energy of 9 but stops at position 6, transferring 3 energy to the second stone.
    The second stone is already touching the first stone, so it transfers 3 energy to the first stone, which then moves to position 11.
    The fourth stone starts with energy 6 and stops at position 5, transferring 1 energy to the next stone.
    The next stone again transfers 1 energy to the subsequent stone, which then moves to position 8.
    Thus, the final positions of the stones are [11, 8, 6, 5], with stone 2 being at position 8, the goal.
*/

#include </Users/macbook/C++/Contests/set_up.h>

void solve(int test_case)
{
    int n, goal;
    cin >> n >> goal;
    vt<int> energy(n);

    int max_energy = 0;
    for (int &i : energy)
    {
        cin >> energy[i];
        max_energy = max(max_energy, energy[i]);
    }

    vt<bool> has_stone(max_energy, false);

    for (int i = 0; i < n; i++)
    {
        int remaining_energy = energy[i];
        int position = 0;
        bool collide = false;
        while (remaining_energy)
        {
            if (has_stone[position])
            {
                collide = true;
            }
            else
            {
                position++;
                remaining_energy--;
            }
        }
    }

    cout << "Case #" << test_case << ": " << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);

    int test_cases;
    cin >> test_cases;
    for (int test_case = 1; test_case <= test_cases; test_case++)
        solve(test_case);

    return 0;
}