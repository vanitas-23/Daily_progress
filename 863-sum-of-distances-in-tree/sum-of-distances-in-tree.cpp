class Solution {
public:
    int countHelper(int index, vector<vector<int>>& adj, vector<int>& nodeCount, int parent) // count number of nodes under each node after fixing 0 as root
    {
        for(auto x : adj[index]) if(x != parent) nodeCount[index] += countHelper(x, adj, nodeCount, index);
        return 1 + nodeCount[index];
    }
    void dfs(vector<vector<int>>& adj, int node, int parent, int& total, int k)
    {   // find sum of distance to each node and sum it
        total += k;
        for(auto i : adj[node])
        {
            if(i != parent)
                dfs(adj, i, node, total, k+1);
        }
    }
    void helper(vector<int>& nodeCount, int index, vector<int>& result, int parent, vector<vector<int>>& adj, int n)
    {
        // calculate sum of distance from top to botom 
        // using sum of node = sum of parent + (number of nodes under parent) - (nodes under child) - (nodes under child)
        if(parent != -1)
        {
            int nodesUnderCild = 0;
            for(auto x : adj[index]) if(x != parent) nodesUnderCild += nodeCount[x] + 1;
            result[index] = result[parent] + (n - nodesUnderCild - 2) - nodesUnderCild;
        }
        
        for(auto x : adj[index]) if(x != parent) helper(nodeCount, x, result, index, adj, n);
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> nodeCount(n, 0), result(n, 0);
        int total = 0;

        for(auto i : edges)
        {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        countHelper(0, adj, nodeCount, -1);
        dfs(adj, 0, -1, total, 0); // find sum of distance from node 0 to all nodes
        result[0] = total;

        helper(nodeCount, 0, result, -1, adj, n);

        return result;
    }
};