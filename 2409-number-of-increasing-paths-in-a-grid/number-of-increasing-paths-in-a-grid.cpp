#define ll long long
class Solution {
public:
    int countPaths(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int mod=1e9+7;
        vector<int>adj[n*m];
        vector<int>ind(n*m);
        for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            if(i+1<n && grid[i+1][j]>grid[i][j])
            adj[i*m+j].push_back((i+1)*m+j),ind[(i+1)*m+j]++;
            if(j+1<m && grid[i][j+1]>grid[i][j])
            adj[i*m+j].push_back(i*m+j+1),ind[i*m+j+1]++;
            if(i-1>=0 && grid[i-1][j]>grid[i][j])
            adj[i*m+j].push_back((i-1)*m+j),ind[(i-1)*m+j]++;
            if(j-1>=0 && grid[i][j-1]>grid[i][j])
            adj[i*m+j].push_back(i*m+j-1),ind[i*m+j-1]++;
        }
        ll ans=0;
        queue<pair<int,ll>>q;
        vector<ll>dp(n*m,1);
        for(int i=0;i<n*m;i++)
        {
            if(ind[i]==0)
            q.push({i,1});
        }
        while(!q.empty())
        {
            auto x=q.front();
            q.pop();
            for(auto i:adj[x.first])
            {
                dp[i]=(dp[i]%mod+x.second%mod)%mod;
                ind[i]--;
                if(ind[i]==0)
                q.push({i,dp[i]});
            }
        }
        for(auto i:dp)
        ans=(ans%mod+i%mod)%mod;
        return ans;
    }
};