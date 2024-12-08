class Solution {
public:
    int f(int i,int n,vector<int>& start,vector<int>& end,vector<int>& value,int can,vector<vector<int>>& dp)
    {
        if(i==n)
        return 0;
        if(dp[i][can]!=-1)
        return dp[i][can];
        int nt=f(i+1,n,start,end,value,can,dp);
        int t=0;
        if(can)
        t=value[i]+f(upper_bound(start.begin(),start.end(),end[i])-start.begin(),n,start,end,value,can-1,dp);
        return dp[i][can]=max(t,nt);
    }
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end());
        int n=events.size();
        vector<int>start,end,value;
        for(auto i:events)
        {
            start.push_back(i[0]);
            end.push_back(i[1]);
            value.push_back(i[2]);
        }
        vector<vector<int>>dp(n,vector<int>(3,-1));
        return f(0,n,start,end,value,2,dp);
    }
};