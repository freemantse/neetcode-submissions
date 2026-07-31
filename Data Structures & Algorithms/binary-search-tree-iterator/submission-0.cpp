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
class BSTIterator {
private:
    stack<TreeNode*> stack;
public:
    BSTIterator(TreeNode* root) {
        TreeNode* curr = root;
        while (curr) {
            stack.push(curr);
            curr = curr->left;
        }
    }
    
    int next() {
        TreeNode* top = stack.top();
        stack.pop();
        if (top->right) {
            TreeNode* curr = top->right;
            while (curr) {
                stack.push(curr);
                curr = curr->left;
            }
        }
        return top->val;
    }
    
    bool hasNext() {
        return !stack.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */