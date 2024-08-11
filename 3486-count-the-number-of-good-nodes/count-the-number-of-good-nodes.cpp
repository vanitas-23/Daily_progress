
class Solution {
private:
    void sizeMake(vector<int> adj[], vector<int> sizeOf[], vector<bool>& visit, int st, vector<int>& numberOfChild) {
        visit[st] = true;
        numberOfChild[st]++;
        for (int i : adj[st]) {
            if (!visit[i]) {
                sizeMake(adj, sizeOf, visit, i, numberOfChild);
                numberOfChild[st] += numberOfChild[i];
                sizeOf[st].push_back(numberOfChild[i]);
            }
        }
    }

public:
    int countGoodNodes(vector<vector<int>>& edges) {
        int n = edges.size() + 1;

        vector<int> adj[n];
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> sizeOf[n];
        vector<int> numberOfChild(n, 0);
        vector<bool> visit(n, false);

        sizeMake(adj, sizeOf, visit, 0, numberOfChild);

        int re = 0;
        for (int i = 0; i < n; i++) {
            bool x = true;
            int size = sizeOf[i].size();
            for (int j = 0; j < size - 1; j++) {
                if (sizeOf[i][j] != sizeOf[i][j + 1]) {
                    x = false;
                    break;
                }
            }
            if (x) {
                re++;
            }
        }

        return re;
    }
};
