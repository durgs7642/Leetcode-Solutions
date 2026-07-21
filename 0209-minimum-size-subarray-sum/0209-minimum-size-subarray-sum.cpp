class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
       int n = nums.size();
       int low = 0, res= INT_MAX, len = 0, sum = 0;
       for(int high = 0;high<n;high++){
        sum += nums[high];
        while(sum >= target){
            res = min(res, high - low + 1);
            sum -= nums[low];
            low++;
        }
       }
       return res == INT_MAX ? 0 : res;
    }
};