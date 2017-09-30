// My solution: bruteforce


// Editorial solution 1: DP

public class Solution {
    public int maximalSquare(char[][] matrix) {
        int rows = matrix.length, cols = rows > 0 ? matrix[0].length : 0;
        int[][] dp = new int[rows + 1][cols + 1]; // => Good trick to avoid the out-of-bound check for dp.
        int maxsqlen = 0;
        for (int i = 1; i <= rows; i++) {
            for (int j = 1; j <= cols; j++) {
                if (matrix[i-1][j-1] == '1'){
                    dp[i][j] = Math.min(Math.min(dp[i][j - 1], dp[i - 1][j]), dp[i - 1][j - 1]) + 1;
                    maxsqlen = Math.max(maxsqlen, dp[i][j]);
                }
            }
        }
        return maxsqlen * maxsqlen;
    }
}

// Editorial solution 2: DP enhanced
public class Solution {
    public int maximalSquare(char[][] matrix) {
        int rows = matrix.length, cols = rows > 0 ? matrix[0].length : 0;
        int[] dp = new int[cols + 1];
        int maxsqlen = 0, prev = 0;
        for (int i = 1; i <= rows; i++) {
            for (int j = 1; j <= cols; j++) {
                int temp = dp[j];
                if (matrix[i - 1][j - 1] == '1') {
                    dp[j] = Math.min(Math.min(dp[j - 1], prev), dp[j]) + 1;
                    maxsqlen = Math.max(maxsqlen, dp[j]);
                } else {
                    dp[j] = 0; //=> Otherwise, this will contain a value that was from the previous rows... solution 1 does not need this step because a new space is allocated for each i/j.
                }
                prev = temp;
            }
        }
        return maxsqlen * maxsqlen;
    }
}

// What I repeated solution 1 with C++
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int nrow = matrix.size(); 
        int ncol = nrow > 0 ? matrix[0].size() : 0;
        
        vector<vector<int>> dp(nrow+1,vector<int>(ncol+1,0));
        
        int maxLen = 0;
        for (int r = 1; r <= nrow; r++) {
            for (int c = 1; c <= ncol; c++) {
                if (matrix[r-1][c-1] == '1') {
                    dp[r][c] = min(min(dp[r-1][c], dp[r][c-1]), dp[r-1][c-1]) + 1;
                    if (dp[r][c] > maxLen)
                        maxLen = dp[r][c];
                }
            }
        }
        
        return maxLen*maxLen;
    }
};
