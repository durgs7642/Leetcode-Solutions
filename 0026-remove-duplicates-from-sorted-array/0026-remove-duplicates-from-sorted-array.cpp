class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int cnt = 1, i = 0, j = 1;

        while( j < n){
            if(nums[j] != nums[j-1]){
                i++;
                nums[i] = nums[j];
                cnt++;
            }
            j++;
        }
        return cnt;
    }
};