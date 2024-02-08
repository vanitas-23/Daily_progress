class Solution {
public:
    int f(int n,vector<int>& dp)
    {
        if(n==0)
        return 0;
        if(n<0)
        return 1e9;
        if(dp[n]!=-1)
        return dp[n];
        int ans=n;
        for(int i=2;i<=sqrt(n);i++)
            ans=min(ans,1+f(n-i*i,dp));

            return dp[n]=ans;
    }
    int numSquares(int n) {
        vector<int>dp(n+1,-1);
        return f(n,dp);
    }
};