#define ll long long
class Solution {
public:
    long long f(int node,int par,int istaken,vector<int>* adj,vector<int>& values,vector<vector<ll>>& dp)
    {
        if(adj[node].size()==1 && adj[node][0]==par)
        {
            if(istaken)
            return values[node];
            return 0;
        }
        if(dp[node][istaken]!=-1)
        return dp[node][istaken];
        if(istaken)
        {
            ll val=values[node];
            for(auto i:adj[node])
            if(i!=par)
            val+=f(i,node,istaken,adj,values,dp);
            return dp[node][istaken]=val;
        }
        ll case1=0;
        ll case2=values[node];
        for(auto i:adj[node])
        if(i!=par)
        case1+=f(i,node,1,adj,values,dp);
        for(auto i:adj[node])
        if(i!=par)
        case2+=f(i,node,0,adj,values,dp);
        return dp[node][istaken]=max(case1,case2);
    }
    long long maximumScoreAfterOperations(vector<vector<int>>& edges, vector<int>& values) {
        int n=values.size();
        vector<int>adj[n];
        for(auto i:edges)
        {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<vector<ll>>dp(n,vector<ll>(2,-1));
        return f(0,-1,0,adj,values,dp);
    }
};