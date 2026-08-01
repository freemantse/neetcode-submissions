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
    int maxDep = 0;
    void dfs(TreeNode* root, int depth) {
        if (!root) return;

        maxDep = max(maxDep, depth);
        if (root->left) dfs(root->left, depth + 1);
        if (root->right) dfs(root->right, depth + 1);
    }
public:
    int maxDepth(TreeNode* root) {
        dfs(root, 1);
        return maxDep;
    }
};
