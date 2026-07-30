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
        stack<pair<TreeNode*, bool>> stack;
        stack.push({root, false});

        while (!stack.empty()) {
            auto [curr, flag] = stack.top();
            stack.pop();

            if (!curr) continue;

            if (flag) {
                result.push_back(curr->val);
            } else {
                stack.push({curr, true});
                stack.push({curr->right, false});
                stack.push({curr->left, false});
            }
        }
        return result;
    }
};