int MOD = 1e9 + 7;
int dp[10001][7][7];
class Solution {
public:
    int f(int i, int n, vector<vector<int>>& mp, int last, int plast) {
        if (i == n) return 1;
        if (dp[i][last][plast] != -1) return dp[i][last][plast];

        int ans = 0;
        for (auto j : mp[last]) {
            if (j == plast) continue;
            ans = (ans + f(i + 1, n, mp, j, last)) % MOD;
        }
        return dp[i][last][plast] = ans;
    }

    int distinctSequences(int n) {
        vector<vector<int>> mp = {
            {}, {2, 3, 4, 5, 6}, {1, 3, 5}, {1, 2, 4, 5}, 
            {1, 3, 5}, {1, 2, 3, 4, 6}, {1, 5}
        };

        memset(dp, -1, sizeof(dp));
        int ans = 0;
        for (int i = 1; i <= 6; i++) {
            ans = (ans + f(1, n, mp, i, 0)) % MOD;
        }
        return ans;
    }
};
