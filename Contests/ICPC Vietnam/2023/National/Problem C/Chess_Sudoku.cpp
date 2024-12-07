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
#define print cout << "Case #" << test_case << ": "
#define optimize() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define precision(x, digit) fixed << setprecision(digit) << x
#define endl '\n'
using namespace std;

#define N 9

using namespace std;

int knightMoves[8][2] = {{-2, -1}, {-1, -2}, {1, -2}, {2, -1}, {2, 1}, {1, 2}, {-1, 2}, {-2, 1}};
int kingMoves[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

bool isValid(vector<vector<int>> &grid, int row, int col, int num)
{
    for (int i = 0; i < N; i++)
        if (grid[row][i] == num || grid[i][col] == num)
            return false;

    // Check 3x3 subgrid
    int startRow = (row / 3) * 3, startCol = (col / 3) * 3;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (grid[startRow + i][startCol + j] == num)
                return false;


    // Check knight moves
    for (auto &move : knightMoves)
    {
        int newRow = row + move[0], newCol = col + move[1];
        if (newRow >= 0 && newRow < N && newCol >= 0 && newCol < N && grid[newRow][newCol] == num)
            return false;
    }

    // Check king moves
    for (auto &move : kingMoves)
    {
        int newRow = row + move[0], newCol = col + move[1];
        if (newRow >= 0 && newRow < N && newCol >= 0 && newCol < N && grid[newRow][newCol] == num)
            return false;
    }

    return true;
}

bool solveChessSudoku(vector<vector<int>> &grid)
{
    for (int row = 0; row < N; row++)
        for (int col = 0; col < N; col++)
            if (grid[row][col] == 0)
            {
                for (int num = 1; num <= 9; num++)
                    if (isValid(grid, row, col, num))
                    {
                        grid[row][col] = num; // Place the number
                        if (solveChessSudoku(grid)) // Recur to solve the rest
                            return true;
                        grid[row][col] = 0; // Backtrack
                    }
                return false; // Trigger backtracking
            }
    return true;
}

void printGrid(const vector<vector<int>> &grid)
{
    for (const auto &row : grid)
    {
        for (int num : row)
            cout << num << " ";
        cout << endl;
    }
}

int main()
{
    optimize();

    vector<vector<int>> grid(N, vector<int>(N));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> grid[i][j];

    if (solveChessSudoku(grid))
        printGrid(grid);
    else
        cout << "NO SOLUTION" << endl;


    return 0;
}