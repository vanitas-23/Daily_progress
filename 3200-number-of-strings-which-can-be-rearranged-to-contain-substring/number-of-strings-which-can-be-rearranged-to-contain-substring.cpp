class Solution {
public:
    int m=1e9+7;
    int f(int i,int n,int mask,vector<vector<int>>& dp)
    {
        if(i==n)
        return __builtin_popcount(mask)==4;
        if(dp[i][mask]!=-1)
        return dp[i][mask];
        int ans=0;
        for(int j=0;j<26;j++)
        {
            if(j==4)
            {
                if(mask&1)
                ans=(ans%m+f(i+1,n,mask|(2),dp)%m)%m;
                else
                ans=(ans%m+f(i+1,n,mask|(1),dp)%m)%m;
            }
            else if(j==11)
            ans=(ans%m+f(i+1,n,mask|(4),dp)%m)%m;
            else if(j==19)
            ans=(ans%m+f(i+1,n,mask|(8),dp)%m)%m;
            else
            ans=(ans%m+f(i+1,n,mask,dp)%m)%m;
        }
        return dp[i][mask]=ans;
    }
    int stringCount(int n) {
        if(n<4)
        return 0;
        int mask=0;
        vector<vector<int>>dp(n,vector<int>(16,-1));
        return f(0,n,mask,dp);
    }
};