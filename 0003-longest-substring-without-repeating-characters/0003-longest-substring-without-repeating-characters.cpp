class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size(), low = 0,high = 0, len = INT_MIN;
        if(n == 0) return 0;
        unordered_map<char, int>map;
        while(high < n){
            map[s[high]] = high;
            len = max(len, high - low + 1);
            high++;
            while(map.find(s[high]) != map.end()){
                map.erase(s[low]);
                low++;
            }
        }
        return len;
    }
};