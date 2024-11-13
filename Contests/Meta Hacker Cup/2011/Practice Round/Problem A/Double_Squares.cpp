#include </Users/macbook/C++/Contests/set_up.h>

void solve(int test_case)
{
    int n;
    cin >> n;

    int count = 0;
    for (int i = 0, j = (int)sqrt(n) / 2; i <= j;)
        if (i * i + j * j == n)
        {
            count++;
            i++;
            j--;
        }
        else if (i * i + j * j < n)
            i++;
        else
            j--;

    cout << "Case #" << test_case << ": " << count << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("Double Squares Input - Meta Hacker Cup 2011.txt", "r", stdin);
    freopen("Double Squares Output - Meta Hacker Cup 2011.txt", "w", stdout);

    int test_cases;
    cin >> test_cases;
    for (int test_case = 1; test_case <= test_cases; test_case++)
        solve(test_case);

    return 0;
}