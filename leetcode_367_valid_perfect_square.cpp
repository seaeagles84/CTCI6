class Solution {
public:
    bool isPSimpl(int n, int start, int end) {
        
        if (start > end) {
            return false;
        }
        
        //how to deal with overflow here? : use / instead of *. Or use long instead of int for middle. 
        int middle = (start+end)/2;
        if (n%middle == 0 && middle == n/middle)
            return true;
        if (middle > n/middle)
            return isPSimpl(n, start, middle - 1);
        
        return isPSimpl(n, middle + 1, end);
    }
    
    bool isPerfectSquare(int num) {
        return isPSimpl(num, 1, num);
    }
};

/* People also mention Newton Method, which I was not aware of */

/*
public boolean isPerfectSquare(int num) {
        long x = num;
        while (x * x > num) {
            x = (x + num / x) >> 1;
        }
        return x * x == num;
    }
*/
