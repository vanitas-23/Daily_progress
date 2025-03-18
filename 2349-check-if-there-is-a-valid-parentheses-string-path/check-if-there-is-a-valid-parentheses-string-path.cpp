class Solution {
public:
    vector<vector<vector<int>>> dp;
    vector<vector<char>> grid;
    int n, m;

    bool f(int i, int j, int curr) {
        if (grid[i][j] == '(')
            curr++;
        else
            curr--;

        if (curr < 0) return false;
        if (i == n - 1 && j == m - 1) return curr == 0;
        if (dp[i][j][curr] != -1) return dp[i][j][curr];

        bool ans = false;
        if (i + 1 < n) ans |= f(i + 1, j, curr);
        if (j + 1 < m) ans |= f(i, j + 1, curr);

        return dp[i][j][curr] = ans;
    }

    bool hasValidPath(vector<vector<char>>& inputGrid) {
        grid = inputGrid;
        n = grid.size();
        m = grid[0].size();
        if((n+m-1)%2)
        return false;
        dp.assign(n, vector<vector<int>>(m, vector<int>(n + m, -1)));
        return f(0, 0, 0);
    }
};
