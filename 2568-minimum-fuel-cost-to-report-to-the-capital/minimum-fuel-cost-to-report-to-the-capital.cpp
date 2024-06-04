class Solution {
public:
    long long ans=0;
    long long dfs(vector<int>adj[],int seats,int node,int lst)
    {
       long long cnt=0;
       for(int i:adj[node])
            if(i!=lst)
            {
                long long p=dfs(adj,seats,i,node);
                cnt+=p;
                ans+=ceil(p*1.0/seats);
            }
        return cnt+1;
    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n=roads.size();
        vector<int>adj[n+1];
        for(auto i:roads)
        {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        dfs(adj,seats,0,-1);
        return ans;
    }
};