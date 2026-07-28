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
    int findHeight(TreeNode* node) {
        if (!node) return 0;

        int left = findHeight(node->left);
        if (left == -1) return -1;

        int right = findHeight(node->right);
        if (right == -1) return -1;

        if (abs(left - right) > 1) 
            return -1;
        
        return 1 + max(left, right);
    }
public:
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        return findHeight(root) != -1;

    }
};
