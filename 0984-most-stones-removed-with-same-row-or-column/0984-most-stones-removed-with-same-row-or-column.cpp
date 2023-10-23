class Solution {
public:
    void dfs(vector<unordered_set<int>> &gr, int s, vector<bool> &vis, int &ans)
    {
        if(vis[s]) return;
        vis[s] = true;
        ans++;

        for(int e:gr[s])
            if(!vis[e]) 
                dfs(gr, e, vis, ans);    
    }

    int removeStones(vector<vector<int>>& stones) {
        int ans = 0;
        int n = stones.size();
        vector<bool> vis(n, false);

        vector<unordered_set<int>> gr(n);
        unordered_map<int, unordered_set<int>> x, y;

        for(int i=0;i<n;i++)
        {
            x[stones[i][0]].insert(i);
            y[stones[i][1]].insert(i);
        }

        for(int i=0;i<n;i++)
        {
            auto v = stones[i];
            for(int a:x[v[0]])
            if(a!=i)
            gr[i].insert(a);

            for(int a:y[v[1]])
            if(a!=i)
            gr[i].insert(a);
        }
        for(int i=0;i<n;i++)
            if(!vis[i])
            {
                dfs(gr, i, vis, ans);
                ans--;
            }
        return ans;
    }
};