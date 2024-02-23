class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int>adj[n];
        map<pair<int,int>,int>mp;
        for(auto i:flights)
        adj[i[0]].push_back(i[1]),mp[{i[0],i[1]}]=i[2];

        int ans=INT_MAX;
        queue<pair<int,int>>q;
        q.push({src,0});
        vector<int>vis(n,1e9);
        vis[src]=0;
        while(!q.empty() && k>-1)
        {
            int m=q.size();
         //   cout<<m<<" ";
            for(int _=0;_<m;_++)
            {
                auto x=q.front();
                q.pop();
               // cout<<x.second<<" ";
                
                for(int i:adj[x.first])
               // if(!vis[i])
                if(x.second+mp[{x.first,i}]<vis[i])
                q.push({i,x.second+mp[{x.first,i}]}),vis[i]=x.second+mp[{x.first,i}];//cout<<i<<" "<<x.second+mp[{x.first,i}];
            }
            k--;
        }
        return vis[dst]==1e9?-1:vis[dst];
    }
};