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

bool collinear(point a, point b, point c) { return (b.y - a.y) * (c.x - b.x) == (c.y - b.y) * (b.x - a.x); }

#define FOR(i, a, b) for (int i = a; i < b; i++)
#define ROF(i, a, b) for (int i = a; i >= b; i--)
#define trav(a, x) for (auto &a : x)