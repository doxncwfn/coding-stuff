#include <iostream>
#include <vector>
#include <cmath>

bool isPerfectSquare(int num)
{
    int root = static_cast<int>(std::sqrt(num));
    return root * root == num;
}

// Recursive backtracking to find subsets with a square product
void findSquareProductSets(const std::vector<int> &numbers, int index, int product, std::vector<int> &subset)
{
    // Check if the current product is a perfect square
    if (product > 1 && isPerfectSquare(product))
    {
        std::cout << "{ ";
        for (int x : subset)
        {
            std::cout << x << " ";
        }
        std::cout << "} -> Product: " << product << std::endl;
    }

    // Backtracking: Add further elements to the subset
    for (int i = index; i < numbers.size(); ++i)
    {
        int newProduct = product * numbers[i];

        // Stop if product would overflow or is already too large
        if (newProduct <= 0 || newProduct > INT_MAX / numbers[i])
            break;

        subset.push_back(numbers[i]);
        findSquareProductSets(numbers, i + 1, newProduct, subset);
        subset.pop_back(); // Backtrack
    }
}

int main()
{
    int n;
    std::cout << "Enter the value of n: ";
    std::cin >> n;

    std::vector<int> numbers;
    for (int i = 1; i < n; ++i)
    {
        numbers.push_back(i);
    }

    std::cout << "Sets with a square product less than " << n << ":\n";
    std::vector<int> subset;
    findSquareProductSets(numbers, 0, 1, subset);

    return 0;
}
