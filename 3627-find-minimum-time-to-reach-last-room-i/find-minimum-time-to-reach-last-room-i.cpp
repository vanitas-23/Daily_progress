#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int minTimeToReach(vector<vector<int>>& mt) {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
        int n = mt.size();
        int m = mt[0].size();
        q.push({0, {0, 0}}); 
        
        vector<vector<int>> vis(n, vector<int>(m, -1));
        vector<pair<int, int>> dir = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        
        vis[0][0] = 0;
        
        while (!q.empty()) {
            auto x = q.top();
            q.pop();
            int curr_time = x.first;
            int r = x.second.first;
            int c = x.second.second;
            
            for (int i = 0; i < 4; i++) {
                int nr = r + dir[i].first;
                int nc = c + dir[i].second;
                
                if (nr >= 0 && nr < n && nc >= 0 && nc < m && vis[nr][nc] == -1) {
                    int tm = mt[nr][nc];
                    int new_time;
                    
                    if (curr_time + 1 == tm) {
                        new_time = tm + 1;
                    } else if (tm > curr_time + 1) {
                        new_time = tm + 1;
                    } else {
                        new_time = curr_time + 1;
                    }
                    
                    q.push({new_time, {nr, nc}});
                    vis[nr][nc] = new_time;
                }
            }
        }
        
        return vis[n-1][m-1];
    }
};