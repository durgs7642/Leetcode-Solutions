class Solution {
public:
bool helper(vector<int>&ptemp, vector<int>&stemp){
    for(int i = 0;i<256;i++){
        if(ptemp[i] > stemp[i]){
            return false;
        }
    }
    return true;
}

    vector<int> findAnagrams(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<int>stemp(256, 0), ptemp(256, 0);
        vector<int>temp;
        for(int i=0; i<m;i++){
            ptemp[p[i]]++;
            stemp[s[i]]++;
        }
        int low = 0,high = m-1 ;
        while(high < n){
            if(helper(ptemp, stemp)){
                temp.push_back(low);
            }
            stemp[s[low]]--;
            low++;
            high++;
            if(high > n) break;
            stemp[s[high]]++;
        }
        
        return temp;
    }
};