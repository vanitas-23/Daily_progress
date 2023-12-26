class Solution {
public:
    int m=1e9+7;
    int f(int i,int n,int k,int target,vector<vector<int>>& dp){
        if(i==n)
        return target==0;
        if(target<0)
        return 0;
        if(dp[i][target]!=-1)
        return dp[i][target];
        int ans=0;
        for(int j=1;j<=k;j++)
        ans=(ans%m + f(i+1,n,k,target-j,dp)%m)%m;

        return dp[i][target]=ans;
    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        return f(0,n,k,target,dp);
    }
};