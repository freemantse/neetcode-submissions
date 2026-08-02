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
        unordered_map<TreeNode*,pair<int,int>> mp;
        mp[nullptr] = {0,0};
        stack<TreeNode*> stack;
        stack.push(root);

        while (!stack.empty()) {
            TreeNode* top = stack.top();

            if (top->left && !mp.contains(top->left)) {
                stack.push(top->left);
            } else if (top->right && !mp.contains(top->right)) {
                stack.push(top->right);
            } else {
                stack.pop();
                
                auto [leftHeight, leftDiameter] = mp[top->left];
                auto [rightHeight, rightDiameter] = mp[top->right];

                int height = 1 + max(leftHeight, rightHeight);
                int diameter = max(leftHeight + rightHeight, max(leftDiameter, rightDiameter));

                mp[top] = {height, diameter};
            }
        }
        return mp[root].second;
    }
};
