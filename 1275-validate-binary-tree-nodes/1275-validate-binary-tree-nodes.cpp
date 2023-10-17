class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& l, vector<int>& r) {
        vector<int>adj[n];
        vector<int>val(n,1);
        for(int i=0;i<n;i++){
            if(l[i]!=-1){
                adj[i].push_back(l[i]);
                val[l[i]]=0;
            }
            if(r[i]!=-1){
                 adj[i].push_back(r[i]);
                 val[r[i]]=0;
            }
           
        }
        for(auto i:adj)
        if(i.size()>2)
        return false;
       
        int z=accumulate(val.begin(),val.end(),0);
        if(z!=1)
        return false;
        int parent=-1;
        for(int i=0;i<n;i++)
        if(val[i]==1)
        parent=i;
        
        queue<int>q;
        vector<int>vis(n,0);
        q.push(parent);
        vis[parent]=1;
        while(!q.empty()){
            int it=q.front();q.pop();
            for(int x:adj[it]){
                if(!vis[x]){
                    q.push(x);
                    vis[x]=1;
                }   
                else
                    return false;
            }
        }
        return accumulate(vis.begin(),vis.end(),0)==n;
    }
};