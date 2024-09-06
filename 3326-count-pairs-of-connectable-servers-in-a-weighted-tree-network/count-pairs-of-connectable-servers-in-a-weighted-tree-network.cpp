class Solution {
public:
    map<pair<int,int>,int>mp;
    int f(int node,vector<int>adj[],int par,int curr,int ss)
    {
        int ans=(curr%ss)==0;
        for(auto i:adj[node])
        if(i!=par)
        ans+=f(i,adj,node,curr+mp[{node,i}],ss);
        return ans;
    }
    vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges, int ss) {
        int n=edges.size();
        vector<int>adj[n+1];

        for(auto i:edges)
        {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
            mp[{i[0],i[1]}]=i[2];
            mp[{i[1],i[0]}]=i[2];
        }
        vector<int>ans(n+1);
        for(int i=0;i<=n;i++)
        {
            vector<int>x;
            for(auto j:adj[i])
            x.push_back(f(j,adj,i,mp[{i,j}],ss));
            if(x.size()==1)
            continue;
            int req=0;
            auto temp=x;
            for(int j=temp.size()-2;j>=0;j--)
            temp[j]+=temp[j+1];
            for(int j=0;j<x.size()-1;j++)
            req+=(x[j]*temp[j+1]);
            ans[i]=req;
        }
        return ans;
    }
};