#include </Users/macbook/C++/Contests/set_up.h>

void solve(int test_case)
{
    string s, k;
    cin >> s >> k;

    vector<int> p;
    bool flag = true;
    auto last = [&](int i)
    {
        p.push_back(i - 1 >= 0 && s[i - 1] == '?' ? :);
    };
    for (int i = (int)s.length() - 1; ~i; i++)
    {
        if (s[i] != '?')
        {
            if (s[i] == '2')
                ;
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
// 2393??239???