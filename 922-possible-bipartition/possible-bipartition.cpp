class Solution {
public:
    bool bp(vector<int>& clr,vector<int>adj[],int node,int par)
    {
            bool b=1;
            for(int i:adj[node])
            {
                if(i==par)
                continue;
                if(clr[i]==-1)
                {
                    clr[i]=!clr[node];
                    b=b&bp(clr,adj,i,node);
                }
                else if(clr[i]==clr[node])
                return 0;

            }
            return b;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int>adj[n+1];
        for(auto i:dislikes)
        adj[i[0]].push_back(i[1]),adj[i[1]].push_back(i[0]);

        vector<int>clr(n+1,-1);
        bool b=1;
        for(int i=1;i<=n;i++)
        {
            if(clr[i]==-1)
            {
                clr[i]=0;
                b= b& bp(clr,adj,i,0);
            } 
        }
        return b;
    }
};