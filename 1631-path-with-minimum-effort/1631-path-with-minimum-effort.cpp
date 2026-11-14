class Solution {
public:
    bool valid(int i, int j, int n, int m){
        if(i < 0 || i >= n || j<0  || j >= m) return false;
        return true;
    }
    int x[4] = {1, -1, 0, 0};
    int y[4] = {0, 0, 1, -1};
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>>res(n, vector<int>(m, INT_MAX));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        res[0][0] = 0;
        pq.push({0, {0, 0}});
        while(!pq.empty()){
            pair<int, pair<int, int>> p = pq.top();
            pq.pop();
            int dist = p.first;
            int row = p.second.first;
            int col = p.second.second;
            if(dist > res[row][col]) continue;
            for(int i = 0; i<4; i++){
                int r = row + x[i];
                int c = col + y[i];
                if(!valid(r, c, n, m)) continue;
                int diff = abs(heights[row][col] - heights[r][c]);
                int newwt = max(diff, dist);
                if(newwt < res[r][c]){
                    res[r][c] = newwt;
                   pq.push({newwt, {r, c}});
                }
            }
        }
        return res[n-1][m-1];
    }
};