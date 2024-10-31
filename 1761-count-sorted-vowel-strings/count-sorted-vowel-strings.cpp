class Solution {
public:
    int f(int i,int n,int j,vector<vector<int>>& dp)
    {
        if(i==n)
        return 1;
        if(dp[i][j]!=-1)
        return dp[i][j];
        int ans=0;
        for(int k=j;k<5;k++)
        ans+=f(i+1,n,k,dp);
        return dp[i][j]=ans;
    }
    int countVowelStrings(int n) {
        int ans=0;
        vector<vector<int>>dp(n,vector<int>(5,-1));
        return f(0,n,0,dp);
    }
};