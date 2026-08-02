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

    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int res;
        int sum = 0;
        for(int i =0;i<n;i++){
            sum += nums[i];
        }
        int maxsum = maxSubarray(nums);
        int minsum = minSubarray(nums);
        cout << maxsum << " "<< minsum;
        if(maxsum < 0) return maxsum;
        res = max(maxsum, sum - minsum);
        return res;
    }
};