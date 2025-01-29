class Solution {
public:
    set<vector<int>>st;
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int>adj[n+1];
        vector<int>res;
        for(auto i:edges){
        adj[i[0]].push_back(i[1]);
        adj[i[1]].push_back(i[0]);
    }
       
       for(int i=1;i<=n;i++){
            queue<pair<int,int>>q;
            q.push({i,-1});
            vector<int>vis(n+1,0);
            
            while(!q.empty()){
                auto j=q.front();
                q.pop();
                int parent=j.second;
                int x = j.first;
                vis[x]=1;
                for(int y:adj[x]){
                    if(!vis[y])
                    q.push({y,x});
                    else{
                        if(y!=parent){
                           if(y<x)
                            st.insert({y,x});
                            else
                            st.insert({x,y});
                        }
                    }
                }
            }
       }
       for(int i=n-1;i>=0;i--)
       if(st.find(edges[i])!=st.end())
       return edges[i];
    return res;
    }
};