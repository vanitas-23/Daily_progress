class Solution {
public:
    long long f(int target, int n, vector<int>& nums) {
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            int it = upper_bound(nums.begin() + i + 1, nums.end(),
                                 target - nums[i]) -
                     nums.begin();
            ans += (it - i - 1);
        }
        return ans;
    }

    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        return f(upper, n, nums) - f(lower - 1, n, nums);
    }
};
