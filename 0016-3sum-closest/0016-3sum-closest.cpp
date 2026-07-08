class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int max_diff = INT_MAX;
        int res_sum = 0;
        sort(nums.begin(), nums.end());
        for(int i=0;i<n-2;i++){
            int left = i+1, right = n-1;
            while(left < right){
                int sum = nums[i] + nums[left] + nums[right];
                int diff = abs(sum - target);
                if(diff < max_diff){
                    max_diff = diff;
                    res_sum = sum;
                }
                if(sum == target){
                    left++;
                    right--;
                }
                else if(sum < target) left++;
                else right--;
            }
        }
        return res_sum;
    }
};