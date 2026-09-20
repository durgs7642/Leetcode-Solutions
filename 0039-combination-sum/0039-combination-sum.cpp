class Solution {
public:
    void helper(vector<int>&candidates, int n, int idx, int sum, vector<int>&dairy, vector<vector<int>> &res, int target){
        if(idx == n){
            if(sum == target)
            res.push_back(dairy);
            return ;
        }
        helper(candidates, n, idx + 1, sum, dairy, res, target);
        if(sum + candidates[idx] <= target){
            dairy.push_back(candidates[idx]);
            sum += candidates[idx];
            helper(candidates, n, idx, sum, dairy, res, target);
            dairy.pop_back();
            sum -= candidates[idx];
        }
        return ;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        int sum = 0;
        vector<vector<int>> res;
        vector<int> dairy ;
        helper(candidates, n, 0, sum, dairy, res, target);
        return res;
    }
};