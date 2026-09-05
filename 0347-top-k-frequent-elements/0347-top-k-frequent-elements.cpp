class Solution {
public:
    struct cmp {
        bool operator()(pair<int, int>&a , pair<int, int>&b ){
            if(a.first != b.first){
                return a.first > b.first;
            }
            return a.second > b.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp>pq;
        for(auto x : mp){
            int val = x.first;
            int fre = x.second;
            if(pq.size() < k) pq.push({fre, val});
            else {
                if(fre < pq.top().first) continue;
                pq.pop();
                pq.push({fre, val});
            }
        }
        vector<int>res;
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};