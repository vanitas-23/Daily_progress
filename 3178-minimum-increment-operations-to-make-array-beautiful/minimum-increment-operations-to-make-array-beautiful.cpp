#define ll long long
class Solution {
public:
    long long minIncrementOperations(vector<int>& nums, int k) {
        int n = nums.size();
        vector<ll> dp(n + 3, 0);
        for (int i = n - 3; i >= 0; i--) {
            ll a1 = max(0, k - nums[i]) + dp[i + 1];
            ll a2 = max(0, k - nums[i + 1]) + dp[i + 2];
            ll a3 = max(0, k - nums[i + 2]) + dp[i + 3];
            dp[i] = min({a1, a2, a3});
        }
        return dp[0];
    }
};
