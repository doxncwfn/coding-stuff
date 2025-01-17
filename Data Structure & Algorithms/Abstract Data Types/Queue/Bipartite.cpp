#include <bits/stdc++.h>
using namespace std;

bool isBipartite(vector<vector<int>> graph)
{
    int n = graph.size();
    vector<int> color(n, -1);

    for (int start = 0; start < n; ++start)
        if (color[start] == -1)
        {
            queue<int> q;
            q.push(start);
            color[start] = 0;

            while (!q.empty())
            {
                int node = q.front();
                q.pop();

                for (int neighbor : graph[node])
                    if (color[neighbor] == -1) // If the neighbor is uncolored
                    {
                        color[neighbor] = 1 - color[node]; // Color with opposite color
                        q.push(neighbor);
                    }
                    else if (color[neighbor] == color[node]) // If the neighbor has the same color
                        return false;
            }
        }
    return true;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    clock_t start = clock();

    int G[6][6] = {{0, 1, 0, 0, 0, 1},
                   {1, 0, 1, 0, 0, 0},
                   {0, 1, 0, 1, 0, 0},
                   {0, 0, 1, 0, 1, 0},
                   {0, 0, 0, 1, 0, 1},
                   {1, 0, 0, 0, 1, 0}};
    int n = 6;

    vector<vector<int>> graph(n, vector<int>());
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (G[i][j])
                graph[i].push_back(j);

    isBipartite(graph) ? cout << "Yes" : cout << "No";

    cerr << "Executed time: " << (clock() - start) / (double)CLOCKS_PER_SEC << endl;

    return 0;
}