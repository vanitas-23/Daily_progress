#define ll long long
class Solution {
public:
    ll f(int i,int n,int curr,vector<int>& nums, int k,int tar,vector<vector<vector<ll>>>& dp)
    {
        if(i==n)
        return (curr%k)==tar;
        if(dp[i][curr][tar]!=-1)
        return dp[i][curr][tar];
        ll t=f(i+1,n,(curr*(nums[i]%k))%k,nums,k,tar,dp);
        ll nt=(curr%k)==tar;
        return dp[i][curr][tar]=t+nt;
    }
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<ll>res(k);
        int n=nums.size();
        vector<vector<vector<ll>>>dp(n,vector<vector<ll>>(k,vector<ll>(k,-1)));
        for(int i=0;i<k;i++)
        {
            ll ans=0;
            for(int j=0;j<n;j++)
            ans+=f(j+1,n,nums[j]%k,nums,k,i,dp);
            res[i]=ans;
        }
        return res;
    }
};