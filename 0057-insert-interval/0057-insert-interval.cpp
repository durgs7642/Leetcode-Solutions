class Solution {
public:
      
      vector<vector<int>> merge(vector<vector<int>>&res ){
        int n = res.size();
        vector<vector<int>>ans;
        int start1 = res[0][0], end1 = res[0][1];
        for(int i = 1;i<n;i++){
            int start2 = res[i][0];
            int end2 = res[i][1];
            if(end1 >= start2){
                start1 = start1;
                end1 = max(end1, end2);
                continue;
            }
            ans.push_back({start1, end1});
            start1 = start2;
            end1 = end2;
        }
        ans.push_back({start1, end1});

        return ans;
      }
    
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        vector<vector<int>>res;
        if(n == 0){
            res.push_back(newInterval);
        }
        bool isinserted = false;
        for(int i=0;i<n;i++){
            int start = intervals[i][0];
            if(isinserted == false && start >= newInterval[0]){
                res.push_back(newInterval);
                isinserted = true;
            }
            res.push_back(intervals[i]);
        }
        if(!isinserted) res.push_back(newInterval);
        return merge(res);
    }
};