#include <bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>> graph, int start)
{
    int n = graph.size();
    vector<bool> visited(n, false);
    queue<int> q;

    q.push(start);
    visited[start] = true;

    while (!q.empty())
    {
        int current = q.front();
        q.pop();
        cout << current << " ";
        for (int neighbor : graph[current])
            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                q.push(neighbor);
            }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    clock_t start = clock();
    int init_graph[10][10] = {{0, 1, 1, 0, 1, 0, 1, 0, 1, 0},
                              {0, 0, 1, 1, 0, 0, 0, 1, 0, 0},
                              {0, 1, 0, 0, 0, 1, 1, 0, 1, 1},
                              {1, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                              {0, 1, 0, 0, 0, 0, 0, 1, 0, 0},
                              {1, 0, 1, 0, 1, 0, 0, 0, 1, 0},
                              {0, 0, 1, 1, 0, 1, 0, 0, 0, 0},
                              {1, 0, 0, 0, 0, 1, 1, 0, 1, 0},
                              {0, 0, 0, 0, 0, 1, 0, 1, 0, 1},
                              {1, 0, 1, 0, 1, 0, 0, 0, 1, 0}};
    int n = 10;
    vector<vector<int>> graph(n, vector<int>());
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (init_graph[i][j])
                graph[i].push_back(j);
        }
    }

    bfs(graph, 0);

    cerr << "Executed time: " << (clock() - start) / (double)CLOCKS_PER_SEC << endl;

    return 0;
}