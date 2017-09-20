class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> C(A.size(),vector<int>(B[0].size(),0));
        vector<vector<int>> nonzeroA(A.size());
        vector<vector<int>> nonzeroB(B[0].size());
        
        //save the nonzero index for each row of A
        for (int row = 0; row < A.size(); row++) {
            for (int col = 0; col < A[0].size(); col++) {
                if (A[row][col])
                    nonzeroA[row].push_back(col);
            }
        }
            
        //save the nonzero index for each col of B
        for (int row = 0; row < B.size(); row++) {
            for (int col = 0; col < B[0].size(); col++) {
                if (B[row][col])
                    nonzeroB[col].push_back(row);
            }
        }    
        
        int sizeA, sizeB;
        int idxA, idxB;
        for (int row = 0; row < A.size(); row++) {
            for (int col = 0; col < B[0].size(); col++) {
                idxA = idxB = 0;
                sizeA = nonzeroA[row].size();
                sizeB = nonzeroB[col].size();
                //When it comes to while, always be keen to increment the index accordingly.
                while (idxA < sizeA && idxB < sizeB) {
                    if (nonzeroA[row][idxA] == nonzeroB[col][idxB]) {
                        C[row][col] += A[row][nonzeroA[row][idxA]]*B[nonzeroB[col][idxB]][col];
                        idxA++;
                        idxB++;
                    } else if (nonzeroA[row][idxA] > nonzeroB[col][idxB]) {
                        idxB++;    
                    } else {
                        idxA++;
                    }
                }               
            }
        }
        
        return C;
    }
};
