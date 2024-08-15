class Solution {
public:
    int f(int i,int n,vector<int>& a,int pre,vector<vector<int>>& dp)
    {
        if(i==n)
        return 0;
        if(dp[i][pre]!=-1)
        return dp[i][pre];
        int nt=f(i+1,n,a,pre,dp);
        int t = 0;
        if(a[i]>=a[pre])
        t=max(t,1+f(i+1,n,a,i,dp));
        return dp[i][pre]=max(t,nt);
    }
    int minimumOperations(vector<int>& a) {
        int n=a.size();
        int ans=0;
        vector<vector<int>>dp(n,vector<int>(n,-1));
        for(int i=0;i<n;i++)
        ans=max(ans,1+f(i+1,n,a,i,dp));
        return n-ans;
    }
};