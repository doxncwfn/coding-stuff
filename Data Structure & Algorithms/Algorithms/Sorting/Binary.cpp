#include <bits/stdc++.h>
using namespace std;

void binary_sort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int left = i + 1, right = n - 1, mid;
        while (left <= right)
        {
            mid = left + (right - left) / 2;
            if (a[mid] < a[i])
                left = mid + 1;
            else
                right = mid - 1;
        }
        int key = a[i];
        for (int j = i; j < right; j++)
            a[j] = a[j + 1];
        a[right] = key;
    }
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

    binary_sort(a, n);

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    cerr << "Executed time: " << (clock() - start) / (double)CLOCKS_PER_SEC << endl;

    return 0;
}