class Solution {
public:
    // map<pair<int,vector<int>>,int>dp;
    int f(int curr,int vis,vector<vector<int>>& grid,int n,int m,int all,vector<vector<int>>& dp)
    {
        if(all==n)
        return 0;
        if(dp[curr][vis]!=-1)
        return dp[curr][vis];
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(vis&(1<<i))
            continue;
            int j=upper_bound(grid[i].begin(),grid[i].end(),curr)-grid[i].begin();
            for(;j<m;j++){
            
            ans=max(ans,grid[i][j]+f(grid[i][j],vis|(1<<i),grid,n,m,all+1,dp));
            // vis[i]=0;
            }
        }
        return dp[curr][vis]=ans;
    }
    int maxScore(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        for(auto& i:grid)
        sort(i.begin(),i.end());
        sort(grid.begin(),grid.end());
        
        int vis=0;
        vector<vector<int>>dp(101,vector<int>(1025,-1));
        return f(0,vis,grid,n,m,0,dp);
    }
};