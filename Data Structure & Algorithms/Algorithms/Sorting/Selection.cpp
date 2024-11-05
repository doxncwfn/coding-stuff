#include <iostream>
using namespace std;

void selection_sort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
            if (a[j] < a[min_idx])
                min_idx = j;
        swap(a[i], a[min_idx]);
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

    selection_sort(a, n);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    cerr << "Executed time: " << (clock() - start) / (double)CLOCKS_PER_SEC << endl;
    return 0;
}