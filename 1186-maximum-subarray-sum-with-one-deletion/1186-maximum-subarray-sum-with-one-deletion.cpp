class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        int oneDelete = INT_MIN;
        int noDelete = arr[0];
        int res = arr[0];

        for(int i=1;i<n;i++){
            int prevOneDelete = oneDelete ;
            int prevNoDelete = noDelete;
            noDelete = max(arr[i], noDelete + arr[i]);
            int v2 ;
            if(prevOneDelete == INT_MIN) v2 = arr[i];
            else v2 = prevOneDelete + arr[i] ;
            oneDelete = max(v2 , prevNoDelete);

            res =max(res, max(noDelete, oneDelete));
        }
        return res;
    }
};