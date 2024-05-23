class Solution {
public:
    int mod = 1e9 + 7;
    int dp[1004][1004];
    int solve(int x, int pd, int n, int d, int f) {
        if (pd > n)
            return 1;
        if (pd - x == f)
            return 0;
        if (dp[x][pd] != -1)
            return dp[x][pd];
        long long int ans = 0;
        if (pd - x < d)
            ans = solve(x, pd + 1, n, d, f);
        else
            ans = (solve(pd, pd + 1, n, d, f) % mod +
                   solve(x, pd + 1, n, d, f) % mod) %
                  mod;
        return dp[x][pd] = ans;
    }
    int peopleAwareOfSecret(int n, int delay, int forget) {
        memset(dp, -1, sizeof(dp));
        return solve(1, 1, n, delay, forget);
    }
};