#define ll long long
class Solution {
public:
    long long f(int i,int m,vector<vector<int>>& rides,vector<int>& arr,vector<ll>& dp)
    {
        if(i==m)
        return 0;
        if(dp[i]!=-1)
        return dp[i];
        ll nt=f(i+1,m,rides,arr,dp);
        ll t=rides[i][1]-rides[i][0]+rides[i][2];
        auto it=lower_bound(arr.begin(),arr.end(),rides[i][1])-arr.begin();
        t+=f(it,m,rides,arr,dp);
        return dp[i]=max(t,nt);
    }
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        sort(rides.begin(),rides.end());
        vector<int>arr;
        for(auto i:rides)
        arr.push_back(i[0]);
        int m=rides.size();
        vector<ll>dp(m,-1);
        return f(0,m,rides,arr,dp);
    }
};