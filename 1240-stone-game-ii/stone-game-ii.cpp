class Solution {
public:
    int f(int i,int n,vector<int>& piles,int m,vector<int>& pre,vector<vector<int>>& dp)
    {
        if(i==n)
        return 0;
        int ans=0;
        if(dp[i][m]!=-1)
        return dp[i][m];
        for(int j=i;j<n && j<i+2*m;j++)
        {
            int sum=pre[j];
            if(i!=0)
            sum-=pre[i-1];
            int rem=pre[n-1]-pre[j];
            ans=max(ans,sum+rem-f(j+1,n,piles,max(m,(j-i+1)),pre,dp));
        }
        return dp[i][m]=ans;
    }
    int stoneGameII(vector<int>& piles) {
        int n=piles.size();
        vector<int>pre=piles;
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        for(int i=1;i<n;i++)
        pre[i]+=pre[i-1];
        return f(0,n,piles,1,pre,dp);
    }
};