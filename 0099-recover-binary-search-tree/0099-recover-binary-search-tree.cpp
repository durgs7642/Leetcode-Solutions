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
    TreeNode* prev = NULL;
    TreeNode* first1 = NULL;
    TreeNode* second1 = NULL;
    TreeNode* first2 = NULL;
    TreeNode* second2 = NULL;
    int wrongPlace = 0;
    void helper(TreeNode* root){
        if(root== NULL) return ;
        helper(root->left);
        if(prev == NULL)prev = root;
        else {
            if(root->val < prev->val){
               if(wrongPlace == 0){
                first1 = prev;
                second1 = root;
                wrongPlace++;
               }
                else {
                    first2 = prev;
                    second2 = root;
                    wrongPlace++;
                }
            } 
            prev = root;
        }   
        helper(root->right);
    }
    void recoverTree(TreeNode* root) {
        helper(root);
        if(wrongPlace == 1) swap(first1->val, second1->val);
        else swap(first1->val, second2->val);
    }
};