class Solution {
public:
    int maximizeWin(vector<int>& prizePositions, int k) {
        int res = 0, n = prizePositions.size(), j = 0;
        vector<int> dp(n + 1, 0);

        for (int i = 0; i < n; ++i) {
            while (prizePositions[i] - prizePositions[j] > k)
                ++j;
            dp[i + 1] = max(dp[i], i - j + 1);
            res =max(res, i - j + 1 + dp[j]);
        }
        return res;
    }
};