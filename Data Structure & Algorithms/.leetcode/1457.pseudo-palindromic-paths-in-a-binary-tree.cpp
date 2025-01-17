/*
 * @lc app=leetcode id=1457 lang=cpp
 *
 * [1457] Pseudo-Palindromic Paths in a Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    int pseudoPalindromicPaths(TreeNode *root)
    {
        vector<int> count(10, 0);
        return dfs(root, count);
    }

    int dfs(TreeNode *root, vector<int> count)
    {
        if (root == nullptr)
            return 0;

        count[root->val]++;
        if (root->left == nullptr && root->right == nullptr)
        {
            int odd = 0;
            for (int i = 1; i <= 9; i++)
            {
                if (count[i] % 2 == 1)
                    odd++;
            }
            if (odd <= 1)
                return 1;
            else
                return 0;
        }

        int left = dfs(root->left, count);
        int right = dfs(root->right, count);

        return left + right;
    }
};
// @lc code=end
