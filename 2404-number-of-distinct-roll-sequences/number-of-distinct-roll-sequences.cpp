int mod=1e9+7;
class Solution {
public:
    int f(int i,int n,map<int,vector<int>>& mp,int last,int plast,vector<vector<vector<int>>>& dp)
    {
        if(i==n)
        return 1;
        if(dp[i][last][plast]!=-1)
        return dp[i][last][plast];
        auto x=mp[last];
        int ans=0;
        int newmask=0;
        for(auto j:x)
        {
            if(j==plast) continue;
            ans=(ans%mod+f(i+1,n,mp,j,last,dp)%mod)%mod;
        }
        return dp[i][last][plast]=ans;
    }
    int distinctSequences(int n) {
        map<int,vector<int>>mp;
        mp[1]={2,3,4,5,6};
        mp[2]={1,3,5};
        mp[3]={1,2,4,5};
        mp[4]={1,3,5};
        mp[5]={1,2,3,4,6};
        mp[6]={1,5};
        int ans=0;
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(7,vector<int>(7,-1)));
        for(int i=1;i<=6;i++)
        ans=(ans%mod+f(1,n,mp,i,0,dp)%mod)%mod;
        return ans;
    }
};