class Solution {
public:
    int mySqrt(int x) {
        if (x < 0)
            return -1;
        if (x == 0)
            return 0;
        
        /* 
        //This may help, but already the binary search approach gives you log(n),
        //so may not improve that much.
          
        int temp = x;
        int digits = 0;
        while (temp > 0) {
            digits++;
            temp = temp/10;
        }
        
        int half = (digits+1)/2;
        temp = 1;
        for (int i = 0; i < half; i++)
            temp = temp*10;        
        */
        //cout << "temp,x:" << temp << "," << x << endl;
        
        int min = 1, max = x;
        int middle;
        while (min <= max) {
            middle = (min + max)/2; 
            //cout << "middle: " << middle << endl;
            
            //The biggest thing to worry is the overflow! 
            if (middle <= x/middle && (middle+1) > x/(middle+1))
                return middle;
            else if (middle > x/middle)
                max = middle - 1;
            else 
                min = middle + 1;
        }
        
        return middle; 
    }
};
