class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> C(A.size(),vector<int>(B[0].size(),0));
        
        //Seems to be this is not the ideal approach. Should prefer the previous one.
        for (int row = 0; row < A.size(); row++) {
            for (int k = 0; k < A[0].size(); k++) {
                if (A[row][k]) {
                    for (int col = 0; col < B[0].size(); col++) {
                        if (B[k][col])
                            C[row][col] += A[row][k]*B[k][col];
                    }           
                }
            }
        }
        
        return C;
    }
};
