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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;

        TreeNode* curr = root;
        TreeNode* prev = nullptr;

        while (curr && key != curr->val) {
            prev = curr;
            if (key < curr->val) {
                curr = curr->left;
            } else {
                curr = curr->right;
            } 
        }
        if (!curr) return root;

        if (!curr->left || !curr->right) {
            TreeNode* child = curr->left ? curr->left : curr->right;
            if (!prev) {
                delete curr;
                return child;
            }
            if (prev->left == curr) {
                prev->left = child;
            } else {
                prev->right = child;
            }
            delete curr;
        } else {
            TreeNode* delNode = curr;
            TreeNode* rightParent = nullptr;
            curr = curr->right; 

            while (curr->left) {
                rightParent = curr;
                curr = curr->left;
            }

            if (rightParent) {
                rightParent->left = curr->right;
                curr->right = delNode->right;
            }
            curr->left = delNode->left;

            if (!prev) {
                delete delNode;
                return curr;
            }

            if (prev->left == delNode) {
                prev->left = curr;
            } else {
                prev->right = curr;
            }
            delete delNode;
        }
        return root;
    }
};