class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int m = queries.size();
        vector<int> arr(m);
        iota(arr.begin(), arr.end(), 0);
        sort(arr.begin(), arr.end(), [&](int a, int b) {
            return queries[a] < queries[b];
        });

        vector<int> dx = {1, -1, 0, 0};
        vector<int> dy = {0, 0, 1, -1};
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        pq.push({grid[0][0], {0, 0}});
        vector<vector<bool>> vis(grid.size(), vector<bool>(grid[0].size(), false));
        vis[0][0] = true;
        
        vector<int> ans(m);
        int past = 0;

        for (int i : arr) {
            int curr = past;
            while (!pq.empty() && pq.top().first < queries[i]) {
                auto [val, p] = pq.top();
                pq.pop();
                int x = p.first, y = p.second;
                curr++;

                for (int k = 0; k < 4; k++) {
                    int r = x + dx[k], c = y + dy[k];
                    if (r >= 0 && r < grid.size() && c >= 0 && c < grid[0].size() && !vis[r][c]) {
                        pq.push({grid[r][c], {r, c}});
                        vis[r][c] = true;
                    }
                }
            }
            ans[i] = curr;
            past = curr;
        }
        return ans;
    }
};
