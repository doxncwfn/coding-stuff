#pragma GCC optimize("O3")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#define debug(x) cout << "[" << #x << "] = " << (x) << endl;
#define print cout << "Case #" << test_case << ": "
#define optimize()                \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define sz(x) (int)x.size()
#define precision(x, digit) fixed << setprecision(digit) << x
#define endl '\n'
using namespace std;

vector<long long> sieve(long long n)
{
    vector<long long> primes;
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (long long i = 2; i <= (long long)sqrt(n); i++)
        if (is_prime[i])
        {
            primes.push_back(i);
            for (long long j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    return primes;
}

int main()
{
    optimize();

    long long n;
    int k;
    cin >> n >> k;
    vector<long long> primes = sieve(n);

    return 0;
}