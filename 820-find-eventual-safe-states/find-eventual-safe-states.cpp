class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>adj[n];
        vector<int>inD(n);
        for(int i=0;i<n;i++)
        {
            for(auto j:graph[i])
            adj[j].push_back(i),inD[i]++;
        }
        queue<int>q;

        for(int i=0;i<n;i++)
        if(inD[i]==0) q.push(i);
        vector<int>ans;
        while(!q.empty())
        {
            auto x=q.front();
            q.pop();
            //cout<<x<<" ";
            ans.push_back(x);
            for(int i:adj[x])
            {
                inD[i]--;
                if(inD[i]==0)
                q.push(i);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};