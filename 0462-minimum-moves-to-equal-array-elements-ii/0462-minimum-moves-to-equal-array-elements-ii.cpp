class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int mid = (0 + n-1)/2;
        int moves = 0;
        for(auto x : nums){
            moves += abs(nums[mid] - x);
        }
        return moves ;
    }
};