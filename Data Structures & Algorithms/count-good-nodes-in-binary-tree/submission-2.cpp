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
    int goodNodes(TreeNode* root) {
        int result = 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, INT_MIN});

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto [node, val_max] = q.front();
                q.pop();

                if (node->val >= val_max) result++;
                val_max = max(val_max, node->val);

                if (node->left) q.push({node->left, val_max});
                if (node->right) q.push({node->right, val_max});
            }
        }
        return result;
    }
};
