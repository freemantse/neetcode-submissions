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
private:
    int dfs(TreeNode* node, int& result) {
        if (!node) return 0;

        int left = dfs(node->left, result);
        int right = dfs(node->right, result);
        result = max(result, left + right);
        return 1 + max(left, right);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        int result = 0;
        dfs(root, result);
        return result;
    }
};
