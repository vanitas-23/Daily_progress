class Solution {
public:
    unordered_map<string, bool> mp;

    bool f(int i, int j, int n, string A, vector<vector<int>>& dp) {
        if (j == n - 1)
            return mp[A.substr(i, j - i + 1)];

        if (dp[i][j] != -1)
            return dp[i][j];

        string temp = A.substr(i, j - i + 1);
        if (mp[temp])
            return dp[i][j] =
                       (f(j + 1, j + 1, n, A, dp) | f(i, j + 1, n, A, dp));

        return dp[i][j] = f(i, j + 1, n, A, dp);
    }
    bool wordBreak(string A, vector<string>& B) {
        for (auto i : B)
            mp[i] = 1;

        int n = A.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));

        return f(0, 0, n, A, dp);
    }
};