class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = 0, res = INT_MAX, sum = 0;
        while(high < n){
            sum = sum + nums[high];
            while(sum >= target){
                res = min(res , high - low + 1);
                sum = sum - nums[low];
                low++;
            }
        
            high++;
        }
        return res == INT_MAX ? 0: res;
    }
};