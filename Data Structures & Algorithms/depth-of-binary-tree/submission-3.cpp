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
    int maxDepth(TreeNode* root) {
        if (!root) return 0;

        stack<pair<TreeNode*, int>> stack;
        stack.push({root, 1});
        int result = 0;

        while (!stack.empty()) {
            auto [curr, depth] = stack.top();
            stack.pop();
            if (curr->left) stack.push({curr->left, depth + 1});
            if (curr->right) stack.push({curr->right, depth + 1});

            result = max(result, depth);
        }
        return result;
    }
};
