class Solution {
public:
    int m=1e9+7;
    long long f(int n,int k, vector<vector<int>>& dp)
    {
        if(k<0)
        return 0;
        if(n==0)
        return k==0;
        if(dp[n][k]!=-1)
        return dp[n][k];
        return dp[n][k]=(f(n-1,k,dp)+f(n,k-1,dp)-f(n-1,k-n,dp)+m)%m;
    }
    int kInversePairs(int n, int k) {
        vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
        return f(n,k,dp);
    }
};