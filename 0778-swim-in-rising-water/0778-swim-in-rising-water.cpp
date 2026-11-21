class Solution {
public:
    bool valid(int i, int j, int n, int m){
        if( i< 0 || i >= n || j < 0 || j>= m) return false;
        return true;
    }
    bool bfs(vector<vector<int>>& grid, int n, int m, int money){
        int i, j ;
        int x[4] = {1, -1, 0, 0};
        int y[4] = {0, 0, 1, -1};
        queue<pair<int, int>> pq;
        vector<vector<int>>vis(n, vector<int>(m , 0));
        pq.push({0, 0});
        vis[0][0] = 1;
        while(!pq.empty()){
            pair<int, int> p = pq.front();
            pq.pop();
            int row = p.first;
            int col = p.second;
            if(row == n-1 && col == m-1) return true;
            for(int i = 0;i< 4; i++){
                int r = row + x[i];
                int c = col + y[i];
                if(valid(r, c, n, m) && vis[r][c] != 1 && money >= grid[r][c]){
                    pq.push({r, c});
                    vis[r][c] = 1;
                } 
            }
        }
        return false;
    }
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size(); 
        int low = grid[0][0];
        int high = grid[0][0];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                high = max(high, grid[i][j]);
            }
        }
        int res = 0;
        while(low <= high){
            int guess = (low + high)/2;
            if(bfs(grid, n, m, guess)){
                res = guess;
                high = guess - 1;
            }
            else {
                low = guess +  1;
            }
        }
        return res;
    }
};