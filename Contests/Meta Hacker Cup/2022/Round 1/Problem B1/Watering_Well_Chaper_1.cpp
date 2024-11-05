#include </Users/macbook/C++/Contests/set_up.h>

const int MOD = 1e9 + 7;

int sum_mod(int a, int b)
{
    return (a % MOD + b % MOD) % MOD;
}

int sub_mod(int a, int b)
{
    return (a % MOD - b % MOD + MOD) % MOD;
}

int mul_mod(int a, int b)
{
    return (1LL * a % MOD * b % MOD) % MOD;
}

int result(int x1, int y1, int x2, int y2)
{
    return sum_mod(mul_mod(sub_mod(x1, x2), sub_mod(x1, x2)), mul_mod(sub_mod(y1, y2), sub_mod(y1, y2)));
}

void solve(int test_case)
{
    int n;
    cin >> n;
    vector<point> trees(n);
    for (int i = 0; i < n; i++)
        cin >> trees[i].x >> trees[i].y;

    int q;
    cin >> q;
    vector<point> wells(q);
    int total = 0;
    for (int i = 0; i < q; i++)
    {
        cin >> wells[i].x >> wells[i].y;
        for (int j = 0; j < n; j++)
            total = sum_mod(total, result(wells[i].x, wells[i].y, trees[j].x, trees[j].y));
    }

    cout << "Case #" << test_case << ": " << total << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("Meta Hacker Cup 2022 Problem B1 Input.txt", "r", stdin);
    freopen("Meta Hacker Cup 2022 Problem B1 Output.txt", "w", stdout);

    int test_cases;
    cin >> test_cases;
    for (int test_case = 1; test_case <= test_cases; test_case++)
        solve(test_case);

    return 0;
}