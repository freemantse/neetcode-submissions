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
    int countGoodNodes (TreeNode* node, int max_val) {
        if (!node) return 0;

        int val = node->val >= max_val ? 1 : 0;
        max_val = max(max_val, node->val);
        
        return val += countGoodNodes(node->left, max_val) + countGoodNodes(node->right, max_val);
    }
public:
    int goodNodes(TreeNode* root) {
        return countGoodNodes(root, INT_MIN);
    }
};
