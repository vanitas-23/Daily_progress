class Solution {
public:
    int f(int ltc,int rtc,int ldc,int rdc,vector<int>& horizontalCut, vector<int>& verticalCut,vector<vector<vector<vector<int>>>>& dp)
    {
        if(ltc+1==rtc && ldc+1==rdc)
        return 0;
        if(dp[ltc][rtc][ldc][rdc]!=-1)
        return dp[ltc][rtc][ldc][rdc];
        int ans=1e9;
        //vertical
        for(int i=ltc+1;i<rtc;i++)
        ans=min(ans,verticalCut[i-1]+f(ltc,i,ldc,rdc,horizontalCut,verticalCut,dp)+f(i,rtc,ldc,rdc,horizontalCut,verticalCut,dp));
        //horizontal
        for(int i=ldc+1;i<rdc;i++)
        ans=min(ans,horizontalCut[i-1]+f(ltc,rtc,ldc,i,horizontalCut,verticalCut,dp)+f(ltc,rtc,i,rdc,horizontalCut,verticalCut,dp));
        return dp[ltc][rtc][ldc][rdc]=ans;
    }
    int minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        vector<vector<vector<vector<int>>>>dp(n+1,vector<vector<vector<int>>>(n+1,
        
        vector<vector<int>>(m+1,vector<int>(m+1,-1))));
        return f(0,n,0,m,horizontalCut,verticalCut,dp);
    }
};