class Solution {
public:
    unordered_map<int,vector<int>>mp;
    int f(int i,int j,int n,int m,string& key,string& ring,vector<vector<int>>& dp)
    {
        if(i==n)
        return 0;
        
        if(dp[i][j]!=-1)
        return dp[i][j];
        if(key[i]==ring[j])
        return dp[i][j]=1+f(i+1,j,n,m,key,ring,dp);
        int ans=1e9;
        for(int x:mp[key[i]])
        {
            int stp=min(abs(x-j),m-abs(x-j));
            ans=min(ans,1+stp+f(i+1,x,n,m,key,ring,dp));
        }
       return dp[i][j]=ans;
    }
    int findRotateSteps(string ring, string key) {
        int n=key.size();
        int m=ring.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        
        for(int i=0;i<m;i++)
        mp[ring[i]].push_back(i);
        return f(0,0,n,m,key,ring,dp);
    }
};