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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        stack<pair<TreeNode*, TreeNode*>> stack;
        stack.push({p ,q});
        while (!stack.empty()) {
            auto [curr1, curr2] = stack.top();
            stack.pop();

            if (!curr1 && !curr2) continue;
            if (!curr1 || !curr2 || curr1->val != curr2->val) return false;

            stack.push({curr1->left, curr2->left});
            stack.push({curr1->right, curr2->right});
        }
        return true;
    }
};
