
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int size = nums.size();
        vector<int> neg, pos;
        for(int i=0;i<size;i++){
            if(nums[i] < 0){
                neg.push_back(nums[i]);
            }
            else {
                pos.push_back(nums[i]);
            }
        }
        if(neg.size() == 0){
            for(int i = 0;i<size;i++){
                pos[i] = pos[i]*pos[i];
            }
            return pos;
        }
        if(pos.size() == 0){
              for(int i = 0;i<size;i++){
              neg[i] = neg[i] * neg[i];
            }
            reverse(neg.begin(), neg.end());
            return neg;
        }

        int i =0, j = 0, k = 0, n = neg.size(), m = pos.size();
        vector<int> res(m+n);
        for(int i=0;i<n;i++){
            neg[i] = neg[i] * neg[i];
        }
        reverse(neg.begin(), neg.end());

        for(int i = 0;i<m;i++){
            pos[i] = pos[i] * pos[i];
           
        }

        while( i< n && j < m){
            if(neg[i] <= pos[j]){
                res[k++] = neg[i++];
            }
            else {
                res[k++] = pos[j++];
            }
        }

        while( i<n){
            res[k++] = neg[i++];
        }
        
        while( j<m){
            res[k++] = pos[j++];
        }

        return res;
    }

};