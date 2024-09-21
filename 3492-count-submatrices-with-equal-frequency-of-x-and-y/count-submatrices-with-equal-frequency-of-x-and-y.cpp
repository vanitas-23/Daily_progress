class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> preXR(n, vector<int>(m));
        vector<vector<int>> preYR(n, vector<int>(m));
        vector<vector<int>> preXC(n, vector<int>(m));
        vector<vector<int>> preYC(n, vector<int>(m));
        vector<vector<int>> reqqX(n, vector<int>(m));
        vector<vector<int>> reqqY(n, vector<int>(m));
        
        for (int i = 0; i < n; i++) {
            if (grid[i][0] == 'X')
                preXR[i][0] = 1;
            if (grid[i][0] == 'Y')
                preYR[i][0] = 1;
            for (int j = 1; j < m; j++) {
                if (grid[i][j] == 'X')
                    preXR[i][j] = 1 + preXR[i][j - 1];
                else
                    preXR[i][j] = preXR[i][j - 1];
                if (grid[i][j] == 'Y')
                    preYR[i][j] = 1 + preYR[i][j - 1];
                else
                    preYR[i][j] = preYR[i][j - 1];
            }
        }

        for (int j = 0; j < m; j++) {
            if (grid[0][j] == 'X')
                preXC[0][j] = 1;
            if (grid[0][j] == 'Y')
                preYC[0][j] = 1;
            for (int i = 1; i < n; i++) {
                if (grid[i][j] == 'X')
                    preXC[i][j] = 1 + preXC[i - 1][j];
                else
                    preXC[i][j] = preXC[i - 1][j];
                if (grid[i][j] == 'Y')
                    preYC[i][j] = 1 + preYC[i - 1][j];
                else
                    preYC[i][j] = preYC[i - 1][j];
            }
        }

        int ans = 0;
        
        for (int i = 0; i < n; i++) {
            reqqX[i][0] = preXC[i][0];
            reqqY[i][0] = preYC[i][0];
            if (reqqX[i][0] > 0 && reqqX[i][0] == reqqY[i][0])
                ans++;
        }

        for (int j = 0; j < m; j++) {
            reqqX[0][j] = preXR[0][j];
            reqqY[0][j] = preYR[0][j];
            if (reqqX[0][j] > 0 && reqqX[0][j] == reqqY[0][j])
                ans++;
        }

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                reqqX[i][j] = reqqX[i - 1][j - 1] + preXR[i][j] + preXC[i][j] - (grid[i][j] == 'X');
                reqqY[i][j] = reqqY[i - 1][j - 1] + preYC[i][j] + preYR[i][j] - (grid[i][j] == 'Y');
                if (reqqX[i][j] > 0 && reqqX[i][j] == reqqY[i][j])
                    ans++;
            }
        }

        return ans;
    }
};
