class Solution {
public:
    string removeDuplicates(string s) {
        int n = s.size();
        stack<char>st;
        string res = "";
        if(s.empty()) return "";
        for(int i =0;i<n;i++){
            if(st.empty()) st.push(s[i]);
            else if(s[i] == st.top()){
                st.pop();
            }
            else st.push(s[i]);
        }

        while(!st.empty()){
            res = res + st.top();
            st.pop();
        }

        reverse(res.begin(), res.end());
        return res;
    }
};