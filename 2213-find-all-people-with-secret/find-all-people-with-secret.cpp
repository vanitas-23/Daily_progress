class Solution {
public:
    void dfs(vector<pair<int,int>>temp,vector<int>& vis,int n)
    {
        
    }
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        map<int,vector<pair<int,int>>>mp;
        for(auto i:meetings)
        mp[i[2]].push_back({i[0],i[1]});

        vector<int>vis(n);
        vis[0]=1;
        vis[firstPerson]=1;

        for(auto it:mp)
        {
        unordered_map<int,vector<int>>adj;
        unordered_set<int>st;
         auto temp=it.second;
        for(auto i:temp){
        adj[i.first].push_back(i.second),adj[i.second].push_back(i.first);
        if(vis[i.first]) st.insert(i.first);
        if(vis[i.second]) st.insert(i.second);
        }
        queue<int>q;
        for(auto i:st)
        q.push(i);
        while(!q.empty())
        {
            auto x=q.front();
            q.pop();
            for(int i:adj[x])
            if(!vis[i])
            q.push(i),vis[i]=1;
        }
        }
        vector<int>res;
        for(int i=0;i<n;i++)
        if(vis[i])
        res.push_back(i);

        return res;
    }
};