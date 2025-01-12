class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited) {
        visited[node] = true;
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, adj, visited);
            }
        }
    }
    
    bool f(int n, vector<vector<int>>& edges, int threshold, int maxWeight) {
        vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            if (edge[2] <= maxWeight && adj[edge[0]].size() < threshold) {
                adj[edge[0]].push_back(edge[1]);
            }
        }
        for (int i = 0; i < n; ++i) {
            if (adj[i].size() > threshold) return false;
        }
        vector<bool> visited(n, false);
        vector<vector<int>> revAdj(n);
        for (auto& edge : edges) {
            if (edge[2] <= maxWeight) {
                revAdj[edge[1]].push_back(edge[0]);
            }
        }

        dfs(0, revAdj, visited);
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) return false;
        }
        
        return true;
    }
    
    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
        
        int low = 1, high = 0;
        for (auto& edge : edges) high = max(high, edge[2]);
        int result = -1;
        if(!f(n,edges,threshold,high)) return -1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (f(n, edges, threshold, mid)) {
                result = mid;
                high = mid - 1; 
            } else {
                low = mid + 1; 
            }
        }
        return result;
    }
};
