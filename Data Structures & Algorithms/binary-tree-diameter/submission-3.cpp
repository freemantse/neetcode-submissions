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
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        stack<TreeNode*> stack;
        unordered_map<TreeNode*, int> mp;
        mp[nullptr] = 0;
        int result = 0;

        stack.push(root);

        while (!stack.empty()) {
            TreeNode* curr = stack.top();
            if (curr->left && !mp.contains(curr->left)) {
                stack.push(curr->left);
            } else if (curr->right && !mp.contains(curr->right)) {
                stack.push(curr->right);
            } else {
                stack.pop();
                mp[curr] = 1 + max(mp[curr->left], mp[curr->right]);
                result = max(result, mp[curr->left] + mp[curr->right]);
            }
        }
        return result;
    }
};
