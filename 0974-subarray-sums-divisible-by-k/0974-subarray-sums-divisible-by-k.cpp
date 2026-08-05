class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        int res = 0, sum = 0;
        unordered_map<int, int>map;
        map[0] = 1;
        for(int i=0;i<n;i++){
            sum += nums[i];
            int rem = sum % k;
            if(rem < 0) rem += k;
            res += map[rem];
            map[rem]++;
        }
        return res;
    }
};