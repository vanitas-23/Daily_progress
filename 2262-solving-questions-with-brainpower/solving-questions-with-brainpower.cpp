#define ll long long 
class Solution {
public:
    long long mostPoints(vector<vector<int>>& q) {
        int n = q.size();
        vector<ll> dp(n);
        for (int i = n - 1; i >= 0; i--) {
            ll pick = q[i][0] + ((i + q[i][1] + 1 < n) ? dp[i + q[i][1] + 1] : 0);
            ll npick = (i == n - 1) ? 0 : dp[i + 1];
            dp[i] = max(pick, npick);
        }
        return dp[0];
    }
};
