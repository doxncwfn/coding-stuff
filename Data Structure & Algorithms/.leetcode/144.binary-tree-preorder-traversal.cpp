/*
 * @lc app=leetcode id=144 lang=cpp
 *
 * [144] Binary Tree Preorder Traversal
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
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> res;
        stack<TreeNode *> s;
        TreeNode *cur = root;
        while (cur || !s.empty())
        {
            while (cur)
            {
                res.push_back(cur->val);
                s.push(cur);
                cur = cur->left;
            }
            cur = s.top();
            s.pop();
            cur = cur->right;
        }
        return res;
    }
};
// @lc code=end
