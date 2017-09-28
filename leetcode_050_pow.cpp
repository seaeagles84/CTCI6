/* 
 * Think twice if the problem seems to be too straightforward.
 * Just repeating multiplication n times will fail due to time limit.
 * Also, watch out for the overflow in n, when doing n = -n. 
 */
class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0)
            return 1;
        
        // Does not work when n = -2147483648 (- 2^31), so when flipped, overflow and back to itself.
        /*
        if (n < 0) {
            x = 1/x;
            n = -n;
        }
        
        return n%2 == 0 ? myPow(x*x, n/2) : x*myPow(x*x, n/2);
        */
        
        double half = myPow(x, n/2);
        double half_square = half*half;
        
        if (n%2 != 0){
            if (n < 0) 
                return 1/x * half_square;
            else 
                return x * half_square;
        }
        
        return half_square;
    }
};
