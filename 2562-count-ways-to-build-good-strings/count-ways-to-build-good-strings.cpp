#define ll long long
class Solution {
public:
    int m=1e9+7;
    ll f(int i,int zero,int one,vector<ll>& dp)
    {
        if(i==0)
        return 1;
        if(dp[i]!=-1)
        return dp[i];
        ll ans=0;
        if(i>=zero)
        ans=(ans%m+f(i-zero,zero,one,dp)%m)%m;
        if(i>=one)
        ans=(ans%m+f(i-one,zero,one,dp)%m)%m;
        return dp[i]=(ans+m)%m;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<ll>dp(high+1,-1);
        for(int i=1;i<=high;i++)
        f(i,zero,one,dp);
        dp[0]=0;
        for(int i=1;i<=high;i++)
        dp[i]=(dp[i]%m+dp[i-1]%m)%m;
        return (dp[high]-dp[low-1]+m)%m;
    }
};