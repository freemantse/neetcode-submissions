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
    int result = 0;
    void dfs(TreeNode* node, int max_val) {
        if (!node) return;

        if (node->val >= max_val) result++;
        max_val = max(max_val, node->val);

        dfs(node->left, max_val);
        dfs(node->right, max_val);
    }

    int goodNodes(TreeNode* root) {
        if (!root) return 0;
        dfs(root, INT_MIN);
        return result;
    }
};
