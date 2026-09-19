class Solution {
public:
   

    void helper(string &digits, int n, int idx, string &diary, vector<string>&res, unordered_map<char, string>&mp){
        if(idx == n){
            res.push_back(diary);
            return ;
        }

        string choice = mp[digits[idx]];
        for(int i= 0;i<choice.size(); i++){
            diary.push_back(choice[i]);
            helper(digits, n, idx + 1, diary, res, mp);
            diary.pop_back();
        }
        return ;
    }
    vector<string> letterCombinations(string digits) {
        int n = digits.size();
        string diary = "";
        vector<string> res;
        unordered_map<char, string>mp;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";
        helper(digits, n , 0, diary, res, mp);
        return res;
    }
};