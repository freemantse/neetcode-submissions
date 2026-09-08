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
class Solution {
public:
    bool dfs(TreeNode* node, int currSum, int targetSum) {
        if (!node) return false;

        int newSum = currSum + node->val;

        if (!node->left && !node->right && newSum == targetSum) 
            return true;
        
        return dfs(node->left, newSum, targetSum) || dfs(node->right, newSum, targetSum);
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;

        return dfs(root, 0, targetSum);
    }
};