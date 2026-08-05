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
    bool isSymmetric(TreeNode* root) {
         if (!root) return true;
        return isMirror(root->left, root->right);
    }

private:
    bool isMirror(TreeNode* left, TreeNode* right) {
        // Both null -> symmetric at this branch
        if (!left && !right) return true;

        // Only one is null -> not symmetric
        if (!left || !right) return false;

        // Values must match, AND:
        // left's left must mirror right's right
        // left's right must mirror right's left
        return (left->val == right->val)
            && isMirror(left->left, right->right)
            && isMirror(left->right, right->left);
    }
};