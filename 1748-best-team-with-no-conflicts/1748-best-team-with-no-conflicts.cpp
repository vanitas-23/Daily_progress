class Solution {
public:
     int fun(vector<pair<int,int>>&combine,int i,int mx,vector<vector<int>>&dp)
    {
        if(i>=combine.size())
        return 0;
        if(dp[i][mx]!=-1)
        return dp[i][mx];

        if(combine[i].second>=mx)
        {
            int nottake=0+fun(combine,i+1,mx,dp);
            int take=combine[i].first+fun(combine,i+1,combine[i].second,dp);
            return dp[i][mx]=max(nottake,take);
        }
        else
        return dp[i][mx]=fun(combine,i+1,mx,dp);
    }
    int bestTeamScore(vector<int>& scores, vector<int>& ages) 
    {
        int n=scores.size();
        vector<pair<int,int>>combine;
        for(int i=0;i<n;i++)
        combine.push_back({scores[i],ages[i]});

        sort(combine.begin(),combine.end());
        vector<vector<int>>dp(n,vector<int>(1010,-1));
        return fun(combine,0,0,dp);   
    }
};