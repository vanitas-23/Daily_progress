class Solution {
public:
int m=1e9+7;
    int f(vector<vector<int>>& grid,int k, int i,int j,int sum,vector<vector<vector<int>>>& dp){
          
          if(i==0 && j==0)
          return sum%k==0;
          int up=0;
          int upl=0;
          if(dp[i][j][sum]!=-1)
          return dp[i][j][sum];
          if(i>=1)
           up=f(grid,k,i-1,j,(sum+grid[i-1][j])%k,dp);
           if(j>=1)
           upl=f(grid,k,i,j-1,(sum+grid[i][j-1])%k,dp);
          return dp[i][j][sum]=(up%m+upl%m)%m;
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(k,-1)));
        return f(grid,k,n-1,m-1,(grid[n-1][m-1])%k,dp);
    }
};