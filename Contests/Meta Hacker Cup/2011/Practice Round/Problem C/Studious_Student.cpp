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
    int n;
    cin >> n;
    vt<string> words(n);
    trav(word, words) cin >> word;

    sort(all(words), [](string a, string b)
    {
        return a + b < b + a;
    });
    string result = "";
    trav(word, words)
    {
        // cout << word << " ";
        result += word;
    }
    // cout << endl;
    cout << "Case #" << test_case << ": " << result << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("Studious Student Input - Meta Hacker Cup 2011.txt", "r", stdin);
    freopen("Studious Student Output - Meta Hacker Cup 2011tput.txt", "w", stdout);

    int test_cases;
    cin >> test_cases;
    for (int test_case = 1; test_case <= test_cases; test_case++)
        solve(test_case);

    return 0;
}