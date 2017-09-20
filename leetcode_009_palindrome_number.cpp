class Solution {
public:
    bool isPalindrome(int x) {
        // Saw the solution. Just for practicing.
        if(x < 0)
            return false;

        int div = 1;
        while(x/10 >= div) { // MUST BE LIKE THIS. If x >= 10*div, this can go beyond the range of int, and overflow... 
            //cout << "x, div: " << x << " " << div << endl;
            div *= 10;
        }

        
        
        while(x > 0) {
            if(x%10 != x/div)
                return false;
            x = (x%div)/10;
            div /= 100;
        }      
        return true;
    }
};
