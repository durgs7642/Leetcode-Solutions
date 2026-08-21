class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> need, have;
        for(auto x : ransomNote) need[x]++;
        for(auto x : magazine) have[x]++;
        for(auto x : need){
            char ch = x.first;
            int val = x.second;
            int Have = have[ch];
            if(Have < val) return false;
        }
        return true;
    }
};