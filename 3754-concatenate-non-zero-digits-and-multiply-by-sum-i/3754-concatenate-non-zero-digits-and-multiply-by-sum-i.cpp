class Solution {
public:
    long long sumAndMultiply(int n) {
        long long temp = n, rem = 0, sum = 0, x =0, place = 1;

        while(temp > 0){
            rem = temp%10;
            if(rem != 0){
            x = rem*place + x; 
            sum += rem;
            place *= 10;
            }
            temp = temp / 10;
        }
        return x*sum;
    }
};