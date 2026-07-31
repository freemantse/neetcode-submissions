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
    vector<int> result;
    void dfs(TreeNode* node, int depth) {
        if (depth == result.size()) result.push_back(node->val);

        if (node->right) dfs(node->right, depth + 1);
        if (node->left) dfs(node->left, depth + 1);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};
        dfs(root, 0);
        return result;
    }
};
