#include <bits/stdc++.h>
using namespace std;

void bubble_sort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    clock_t start = clock();

    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    bubble_sort(a, n);

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    cerr << "Executed time: " << (clock() - start) / (double)CLOCKS_PER_SEC << endl;

    return 0;
}