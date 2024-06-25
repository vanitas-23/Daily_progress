class Solution {
public:
    map<pair<int,int>,double>mp;
    map<int,vector<int>>adj;
    double maxProbability(int n, vector<vector<int>>& ed, vector<double>& succ, int src, int dst) {
        int m=ed.size();
        for(int i=0;i<m;i++)
        {
            adj[ed[i][0]].push_back(ed[i][1]);
            adj[ed[i][1]].push_back(ed[i][0]);
            mp[{ed[i][0],ed[i][1]}]=succ[i];
            mp[{ed[i][1],ed[i][0]}]=succ[i];
        }
        priority_queue<pair<double,int>>pq;
        pq.push({1,src});
        vector<double>cal(n);
        cal[src]=1;
        while(!pq.empty())
        {
            auto x=pq.top();
            pq.pop();
            if(x.second==dst)
            return x.first;
            for(auto i:adj[x.second])
            {
                if(x.first*mp[{x.second,i}]>cal[i])
                {
                    pq.push({x.first*mp[{x.second,i}],i});
                    cal[i]=x.first*mp[{x.second,i}];
                }
            }
        }
        return cal[dst];
    }
};