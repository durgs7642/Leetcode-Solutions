class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int src) {
        // int n = times.size();
        vector<vector<pair<int, int>>> adj(n);
        for(int i= 0;i<times.size();i++){
            int s = times[i][0];
            int t = times[i][1];
            int w = times[i][2];
            adj[s-1].push_back({t-1, w});
        }
        vector<int> dist(n, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        src--;
        dist[src] = 0;
        pq.push({0, src});

        while(!pq.empty()){
            pair<int, int> p = pq.top();
            pq.pop();
            int d = p.first;
            int node = p.second;
            if(d > dist[node]) continue;
            for(int j = 0; j< adj[node].size(); j++){
                int neigh = adj[node][j].first;
                int wt = adj[node][j].second;
                if(d + wt < dist[neigh]){
                    dist[neigh] = d + wt;
                    pq.push({d + wt, neigh});
                }
            }
        }
        int maxi = *max_element(dist.begin(), dist.end());
        return maxi == INT_MAX ? -1 : maxi;
    }
};