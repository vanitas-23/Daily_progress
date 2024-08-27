class Solution {
public:
    int f(int i,int n,int last,vector<int>& prices,vector<vector<int>>& dp)
    {
        if(i==n)
        return 0;
        if(dp[i][last]!=-1)
        return dp[i][last];
        if(2*last+1<i)
        return dp[i][last]=prices[i]+f(i+1,n,i,prices,dp);
        //cout<<i<<" "<<last<<endl;
        return dp[i][last]=min(f(i+1,n,last,prices,dp),prices[i]+f(i+1,n,i,prices,dp));
    }
    int minimumCoins(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return prices[0]+f(1,n,0,prices,dp);
    }
};