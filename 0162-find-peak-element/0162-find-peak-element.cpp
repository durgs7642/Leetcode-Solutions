class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        int n = arr.size();
        if(n == 1) return 0;
        int low = 0, high = n-1, res= -1;

        while(low <= high){
            int mid = (low + high)/ 2;
            if(mid + 1 < n && arr[mid] < arr[mid+1]) low = mid + 1;
            else {
                res = mid;
                high = mid - 1;
            }
        }
        return res;
    }
};