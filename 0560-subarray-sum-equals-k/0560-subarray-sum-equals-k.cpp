class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0, res = 0;
        unordered_map<int, int>map;
        map[0] = 1;
        for(int i=0;i<n;i++){
            sum += nums[i];
            int freq = map[sum - k];
            map[sum]++;
            res += freq;
        }
        return res;
    }
};