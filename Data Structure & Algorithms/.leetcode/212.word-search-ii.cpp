/*
 * @lc app=leetcode id=212 lang=cpp
 *
 * [212] Word Search II
 */

// @lc code=start
class Solution
{
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words)
    {
        vector<string> res;
        TrieNode* root = buildTrie(words);
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                dfs(board, visited, i, j, root, res);
        return res;
    }

private:
    struct TrieNode
    {
        TrieNode* next[26] = {};
        string word;
    };

    TrieNode* buildTrie(vector<string>& words)
    {
        TrieNode* root = new TrieNode();
        for (string& word : words)
        {
            TrieNode* node = root;
            for (char c : word)
            {
                if (!node->next[c - 'a'])
                    node->next[c - 'a'] = new TrieNode();
                node = node->next[c - 'a'];
            }
            node->word = word;
        }
        return root;
    }

    void dfs(vector<vector<char>>& board, vector<vector<bool>>& visited, int i, int j, TrieNode* node, vector<string>& res)
    {
        if (!node || i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || visited[i][j])
            return;
        node = node->next[board[i][j] - 'a'];
        if (!node)
            return;
        if (!node->word.empty())
        {
            res.push_back(node->word);
            node->word.clear();
        }
        visited[i][j] = true;
        dfs(board, visited, i - 1, j, node, res);
        dfs(board, visited, i + 1, j, node, res);
        dfs(board, visited, i, j - 1, node, res);
        dfs(board, visited, i, j + 1, node, res);
        visited[i][j] = false;
    }
};
// @lc code=end

