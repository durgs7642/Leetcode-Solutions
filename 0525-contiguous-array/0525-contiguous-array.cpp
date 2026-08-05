class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        int res = 0, zeros = 0, ones = 0;
        unordered_map<int, int>map;

        for(int i =0;i<n;i++){
            if(nums[i] == 0) zeros++;
            else ones++;
            int diff = zeros - ones;
            if(diff == 0){
                res = max(res, i+1);
                continue;
            }
            if(map.find(diff) == map.end()){
                map[diff] = i;
            }
            else {
                res = max(res, i-map[diff]);
            }
        }
        return res;
    }
};