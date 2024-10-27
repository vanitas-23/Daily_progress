class Solution {
public:
    int f(int i,int j,int n,int m,vector<vector<int>>& mat,vector<vector<int>>& dp)
    {
        if(i==n || j==m)
        return 0;
        if(dp[i][j]!=-1)
        return dp[i][j];
        if(mat[i][j]==0)
        return dp[i][j]=0;
        return dp[i][j]=1+min({f(i+1,j,n,m,mat,dp),f(i,j+1,n,m,mat,dp),f(i+1,j+1,n,m,mat,dp)});
    }
    int countSquares(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int ans=0;
        vector<vector<int>>dp(n,vector<int>(m,-1));
        for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        if(mat[i][j])
        ans+=f(i,j,n,m,mat,dp);
        return ans;
    }
};