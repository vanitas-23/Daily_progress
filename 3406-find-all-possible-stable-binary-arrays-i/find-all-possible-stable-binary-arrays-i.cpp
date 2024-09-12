class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        ios::sync_with_stdio(false);
        vector<vector<int>> dp0(zero + 1, vector<int>(one + 1, 0));
        vector<vector<int>> dp1(zero + 1, vector<int>(one + 1, 0));
        vector<int> dp0sum(zero + 1, 0);
        vector<int> dp1sum(one + 1, 0);
        int mod = 1e9 + 7;

        for (int j = 0; j <= one; j++) {
            if (j <= limit) {
                dp1[0][j] = 1;
            }
            dp1sum[j] = dp1[0][j];
        }

        for (int i = 1; i <= zero; i++) {
            if (i <= limit) {
                dp0[i][0] = 1;
            }
            dp0sum[i] = dp0[i][0];

            for (int j = 1; j <= one; ++j) {
                dp0[i][j] = dp1sum[j];
                dp1[i][j] = dp0sum[i];
                dp0sum[i] = (dp0sum[i] + dp0[i][j]) % mod;
                if (j >= limit) {
                    dp0sum[i] = (dp0sum[i] - dp0[i][j - limit] + mod) % mod;
                }
                dp1sum[j] = (dp1sum[j] + dp1[i][j]) % mod;
                if (i >= limit) {
                    dp1sum[j] = (dp1sum[j] - dp1[i - limit][j] + mod) % mod;
                }
            }
        }
        return (dp0[zero][one] + dp1[zero][one]) % mod;
    }
};