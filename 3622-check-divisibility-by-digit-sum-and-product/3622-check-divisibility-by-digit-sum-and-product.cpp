class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0, prod = 1, temp = n;
        while(temp > 0){
            int rem = temp % 10;
            sum = sum + rem;
            prod = prod*rem;
            temp = temp/ 10;
        }

        cout << sum << " " << prod ;

        if((n % (sum + prod) == 0)) return true;
        return false;
    }
};