class Solution {
public:
    int f(int i,int j,int n,int m,vector<vector<int>>& grid, vector<vector<int>>& dp)
    {
        if(dp[i][j]!=-1)
        return dp[i][j];
        vector<int>rx={-1,0,1};
        vector<int>ry={1,1,1};
        int x=0;
        for(int k=0;k<3;k++)
        {
            int r=i+rx[k];
            int c=j+ry[k];
            if(r>=0 && r<n && c>=0 && c<m && grid[r][c]>grid[i][j])
            x=max(x,f(r,c,n,m,grid,dp));
            
        }
        return dp[i][j]=1+x;
    }
    int maxMoves(vector<vector<int>>& grid) {
        int ans=0;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        for(int i=0;i<n;i++)
        ans=max(ans,f(i,0,n,m,grid,dp));
        // cout<<grid[0][2];
        // cout<<f(0,2,n,m,grid);
        return ans-1;
    }
};