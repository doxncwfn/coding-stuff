#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool isPerfectSquare(int num)
{
    int root = static_cast<int>(sqrt(num));
    return root * root == num;
}

// Recursive backtracking to find subsets with a square product
void findSquareProductSets(const vector<int> &numbers, int index, int product, vector<int> &subset)
{
    if (product > 1 && isPerfectSquare(product)) // Check if the current product is a perfect square
    {
        cout << "{ ";
        for (int x : subset)
            cout << x << " ";
        cout << "} -> " << product << endl;
    }

    for (int i = index; i < numbers.size(); ++i) // Backtracking: Add further elements to the subset
    {
        int newProduct = product * numbers[i];
        if (newProduct <= 0 || newProduct > INT_MAX / numbers[i]) // Stop if product would overflow or is already too large
            break;

        subset.push_back(numbers[i]);
        findSquareProductSets(numbers, i + 1, newProduct, subset);
        subset.pop_back(); // Backtracking
    }
}

int main()
{
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    vector<int> numbers;
    for (int i = 1; i < n; ++i)
        numbers.push_back(i);

    cout << "Sets with a square product less than " << n << ":\n";
    vector<int> subset;
    findSquareProductSets(numbers, 0, 1, subset);

    return 0;
}
