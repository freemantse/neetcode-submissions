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
    int count = 0;
    void countGoodNodes (TreeNode* node, int base) {
        if (!node) return;
        if (node->val >= base) count++;
        base = max(base, node->val);
        if (node->left) countGoodNodes(node->left, base);
        if (node->right) countGoodNodes(node->right, base);
    }
public:
    int goodNodes(TreeNode* root) {
        countGoodNodes(root, INT_MIN);
        return count;
    }
};
