#define ll long long
class Solution {
public:
    
   int dfs(int i, int p, int s, int ss, vector<vector<pair<int, int>>> &al) {
    int res = s % ss == 0;
    for (auto [j, w] : al[i])
        if (j != p)
            res += dfs(j, i, s + w, ss, al);
    return res;
}
vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges, int signalSpeed) {
    int n = edges.size() + 1;
    vector<vector<pair<int, int>>> al(n);
    vector<int> res(n);
    for (const auto &e : edges) {
        al[e[0]].push_back({e[1], e[2]});
        al[e[1]].push_back({e[0], e[2]});
    }
    for (int i = 0; i < n; ++i) {
        int cnt = 0;
        for (auto [j, w] : al[i]) {
            int cnt_j = dfs(j, i, w, signalSpeed, al);
            res[i] += cnt * cnt_j;
            cnt += cnt_j;
        }            
    }            
    return res;
}
};