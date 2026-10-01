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
int helper(TreeNode* root) {
        if (root == NULL)
            return 0;

        int left = helper(root->left);
        int right = helper(root->right);
        if (root->left == NULL && root->right == NULL)
            return 1;
        if (root->left == NULL)
            return 1 + right;
        if (root->right == NULL)
            return 1 + left;
        return 1 + max(left, right);
    }
    int maxDepth(TreeNode* root) {
return helper(root);
    }
};