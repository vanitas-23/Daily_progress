class Solution {
private:
    int rows, cols;
    vector<vector<int>> status;
    const vector<int> DR = {-1, 1, 0, 0};
    const vector<int> DC = {0, 0, -1, 1};

    bool dfs(int r, int c, vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        if (grid1[r][c] != 1) {
            status[r][c] = -1;
            return false;
        }

        status[r][c] = 1;
        bool isSubIsland = true;

        for (int i = 0; i < 4; i++) {
            int nr = r + DR[i];
            int nc = c + DC[i];

            if (nr >= 0 && nr < rows && nc >= 0 && nc < cols) {
                if (status[nr][nc] == -1) {
                    status[r][c] = -1;
                    return false;
                }
                if (status[nr][nc] == 1) continue;
                if (grid2[nr][nc] == 1 && !dfs(nr, nc, grid1, grid2)) {
                    status[r][c] = -1;
                    return false;
                }
            }
        }

        return isSubIsland;
    }

public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        rows = grid1.size();
        cols = grid1[0].size();
        status = vector<vector<int>>(rows, vector<int>(cols, 0));
        int subIslandCount = 0;

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (status[r][c] == 0 && grid2[r][c] == 1) {
                    if (dfs(r, c, grid1, grid2)) {
                        subIslandCount++;
                    }
                }
            }
        }

        return subIslandCount;
    }
};

static const auto speedup = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();