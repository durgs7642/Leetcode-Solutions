class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = 0, sum = 0, ind = -1;
        for(auto x: nums){
            sum += x;
        }

        for(int i =0;i<n;i++){
           if(i > 0)  left += nums[i-1];
             right = sum - left - nums[i];
             if(left == right ) {
                ind = i;
                break;
             }
        }
        return ind;
    }
};