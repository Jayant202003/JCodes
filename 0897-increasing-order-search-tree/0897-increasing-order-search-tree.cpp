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
    TreeNode* increasingBST(TreeNode* root) {
         vector<int> values;
        inorder(root, values);

        // Dummy head to simplify building the new right-skewed tree
        TreeNode* dummy = new TreeNode(0);
        TreeNode* curr = dummy;

        for (int val : values) {
            curr->right = new TreeNode(val);
            curr = curr->right;
        }

        return dummy->right;
    }

private:
    void inorder(TreeNode* node, vector<int>& values) {
        if (!node) return;
        inorder(node->left, values);
        values.push_back(node->val);
        inorder(node->right, values);
    }
};