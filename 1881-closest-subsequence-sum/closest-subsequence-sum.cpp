class Solution {
public:
    void f(int i, int n, vector<int>& arr, vector<int>& res, int sum) {
        if (i == n) {
            res.push_back(sum);
            return;
        }
        f(i + 1, n, arr, res, sum);
        f(i + 1, n, arr, res, sum + arr[i]);
    }

    int minAbsDifference(vector<int>& nums, int goal) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        vector<int> arr1, arr2;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (i < n / 2) arr1.push_back(nums[i]);
            else arr2.push_back(nums[i]);
        }

        vector<int> req1, req2;
        f(0, arr1.size(), arr1, req1, 0);
        f(0, arr2.size(), arr2, req2, 0);
        sort(req2.begin(), req2.end());

        int ans = INT_MAX;
        for (int sum1 : req1) {
            auto x = lower_bound(req2.begin(), req2.end(), goal - sum1);
            if (x != req2.end()) ans = min(ans, abs(goal - *x - sum1));
            if (x != req2.begin()) ans = min(ans, abs(goal - *prev(x) - sum1));
        }

        return ans;
    }
};
