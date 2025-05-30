class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n=edges.size();
        vector<int>adj[n];
        vector<int>dist1(n,1e9);
        vector<int>dist2(n,1e9);
        queue<int>q;
        for(int i=0;i<n;i++)
        {
            if(edges[i]==-1) continue;
            adj[i].push_back(edges[i]);
        }
        q.push(node1);
        dist1[node1]=0;
        dist2[node2]=0;
        int dd=1;
        while(!q.empty())
        {
            int m=q.size();
            for(int i=0;i<m;i++)
            {
                auto x=q.front();
                q.pop();
                for(auto j:adj[x])
                if(dist1[j]==1e9)
                {
                    q.push(j);
                    dist1[j]=dd;
                }
            }
            dd++;
        }
        dd=1;
        q.push(node2);
        while(!q.empty())
        {
            int m=q.size();
            for(int i=0;i<m;i++)
            {
                auto x=q.front();
                q.pop();
                for(auto j:adj[x])
                if(dist2[j]==1e9)
                {
                    q.push(j);
                    dist2[j]=dd;
                }
            }
            dd++;
        }
        int id=-1;
        int mn=1e9;
        for(int i=0;i<n;i++)
        {
            if(dist1[i]==1e9 || dist2[i]==1e9)
            continue;
            if(max(dist1[i],dist2[i])<mn)
            {
                mn=max(dist1[i],dist2[i]);
                id=i;
            }
        }
        return id;
    }
};