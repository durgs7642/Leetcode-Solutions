class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for(int i = 0;i<n-3;i++){
            if(i>0 && nums[i] == nums[i-1]) continue;
            for(int j = i+1;j<n-2;j++){
                 if(j>i+1 && nums[j] == nums[j-1]) continue;
                long long sum = -1 * (nums[i]+ nums[j]);
                int left = j+1, right = n-1;
                while(left < right){
                    long long temp_sum = nums[left] + nums[right];
                    if(temp_sum  == target + sum){
                        res.push_back({nums[i],nums[j],nums[left],nums[right]});
                        left++;
                        right--;
                        while(left < n && nums[left] == nums[left-1]) left++;
                        while(right >= 0 && nums[right] == nums[right+1]) right--;
                    }
                    else if (temp_sum < target+ sum) left++;
                    else right--;
                }
            }
        }
        return res;
    }
};