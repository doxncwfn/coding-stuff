/*
Given a n*m grid where each cell in the grid can have a value of 0, 1 or 2, which has the following meaning:
1. Empty cell
2. This cell contains a fresh apple
3. This cell contains a rotten apple
After 1 second, the cell with rotten apple will rot all fresh apples in all the cells adjacent to it (i.e the cells (x+1, y), (x-1, y), (x, y+1), (x, y-1))
Determine the minimum time (in seconds) required to rot all apples. If this cannot be done, return -1.

Constraint:
1 <= n, m <= 500
*/

#include <bits/stdc++.h>
using namespace std;

struct Cell
{
    int x, y;
};

bool isValid(int x, int y, int n, int m)
{
    return (x >= 0 && y >= 0 && x < n && y < m);
}

int secondsToBeRotten(vector<vector<int>> &grid)
{
    int n = grid.size();
    if (n == 0)
        return -1;
    int m = grid[0].size();

    queue<Cell> q;
    int freshCount = 0;
    int time = 0;
    vector<Cell> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (grid[i][j] == 2)
                q.push({i, j});
            else if (grid[i][j] == 1)
                freshCount++;

    if (freshCount == 0)
        return 0;

    while (!q.empty())
    {
        int qSize = q.size();
        bool hasRottenThisRound = false;

        for (int i = 0; i < qSize; i++)
        {
            Cell rotten = q.front();
            q.pop();

            for (auto dir : directions)
            {
                int newX = rotten.x + dir.x;
                int newY = rotten.y + dir.y;

                if (isValid(newX, newY, n, m) && grid[newX][newY] == 1)
                {
                    grid[newX][newY] = 2;
                    q.push({newX, newY});
                    freshCount--;
                    hasRottenThisRound = true;
                }
            }
        }
        if (hasRottenThisRound)
            time++;
    }
    return (freshCount == 0) ? time : -1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    clock_t start = clock();
    vector<vector<int>> grid = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};

    cerr << "Executed time: " << (clock() - start) / (double)CLOCKS_PER_SEC << endl;

    return 0;
}