class Solution {
public:
   
bool helper(vector<int>&s1temp, vector<int>&s2temp){
    for(int i = 0;i<256;i++){
        if(s1temp[i] < s2temp[i]){
            return false;
        }
    }
    return true;
}
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        if( n > m) return false;
        vector<int>s2temp(256, 0);
        vector<int>s1temp(256, 0);
        int low = 0, high = n-1;
        for(int i= low;i<=high; i++){
            s2temp[s2[i]]++;
            s1temp[s1[i]]++;
        }
        while(high < m){
            if(helper(s1temp, s2temp)){
                return true;
            }
            s2temp[s2[low]]--;
            low++;
            high++;
            if(high > m) break;
            s2temp[s2[high]]++;
        }
        return false;
    }
};