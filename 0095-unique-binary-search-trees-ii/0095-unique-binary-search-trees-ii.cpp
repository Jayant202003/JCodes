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
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return build(1, n);
    }

private:
    vector<TreeNode*> build(int start, int end) {
        vector<TreeNode*> result;

        // Base case: empty range -> represents a "null" subtree
        if (start > end) {
            result.push_back(nullptr);
            return result;
        }

        // Try every value as the root
        for (int i = start; i <= end; i++) {
            // All possible left subtrees using values [start, i-1]
            vector<TreeNode*> leftSubtrees = build(start, i - 1);
            // All possible right subtrees using values [i+1, end]
            vector<TreeNode*> rightSubtrees = build(i + 1, end);

            // Combine every left option with every right option
            for (TreeNode* left : leftSubtrees) {
                for (TreeNode* right : rightSubtrees) {
                    TreeNode* root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    result.push_back(root);
                }
            }
        }

        return result;

    }
};