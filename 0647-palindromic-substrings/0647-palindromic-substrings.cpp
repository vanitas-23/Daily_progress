class Solution {
public:
int solveMem(string& s, int i, int j, vector<vector<int>>& dp)  {
        if(i>j) return 1;
        if(dp[i][j] != -1)  return dp[i][j];
        return dp[i][j] = (s[i]==s[j]) ? solveMem(s, i+1, j-1, dp) : 0;
    }
    int countSubstrings(string s) {
       int cnt = 0, n=s.length();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        for(int i=0; i<n; i++)
            for(int j=i; j<n; j++)
                
                cnt += solveMem(s, i, j, dp);
        return cnt;
    }
};