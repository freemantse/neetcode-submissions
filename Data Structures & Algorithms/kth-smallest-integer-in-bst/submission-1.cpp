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
    int result;

    void dfs(TreeNode* node, int& count) {
        if (!node) return; 
        dfs(node->left, count);

        if (count == 1) result = node->val;
        count--;

        dfs(node->right, count);
    }

    int kthSmallest(TreeNode* root, int k) {
        dfs(root, k);
        return result;
    }
};
