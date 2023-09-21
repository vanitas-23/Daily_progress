class Solution {
public:
    int f(int l,int r,vector<vector<int>>& dp){
        if(l>=r)
        return 0;
        int ans=INT_MAX;
        if(dp[l][r]!=-1)
        return dp[l][r];
        for(int i=l;i<=r;i++)
        ans=min(ans,i+max(f(i+1,r,dp),f(l,i-1,dp)));

        return dp[l][r]=ans;
    }
    int getMoneyAmount(int n) {
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return f(1,n,dp);
    }
};