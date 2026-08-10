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
    void recoverTree(TreeNode* root) {
        TreeNode* first = nullptr;
        TreeNode* second = nullptr;
        TreeNode* prev = nullptr;

        inorder(root, first, second, prev);

        // Swap the values of the two misplaced nodes
        if (first && second) {
            swap(first->val, second->val);
        }
    }

private:
    void inorder(TreeNode* node, TreeNode*& first, TreeNode*& second, TreeNode*& prev) {
        if (!node) return;

        inorder(node->left, first, second, prev);

        // In a valid BST, inorder traversal should be strictly increasing.
        // If we find a violation (prev->val > node->val), a swap occurred here.
        if (prev && prev->val > node->val) {
            if (!first) {
                first = prev;   // first violation: mark the earlier (larger) node
            }
            second = node;      // always update second to the current (smaller) node
        }

        prev = node;

        inorder(node->right, first, second, prev);
    }
};