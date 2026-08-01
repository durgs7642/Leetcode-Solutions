class Solution {
public:
    int maxSubarray(vector<int>&nums){

        int n = nums.size();
        int res = nums[0];
        
        int bestending = nums[0];
         for(int i = 1;i<n;i++){
            int v1 = nums[i];
            int v2 = bestending + nums[i];
            bestending = max(v1,v2);
            res = max(res, bestending);
         }
         return res;
    }

    int minSubarray(vector<int>&nums){
        int n = nums.size();
        int res = nums[0];
        int bestending = nums[0];
        
         for(int i = 1;i<n;i++){
            int v1 = nums[i];
            int v2 = bestending + nums[i];
            bestending = min(v1, v2);
            res = min(res, bestending);
         }
         return res;
    }
    int maxAbsoluteSum(vector<int>& nums) {
        
           int maxi = maxSubarray(nums);
           int mini = minSubarray(nums);
           int res = max(abs(mini), abs(maxi));
        return res;
    }
};