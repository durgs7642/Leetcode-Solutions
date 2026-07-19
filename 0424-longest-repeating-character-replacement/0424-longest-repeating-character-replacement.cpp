class Solution {
public:
    
    int maxC(vector<int> &temp){
        int n = temp.size();
        int max = temp[0];
        for(int i=1;i<n;i++){
            if(temp[i] > max){
                max = temp[i];
            }
        }
        return max;
    }
    

    int characterReplacement(string s, int k) {
        int n = s.size();
        int low = 0, res = INT_MIN;
        vector<int>temp(255, 0);
        for(int high = 0;high <n; high++){
            temp[s[high]]++;
           int len = high - low + 1;
           int maxCount = maxC(temp);
           int diff = len - maxCount ;
           while(diff > k){
            temp[s[low]]--;
            low++;
            len  = high - low +1;
            maxCount = maxC(temp);
            diff = len - maxCount;
           }
           res = max(res, high - low + 1);
        }
        return res;
    }
};