class Solution {
public:
    int longestPalindrome(string s) {
        int n = s.size();
        unordered_map<char, int>mp;
        bool odd = false;
        int res=0;
        for(auto x : s){
            mp[x]++;
        }

        for(auto x : mp){
            if(x.second % 2 == 0) res += x.second;
            else odd = true;
        }
        if(odd == false ) return res;
        for(auto  x : mp){
            if(x.second % 2 == 1)res += x.second -1 ;
        }
        return res + 1 ;
    }
};