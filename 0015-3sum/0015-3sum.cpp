class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>res;
        sort(nums.begin(), nums.end());
        for(int i=0;i<n-2;i++){
            if(i>0 && nums[i] == nums[i-1]) continue;
            int sum = -1 * nums[i];
            int left = i+1, right = n-1;
            while( left < right ){
                if(nums[left] + nums[right] == sum){
                    res.push_back({nums[i], nums[left], nums[right]});     
                    left++;
                    right--;
                    while(left < n && nums[left] == nums[left-1]) left++;
                    while(right >=0 && nums[right] == nums[right+1]) right--;
                }
                else if(nums[left] + nums[right] < sum) left++;
                else right--;
            }
        }
        return res;
    }
};