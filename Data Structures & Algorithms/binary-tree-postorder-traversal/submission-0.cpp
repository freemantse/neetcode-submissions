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
    vector<int> postorderTraversal(TreeNode* root) {
        if (!root) return {};

        vector<int> result;
        stack<TreeNode*> stack;
        TreeNode* curr = root;
        TreeNode* lastVisited = nullptr;

        while (curr || !stack.empty()) {
            if (curr) {
                stack.push(curr);
                curr = curr->left;
            } else {
                TreeNode* top = stack.top();
                if (top->right && lastVisited != top->right) {
                    curr = top->right;
                } else {
                    result.push_back(top->val);
                    lastVisited = top;
                    stack.pop();
                }
            }
            
        }
        return result;
    }
};