class Solution {
public:
    void dfs(int i,int& ele,vector<int>arr[],vector<int>& quiet,int n,vector<int>& vis,int& ans)
    {

        vis[i]=1;
        if(ans>=quiet[i])
        ele=i,ans=quiet[i];
        for(int x:arr[i])
        if(!vis[x])
        dfs(x,ele,arr,quiet,n,vis,ans);

    }
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n=quiet.size();
        vector<int>arr[n];
        for(auto i:richer)
        arr[i[1]].push_back(i[0]);

        vector<int>res(n);
        for(int i=0;i<n;i++)
        {
            vector<int>vis(n);
            int ele=i;
            int ans=INT_MAX;
            dfs(i,ele,arr,quiet,n,vis,ans);
            res[i]=ele;
        }
        return res;
    }
};