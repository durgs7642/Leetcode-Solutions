class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int miniending = nums[0];
        int maxending = nums[0];
        int res = nums[0];
        for(int i =1;i<n; i++){
            int v1 = nums[i];
            int v2 = nums[i]*miniending ;
            int v3 = nums[i]*maxending ;
            miniending = min(v1, min(v2, v3));
            maxending = max(v1, max(v2, v3));
            res = max(res, max(miniending, maxending));
        }
        return res;
    }
};