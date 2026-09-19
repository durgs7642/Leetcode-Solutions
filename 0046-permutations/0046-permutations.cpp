class Solution {
public:
    void helper(vector<int>&nums, int n, vector<int>&temp, vector<vector<int>>&res, vector<bool>& used){
        if(temp.size() == n){
            res.push_back(temp);
            return ;
        }
        for(int i = 0; i< n;i++){
            if(used[i]) continue;
            used[i] = true;
            temp.push_back(nums[i]);
            helper(nums, n, temp, res, used);
            temp.pop_back();
            used[i] = false;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        vector<int>temp;
        vector<bool> used(n, false);
        helper(nums, n, temp, res, used);
        return res;
    }
};