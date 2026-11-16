class Solution {
public:
    long long maxDifference(vector<int>& nums) {
        int n = nums.size();
        vector<long long>dp(n+2, 0);
        for(int i= n-1; i>= 0; i--){
            long long sum1 = nums[i];
            long long opt1;
            if(sum1 % 3 == 0){
                opt1 = sum1 - dp[i + 1];
            }
            else opt1 = sum1 + dp[i+1];

            long long opt2 = LLONG_MIN;
            if(i + 1 < n){
                long long sum2 = nums[i] + nums[i + 1];
                if(sum2 % 3 == 0){
                    opt2 = sum2 - dp[i + 2];
                }
                else opt2 = sum2 + dp[i+2];
            }
          dp[i] = max(opt1, opt2);
        }
        return dp[0];
    }
};