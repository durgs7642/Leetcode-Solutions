class Solution {
public:
    struct cmp{
        bool operator()(pair<int, string>&a, pair<int, string>&b){
            if(a.first != b.first)
            return a.first > b.first;
            return a.second < b.second;
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        int n = words.size();
        unordered_map<string, int> map;
        for(auto x : words) map[x]++;
        priority_queue< pair<int, string>, vector<pair<int, string>>, cmp>pq;

        for(auto x : map){
            int fre = x.second;
            string word = x.first;
            if(pq.size() < k) pq.push({fre, word});
            else {
                if(fre < pq.top().first ||  (fre == pq.top().first && word > pq.top().second)) continue;
                pq.pop();
                pq.push({fre, word});
            }
        }

        vector< string> res;
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};