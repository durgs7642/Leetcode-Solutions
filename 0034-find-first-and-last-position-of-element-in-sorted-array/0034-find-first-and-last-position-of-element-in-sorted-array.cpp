class Solution {
public:
    int first(vector<int>& nums, int target){
        int n = nums.size();
        int low = 0, high = n-1, res = -1;
        while(low <= high){
            int mid = (low + high)/2;
            if(nums[mid] < target) low = mid + 1;
            else if (nums[mid] > target) high = mid - 1;
            else {
                res = mid;
                high = mid - 1;
            }
        }
        return res;
    }

    int last(vector<int>& nums, int target){
        int n = nums.size();
        int low = 0, high = n-1, res = -1;
        while(low <= high){
            int mid = (low + high)/2;
            if(nums[mid] < target) low = mid + 1;
            else if (nums[mid] > target) high = mid - 1;
            else {
                res = mid;
                low = mid + 1;
            }
        }
        return res;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        return {first(nums, target), last(nums, target)};
    }
};