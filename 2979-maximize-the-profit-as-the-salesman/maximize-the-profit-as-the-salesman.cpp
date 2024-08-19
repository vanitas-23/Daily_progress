class Solution {
public:
    int f(int i,int n,vector<vector<int>>& off,vector<int>& dum,vector<int>& dp)
    {
        if(i==dum.size())
        return 0;
        if(dp[i]!=-1)
        return dp[i];
        int nt=f(i+1,n,off,dum,dp);
        int t=off[i][2]+f(upper_bound(dum.begin(),dum.end(),off[i][1])-dum.begin(),n,off,dum,dp);
        return dp[i]=max(t,nt);
    }
    int maximizeTheProfit(int n, vector<vector<int>>& off) {
        sort(off.begin(),off.end());
        vector<int>dum;
        for(auto i:off)
        dum.push_back(i[0]);
        vector<int>dp(off.size(),-1);
        return f(0,n,off,dum,dp);
    }
};