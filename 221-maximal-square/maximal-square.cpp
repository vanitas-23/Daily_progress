class Solution {
public:
    int f(int i,int j,int n,int m,vector<vector<char>>& mat,vector<vector<int>>& dp)
    {
        if(i==n || j==m)
        return 0;
        if(dp[i][j]!=-1)
        return dp[i][j];
        if(mat[i][j]=='0')
        return dp[i][j]=0;
        return dp[i][j]=1+min({f(i+1,j,n,m,mat,dp),f(i,j+1,n,m,mat,dp),f(i+1,j+1,n,m,mat,dp)});
    }
    int maximalSquare(vector<vector<char>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        f(i,j,n,m,mat,dp);
        int ans=0;
        for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        ans=max(ans,dp[i][j]);
        return ans*ans;
    }
};