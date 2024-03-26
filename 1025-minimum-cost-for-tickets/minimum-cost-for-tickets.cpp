class Solution {
public:
    int f(int i,int n,vector<int>& days,vector<int>& costs,vector<int>& dp)
    {
        if(i>=n)
        return 0;
        if(dp[i]!=-1)
        return dp[i];
        int fst=costs[0]+f(i+1,n,days,costs,dp);
        auto x=upper_bound(days.begin(),days.end(),days[i]+6);
        x--;
        int snd=costs[1]+f(x-days.begin()+1,n,days,costs,dp);
        auto y=upper_bound(days.begin(),days.end(),days[i]+29);
        y--;
        int trd=costs[2]+f(y-days.begin()+1,n,days,costs,dp);

        return dp[i]=min({fst,snd,trd});
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        vector<int>dp(n+1,-1);
        return f(0,days.size(),days,costs,dp);
    }
};