class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        
        int size = INT_MAX;
        int low =0, high = 0;
        int sum = 0;
        while(high < n){
           
                sum = sum + nums[high];
              
            while (sum >= target){
                size = min(size, high - low + 1);
                sum = sum - nums[low];
                low++;
            }
              high++; 
    }

        return size == INT_MAX ? 0 : size;
    }
};