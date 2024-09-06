class Solution {
public:
    vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges, int signalSpeed) {
        ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        int n=edges.size()+1;
        typedef pair<int,int> ii;
        vector<vector<ii>> g(n);
        for(auto& e:edges){
            g[e[0]].emplace_back(e[1], e[2]);
            g[e[1]].emplace_back(e[0], e[2]);
        }

        auto dfs=[&](int u, int p, int d, auto&& dfs)->int{
            int res=0;
            if(d%signalSpeed==0){
                res++;
            }
            for(auto& [v,w]: g[u]){
                if(v!=p){
                    res+=dfs(v,u,d+w, dfs);
                }
            }
            return res;
        };

        vector<int> ans(n);
        for(int i=0; i<n; i++){
            int m=g[i].size();
            if(m==1){
                ans[i]=0;
                continue;
            }
            int sum=0;
            ans[i]=0;
            for(auto& [v,w]:g[i]){
                int r=dfs(v,i,w, dfs);
                ans[i]+=sum*r;
                sum+=r;
            }
        }
        return ans;
    }
};