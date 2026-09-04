class Solution {
public:
    int helper(int m, int n, int guess){
        int count = 0;
       
        for(int i = 1; i <= m; i++) {
            count += min(n, guess / i);
        }
        return count;
    }
    int findKthNumber(int m, int n, int k) {
        int low = 1;
        int high = m*n;
        int res = -1;
        while(low <= high){
            int guess = (low + high)/2;
            int ans = helper(m, n, guess);
            if(ans < k){
                low = guess + 1;
            }
            else {
                res = guess;
                high = guess - 1;
            }
        }
        return res;
    }
};