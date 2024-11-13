#include <vector>
#include <queue>
#include <iostream>
using namespace std;

#define freq first
#define num second

void sortByFrequency(int arr[], int n)
{
    vector<pair<int, int>> vt;
    for (int i = 0; i < n; i++)
    {
        bool appear = false;
        for (auto &p : vt)
            if (arr[i] == p.num)
            {
                p.freq++;
                appear = true;
                break;
            }
        if (!appear)
            vt.push_back(make_pair(1, arr[i]));
    }
    
    vector<bool> visited(vt.size(), false);
    queue<pair<int, int>> q;
    for (int i = 0; i < (int)vt.size(); i++)
    {
        int mx_frq = -1;
        for (int j = 0; j < (int)vt.size(); j++)
            if (!visited[j] && (mx_frq == -1 || vt[j].freq > vt[mx_frq].freq))
                mx_frq = j;
                
        q.push(vt[mx_frq]);
        visited[mx_frq] = true;
    }

    int idx = 0;
    while (!q.empty())
    {
        for (int i = 0; i < q.front().freq; i++)
            arr[idx++] = q.front().num;
        q.pop();
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    clock_t start = clock();

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    sortByFrequency(arr, n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cerr << "\nExecuted time: " << (clock() - start) / (double)CLOCKS_PER_SEC << endl;
    return 0;
}