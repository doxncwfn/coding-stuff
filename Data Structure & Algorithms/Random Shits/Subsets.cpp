#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    clock_t start = clock();

    int n;
    cin >> n;
    cout << "\n";
    for (int i = 0; i < (1 << n); i++)
    {
        vector<int> v;
        for (int j = 0; j < n; j++)
            if (i & (1 << j))
                v.push_back(j + 1);
        cout << "[";
        for (int j = 0; j < v.size(); j++)
            cout << v[j] << ((j == v.size() - 1) ? "]\n" : ", ");
    }

    cerr << "Executed time: " << (clock() - start) / (double)CLOCKS_PER_SEC << endl;

    return 0;
}