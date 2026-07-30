class Solution {
public:
    int sumOfSquareOfDigit(int n){
        int sum = 0;
        while(n > 0){
            int d = n%10;
            sum = sum + d*d;
            n = n/10;
        }
        return sum;
    }
    bool isHappy(int n) {
       int slow = n;
       int fast = n;
       while(fast != 1){
        slow = sumOfSquareOfDigit(slow);
        fast = sumOfSquareOfDigit(fast);
        fast = sumOfSquareOfDigit(fast);
        if(slow == fast && slow !=1 ) return false;
       }
       return true;
    }
};