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
    vector<int> preorderTraversal(TreeNode* root) {
        if (!root) return {};
        stack<TreeNode*> stack;
        vector<int> result;
        stack.push(root);

        while (!stack.empty()) {
            TreeNode* top = stack.top();
            stack.pop();
            result.push_back(top->val);
            if (top->right) stack.push(top->right);
            if (top->left) stack.push(top->left);
        }
        return result;
    }
};