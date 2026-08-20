class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int>map1, map2;
        string target = "balloon";
        int ans = INT_MAX;
        for(auto c:text) map1[c]++;
        for(auto c:target) map2[c]++;

        for(auto it:map2){
            char ch = it.first;
            int x = it.second;
            if(map1.find(ch) == map1.end() || map2[ch] < x ) return 0;
            else ans = min(ans, map1[ch] / x);
        }
        return ans;
    }
};