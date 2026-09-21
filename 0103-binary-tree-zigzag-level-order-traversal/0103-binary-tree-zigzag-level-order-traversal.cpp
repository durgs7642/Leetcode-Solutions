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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
         vector<vector<int>>res; 
         int flag = 1;
        if(root == NULL) return res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int>level(size);
            int first = 0, last = size - 1;
            while(size--){
                TreeNode* node = q.front();
                q.pop();
                if(flag){
                    level[first] = node->val;
                    first++;
                }
                else {
                    level[last] = node->val;
                    last--;
                }
                if(node->left != NULL) q.push(node->left);
                if(node->right != NULL) q.push(node->right);  
            }
            flag = 1- flag;
            res.push_back(level);
        }
        return res;
    }
};