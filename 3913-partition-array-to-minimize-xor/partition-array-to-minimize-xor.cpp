class Solution {
public:
    int solve(int ind, int k, int currxor, vector<int>& nums, vector<vector<int>>& dp) {
        if (ind == nums.size()) {
            if (k == 0) return 0;
            else return -1e9;
        }
        if (k <= 0) return -1e9;
        if (dp[ind][k] != -1) return dp[ind][k];
        int ans = INT_MAX;
        for (int i = ind; i < nums.size(); i++) {
            currxor = currxor ^ nums[i];
            int curr = solve(i + 1, k - 1, 0, nums, dp);
            if (curr < 0) continue;
            ans = min(ans, max(currxor, curr));
        }
        return dp[ind][k] = ans == INT_MAX ? -1e9 : ans;
    }
    int minXor(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(k + 1, -1));
        solve(0, k, 0, nums, dp);
        return dp[0][k];
    }
};