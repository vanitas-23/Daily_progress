class Solution {
public:
    int f(int i,int n,int m,vector<vector<int>>& grid,int lst,vector<vector<int>>& dp)
    {
        if(i==n)
        return 0;
        if(dp[i][lst]!=-1)
        return dp[i][lst];
        int ans=1e9;
        for(int j=0;j<m;j++)
        {
            if(j==lst)
            continue;
            ans=min(ans,grid[i][j]+f(i+1,n,m,grid,j,dp));
        }
        return dp[i][lst]=ans;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        int ans=1e9;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        for(int i=0;i<m;i++)
        ans=min(ans,grid[0][i]+f(1,n,m,grid,i,dp));
        return ans;
    }
};