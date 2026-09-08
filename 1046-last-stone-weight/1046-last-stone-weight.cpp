class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n = stones.size();
        // if(n == 1) return stones[]
        priority_queue<int>pq;
        for(auto x : stones) pq.push(x);
        int res = -1;
        while(!pq.empty()){
            if(pq.size() > 1){
            int first = pq.top();
            pq.pop();
            int second = pq.top();
            pq.pop();
            int diff = first - second ;
            pq.push(diff);
            }
            else {
                res = pq.top();
                pq.pop();
            }
        }
        return res ;
    }
};