class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int low = 0, high = 0,len =INT_MIN;
        unordered_map<int, int>map;
        while(high < n){
           map[fruits[high]]++;
           while(map.size() > 2){
            map[fruits[low]]--;
            if(map[fruits[low]] == 0){
                map.erase(fruits[low]);
            }
            low++;
           }
           len = max(len, high - low + 1);
           high++;
        }
        return len;
    }
};