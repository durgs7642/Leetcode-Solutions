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
     stack<TreeNode*>asc ;
    TreeNode* getSmall(){
        if(asc.empty()) return NULL;
        TreeNode* small = asc.top();
        asc.pop();
        TreeNode* rightchild = small->right ;
        while(rightchild){
            asc.push(rightchild);
            rightchild = rightchild->left;
        }
        return small;
    }
    int kthSmallest(TreeNode* root, int k) {
        if(root == NULL) return -1;
        TreeNode* t = root ;
        while(t){
            asc.push(t);
            t= t->left ;
        }
        int count = 0;
        int ans ;
        while(!asc.empty()){
            TreeNode* temp = getSmall();
            count++;
            if(count == k){
                ans = temp->val;
            }
        }
        return ans;
    }
};