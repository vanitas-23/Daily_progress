class Solution {
public:
    int f(int i,int n,vector<int>& r,int curr,vector<vector<int>>& dp)
    {
        if(i==n)
        return 0;
        if(dp[i][curr]!=-1)
        return dp[i][curr];
        int nt=f(i+1,n,r,curr,dp);
        int t=0;
        if(curr<r[i])
        t=r[i]+f(i+1,n,r,curr+r[i],dp);
        return dp[i][curr]=max(t,nt);
    }
    int maxTotalReward(vector<int>& r) {
        sort(r.begin(),r.end());
        int n=r.size();
        vector<vector<int>>dp(n,vector<int>(2*r.back(),-1));
        return f(0,n,r,0,dp);
    }
};