class Solution {
public:
    typedef pair<double, vector<int>> P ;
    struct cmp {
        bool operator()(P &a, P &b){
            if(a.first != b.first) return a.first < b.first;
            return a.second < b.second;
        }
    };

    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        priority_queue< P , vector<P>, cmp> pq;

        for(int i =0;i<n;i++){
            int dist = ( 1LL*points[i][0]* points[i][0] + 1LL*points[i][1]* points[i][1] );
            if(pq.size() < k) pq.push({dist, points[i]});
            else {
                if(dist >= pq.top().first) continue;
                pq.pop();
                pq.push({dist, points[i]});
            }
        }

        vector<vector<int>> res;
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        } 

        return res;
    }
};