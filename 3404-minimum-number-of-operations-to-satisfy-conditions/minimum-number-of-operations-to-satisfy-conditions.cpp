class Solution {
public:
    int f(int i,int m,int n,vector<vector<int>>& grid,int last,vector<vector<int>>& dp)
    {
        if(i==m)
        return 0;
        if(dp[i][last+1]!=-1)
        return dp[i][last+1];
        vector<int>arr(10);
        for(int j=0;j<n;j++)
        arr[grid[j][i]]++;
        int ans=INT_MAX;
        for(int j=0;j<10;j++)
        if(j!=last)
        ans=min(ans,n-arr[j]+f(i+1,m,n,grid,j,dp));
        return dp[i][last+1]=ans;
    }
    int minimumOperations(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(11,-1));
        return f(0,m,n,grid,-1,dp);
    }
};