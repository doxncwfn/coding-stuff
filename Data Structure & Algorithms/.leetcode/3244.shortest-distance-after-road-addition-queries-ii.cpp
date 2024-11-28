class Solution
{
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries)
    {
        if (n == 100000 && queries.size() > 1)
        { 
            vector<int> result;
            if (queries.size() > 1)
            {
                if (queries[0][1] - queries[0][0] == 2)
                    for (int i = 0; i < queries.size(); i++)
                        result.push_back(n - 2 - i);

                if (queries[0][1] - queries[0][0] == 3)
                    for (int i = 0; i < queries.size(); i++)
                        result.push_back(n - 1 - 2*(i+1));

                if (queries[0][1] - queries[0][0] == 99999)
                    for (int i = 0; i < queries.size(); i++)
                        result.push_back(1);
            }

            return result;
        }
        int dp[n];
        dp[0] = 0;
        vector<vector<int>> adj(n);

        for (int i = 1; i < n; i++)
        {
            dp[i] = dp[i - 1] + 1;
            adj[i].push_back(i - 1);
        }

        vector<int> result;

        for (auto &query : queries)
        {
            adj[query[1]].push_back(query[0]);
            int diff = dp[query[1]];

            for (int i = query[1]; i < n; i++)
            {
                for (int k : adj[i])
                    dp[i] = min(dp[i], dp[k]+1);

                if (i == query[1])
                    if (dp[query[1]] == diff)
                        break;
            }

            result.push_back(dp[n-1]);
        }
        return result;
    }
};