class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp( m , vector<int> (n));  
        // corner
        dp[m-1][n-1] = INT_MIN;
        // last row
        int addR, valR, addB, valB, ans = INT_MIN;
        for (int i = n-2; i >= 0; i--) {
            valR = grid[m-1][i+1] - grid[m-1][i];
            if (dp[m-1][i+1] != INT_MIN) addR = dp[m-1][i+1] + valR;
            else addR = valR;
            dp[m-1][i] = max(valR, addR);
            ans = max(ans, dp[m-1][i]);
        }
        // last column
        for (int i = m-2; i >= 0; i--) {
            valB = grid[i+1][n-1] - grid[i][n-1];
            if (dp[i+1][n-1] != INT_MIN) addB = dp[i+1][n-1] + valB;
            else addB = valB;
            dp[i][n-1] = max(valB, addB);
            ans = max(ans, dp[i][n-1]);
        }
        // others
        int Rmax, Bmax;
        for (int i = m-2; i >= 0; i--) {
            for (int j = n-2; j >= 0; j--) {
                valR = grid[i][j+1] - grid[i][j];
                if (dp[i][j+1] != INT_MIN) addR = dp[i][j+1] + valR;
                else addR = valR;
                Rmax = max(valR, addR);
                
                valB = grid[i+1][j] - grid[i][j];
                if (dp[i+1][j] != INT_MIN) addB = dp[i+1][j] + valB;
                else addB = valB;
                Bmax = max(valB, addB);
                
                dp[i][j] = max(Rmax, Bmax);
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
};