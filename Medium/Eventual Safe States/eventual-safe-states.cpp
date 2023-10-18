//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> eventualSafeNodes(int v, vector<int> adj[]) {
        // code here
        vector<int>ter;
        for(int i=0;i<v;i++)
        if(adj[i].size()==0)
        ter.push_back(i);
        
        vector<int>vis(v,0);
        vector<int>adjj[v];
        for(int i=0;i<v;i++){
            for(int j=0;j<adj[i].size();j++)
            adjj[adj[i][j]].push_back(i);
        }
        vector<int>res;
        vector<int>inD(v);
        
        for(int i=0;i<v;i++)
        inD[i]=adj[i].size();
         queue<int>q;
        for(int i=0;i<v;i++){
            if(inD[i]==0) q.push(i);
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            res.push_back(node);
            for(auto it:adjj[node]){
                inD[it]--;
                if(inD[it]==0)q.push(it);
            }
        }
        sort(res.begin(),res.end());
        return res;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends