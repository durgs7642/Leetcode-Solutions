class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int j = 0;
        vector<int> res(n, 0);
        unordered_map<int ,int>mp;
        for(int i = 0;i<n;i++){
            mp[nums[i]]++;
            if(mp[nums[i]] <= 2){
                res[j] = nums[i];
                j++;
            }
        }
        nums = res;
        return j;
    }
};