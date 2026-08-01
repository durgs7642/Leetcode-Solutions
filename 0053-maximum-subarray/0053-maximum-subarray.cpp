class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int bestending = nums[0];
        int maxi = nums[0];
        for(int i =1;i<n;i++){
            int v1 = nums[i];
            int v2 = bestending + nums[i];
            bestending = max(v1, v2);
            maxi = max(maxi, bestending);
        }
        return maxi;
    }
};