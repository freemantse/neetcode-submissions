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
    int count;
    int value;
    void dfs(TreeNode* node) {
        if (!node) return;
        if (count == 0) return;

        dfs(node->left);
        count--;
        if (count == 0) {
            value = node->val;
            return;
        }
        dfs(node->right);
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        count = k;
        dfs(root);
        return value;
    }
};
