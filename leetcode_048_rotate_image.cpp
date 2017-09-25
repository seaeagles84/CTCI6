class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size(); // n by n matrix
        
        if (n == 1)
            return;
        
        for (int layer = 0; layer < n/2; layer++) { // outer to inner (0, ... )
            int length = n - layer*2 - 1; // trailing one corner left
            vector<int> temp(length); // keeping the top row of the layer. 
            for (int i = 0; i < length; i++) {
                temp[i] = matrix[layer][layer+i];
                //cout << "temp[i]: " << temp[i] << endl;
            }
            
            //left to top
            for (int i = 0; i < length; i++)
                matrix[layer][layer+i] = matrix[n - 1 - layer - i][layer];
        
            //bottom to left
            for (int i = 0; i < length; i++)
                matrix[n - 1 - layer - i][layer] = matrix[n - 1 - layer][n - 1 - layer - i];
                
            //right to bottom
            for (int i = 0; i < length; i++)
                matrix[n - 1 - layer][n - 1 - layer - i] = matrix[layer + i][n - 1 - layer]; 
            
            //top to right
            for (int i = 0; i < length; i++)
                matrix[layer + i][n - 1 - layer] = temp[i];
        }
    }
};
