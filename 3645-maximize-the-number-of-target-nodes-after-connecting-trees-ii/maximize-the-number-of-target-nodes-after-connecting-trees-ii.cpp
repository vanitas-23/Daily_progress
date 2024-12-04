class Solution {
public:
    vector<vector<int>> f(vector<int>adj[],int n)
    {
        queue<int>q;
        q.push(0);
        vector<vector<int>>ans(n+1,vector<int>(2));
        int res=0;
        bool b=1;
        vector<int>vis(n+1);
        vis[0]=1;
        while(!q.empty())
        {
            int m=q.size();
            for(int i=0;i<m;i++)
            {
                auto x=q.front();
                q.pop();
                for(auto j:adj[x])
                if(!vis[j])
                {
                    q.push(j);
                    vis[j]=1;
                }
            }
            if(b)
            res+=m;
            b=!b;
        }
       //cout<<res<<" ";
        int even=res;
        int odd=n+1-res;
        ans[0][0]=even;
        ans[0][1]=odd;
        fill(vis.begin(), vis.end(), 0);
        vis[0]=1;
        q.push(0);
        while(!q.empty())
        {
            int m=q.size();
            swap(even,odd);
            for(int i=0;i<m;i++)
            {
                auto x=q.front();
                q.pop();
                for(auto j:adj[x])
                if(!vis[j])
                {
                    q.push(j);
                    vis[j]=1;
                    ans[j][0]=even;
                    ans[j][1]=odd;
                }
            }
        }
        return ans;
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n=edges1.size();
        int m=edges2.size();
        vector<int>adj1[n+1];
        vector<int>adj2[m+1];
        for(auto i:edges1)
        {
            adj1[i[0]].push_back(i[1]);
            adj1[i[1]].push_back(i[0]);
        }
        for(auto i:edges2)
        {
            adj2[i[0]].push_back(i[1]);
            adj2[i[1]].push_back(i[0]);
        }
        auto x=f(adj1,n);
        auto y=f(adj2,m);
        int mx=max(y[0][0],y[0][1]);
        vector<int>res(n+1);
        for(int i=0;i<=n;i++)
        res[i]=x[i][0]+mx;
        return res;
    }
};