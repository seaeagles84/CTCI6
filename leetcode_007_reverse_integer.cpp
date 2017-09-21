class Solution {
public:
    int reverse(int x) {        
        if (x == 0)
            return 0;
        
        // to remove trailing zeros...
        while (x%10 == 0) {
            x = x/10;
        }
        
        int newoutput = 0;
        int output = 0;
        while (x != 0) {
            newoutput = output*10 + x%10;
            if ((newoutput - x%10)/10 != output)
                return 0;
            output = newoutput;
            x = x/10;
            
        }
        
        return output;        
    }
};
