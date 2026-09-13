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
        unordered_map<char, int>freq;
        unordered_map<char, int>free;
        for(auto x : tasks){
            freq[x]++;
            free[x] = 1;
        }
        priority_queue<pair<int, char>>pq;
        for(auto x: freq){
            pq.push({x.second, x.first});
        }
        int seat = 1;
        while(!pq.empty()){
            vector<pair<int, char>>pulled;
            while(!pq.empty()){
                pair<int, char> p = pq.top();
                pq.pop();
                if(free[p.second] <= seat){
                    if(p.first > 1)
                        pq.push({p.first - 1, p.second});
                    free[p.second] = seat+ n + 1;
                    break;
                }
                else {
                    pulled.push_back(p);
                }
            }
            for(int i =0;i<pulled.size();i++) pq.push(pulled[i]);
            seat++;
        }
        return seat - 1;
    }
};