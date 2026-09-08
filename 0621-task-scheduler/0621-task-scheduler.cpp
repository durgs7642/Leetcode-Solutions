class Solution {
public:
    // struct cmp {
    //     bool operator()(pair<int, string>&a, pair<int, string>&b){
    //         if(a.first != b.fisrt) return a.first < b.first;
    //         return a.second < b.second;
    //     }
    // }
    int leastInterval(vector<char>& tasks, int n) {
        int m = tasks.size();
        unordered_map<char, int>mp;
        for(auto x : tasks) mp[x]++;

        // priority_queue< pair<int, string>, vector<pair<int, string>, cmp>pq;
        priority_queue<int>pq;
        for(auto x: mp){
            pq.push({x.second});
        }
        int time = 0;
        while(!pq.empty()){
            vector<int>temp;
            for(int i = 1;i<= n+1;i++){
                if(!pq.empty()){
                    int fre = pq.top();
                    pq.pop();
                    fre--;
                    temp.push_back(fre);
                }
            }
            for(auto x: temp){
                if(x > 0)pq.push(x);
            }
            if(pq.empty()) time += temp.size();
            else time += n+1;
        }
        return time ;
    }
};