class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1)
        return {0};
        vector<int>res;
        queue<int>q;
        vector<int>adj[n+1];
        vector<int>inD(n+1);
        for(auto i:edges)
        {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
            inD[i[0]]++;
            inD[i[1]]++;
        }
        for(int i=0;i<=n;i++)
        if(inD[i]==1)
        q.push(i);

        while(n>2)
        {
            int sz=q.size();
            //cout<<sz<<" ";
            n-=sz;
            while(sz>0)
            {
                int ele=q.front();
                q.pop();
               // cout<<ele<<" ";
                for(auto i:adj[ele])
                {
                    inD[i]--;
                    if(inD[i]==1)
                    q.push(i);
                }
                sz--;
            }
            
        }
        while(!q.empty())
        {
            auto x=q.front();
            q.pop();
            res.push_back(x);
        }
        return res;
    }
};