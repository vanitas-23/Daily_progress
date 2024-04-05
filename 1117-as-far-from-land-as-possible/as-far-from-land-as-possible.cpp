int delRow[] = {0, 0, -1, 1};
int delCol[] = {1, -1, 0, 0};

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int n = grid.size();
        int m = grid[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                }
            }
        }

        int step = 0;

        while (!q.empty()) {
            step++;

            int size = q.size(); // Get the current size of the queue

            for (int k = 0; k < size; k++) {
                auto it = q.front();
                q.pop(); // Pop the front element

                int row = it.first;
                int col = it.second;

                for (int i = 0; i < 4; i++) {
                    int Nrow = delRow[i] + row;
                    int Ncol = delCol[i] + col;

                    if (Nrow >= 0 && Nrow < n && Ncol >= 0 && Ncol < m &&
                        grid[Nrow][Ncol] == 0) {
                        grid[Nrow][Ncol] = step;
                        q.push({Nrow, Ncol}); // Push the new cell to the queue
                    }
                }
            }
        }

        return step == 1 ? -1 : step - 1;
    }
};