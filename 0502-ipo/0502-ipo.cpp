class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int, int>> project;
        int i;
        for(i = 0;i<n;i++){
            project.push_back({capital[i], profits[i]});
        }
        sort(project.begin(), project.end());
        priority_queue<int>pq;
        int idx = 0;
        while(k--){
            while(idx < n){
            if(project[idx].first > w) break;
            pq.push(project[idx].second);
            idx++;
            }
            if(pq.empty()) return w;
            w = w + pq.top();
            pq.pop();
        }
        return w ;
    }
};