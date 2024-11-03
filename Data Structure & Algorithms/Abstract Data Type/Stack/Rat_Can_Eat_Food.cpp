#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

bool valid(pair<int, int> position)
{
    return position.x >= 0 && position.x < 5 && position.y >= 0 && position.y < 5;
}

bool canEatFood(int maze[5][5], int fx, int fy)
{
    bool visited[5][5] = {false};
    visited[0][0] = true;
    stack<pair<int, int>> toVisit;
    toVisit.push(make_pair(0, 0));

    while (!toVisit.empty())
    {
        pair<int, int> current = toVisit.top();
        toVisit.pop();

        if (current.x == fx && current.y == fy)
            return true;

        pair<int, int> directions[4] =
            {
                make_pair(current.x, current.y + 1),
                make_pair(current.x + 1, current.y),
                make_pair(current.x, current.y - 1),
                make_pair(current.x - 1, current.y)};

        for (auto dir : directions)
            if (valid(dir) && !visited[dir.x][dir.y] && maze[dir.x][dir.y])
            {
                toVisit.push(dir);
                visited[dir.x][dir.y] = true;
            }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    clock_t start = clock();
    int maze[5][5] =
        {
            {1, 0, 0, 0, 0},
            {1, 1, 1, 1, 1},
            {0, 1, 0, 0, 1},
            {0, 1, 1, 1, 1},
            {0, 0, 0, 0, 1}};
    cout << canEatFood(maze, 4, 4) << endl;

    cerr << "Executed time: " << (clock() - start) / (double)CLOCKS_PER_SEC << endl;

    return 0;
}