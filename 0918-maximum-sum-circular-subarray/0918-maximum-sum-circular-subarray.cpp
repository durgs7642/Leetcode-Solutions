class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int res = nums[0];
        int maxbestending = nums[0];
        int minbestending = nums[0];
        int maxsum = nums[0];
        int minsum = nums[0];
        int sum = nums[0];
        for(int i =1;i<n;i++){
           sum += nums[i];
           maxbestending = max(nums[i], maxbestending + nums[i]);
           maxsum = max(maxsum, maxbestending);
           minbestending = min(nums[i], minbestending + nums[i]);
           minsum = min(minsum, minbestending);
        }
        if(maxsum < 0) return maxsum;
        return  max(maxsum, sum - minsum);
    }
};