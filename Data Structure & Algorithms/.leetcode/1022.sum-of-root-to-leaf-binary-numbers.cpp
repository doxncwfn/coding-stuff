/*
 * @lc app=leetcode id=1022 lang=cpp
 *
 * [1022] Sum of Root To Leaf Binary Numbers
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
    int sumRootToLeaf(TreeNode *root)
    {
        int sum = 0;
        dfs(root, 0, sum);
        return sum;
    }
    void dfs(TreeNode *root, int val, int &sum)
    {
        if (!root)
            return;
        val = val * 2 + root->val;
        if (!root->left && !root->right)
        {
            sum += val;
            return;
        }
        dfs(root->left, val, sum);
        dfs(root->right, val, sum);
    }
};
// @lc code=end
