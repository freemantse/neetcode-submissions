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
    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        queue<tuple<TreeNode*, long, long>> q;
        q.push(make_tuple(root, LONG_MIN, LONG_MAX));
        while (!q.empty()) {
            auto [node, min_val, max_val] = q.front();
            q.pop();
            if (node->val > min_val && node->val < max_val) {
                if (node->left) q.push(make_tuple(node->left, min_val, node->val));
                if (node->right) q.push(make_tuple(node->right, node->val, max_val));
            } else 
                return false;
        }
        return true;
    }
};
