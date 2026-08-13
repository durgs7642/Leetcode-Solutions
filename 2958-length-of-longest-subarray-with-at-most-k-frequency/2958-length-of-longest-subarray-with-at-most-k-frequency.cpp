class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int>map;
        int low = 0, len = 0;
        for(int high = 0; high<n;high++){
            map[nums[high]]++;

            while(map[nums[high]] > k){
                map[nums[low]]--;
                low++;
            }
            len = max(len, high - low + 1);
        }
        return len;
    }
};