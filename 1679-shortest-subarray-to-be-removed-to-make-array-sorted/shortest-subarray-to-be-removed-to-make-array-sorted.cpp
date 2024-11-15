class Solution {
public:
    bool f(int mid, int n, vector<int>& pre, vector<int>& post,
           vector<int>& nums) {
        for (int i = 0; i <= n - mid; i++) {
            if (i == 0) {
                if (i + mid < n && post[i + mid])
                    return true;
            } else if (i == n - mid) {
                if (i - 1 >= 0 && pre[i - 1])
                    return true;
            } else {
                if (i - 1 >= 0 && i + mid < n && pre[i - 1] && post[i + mid] &&
                    nums[i - 1] <= nums[i + mid])
                    return true;
            }
        }
        return false;
    }

    int findLengthOfShortestSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n);
        vector<int> post(n);
        pre[0] = 1;
        post[n - 1] = 1;
        for (int i = 1; i < n; i++) {
            if (pre[i - 1] == 0)
                pre[i] = 0;
            else if (nums[i] >= nums[i - 1])
                pre[i] = 1;
            else
                pre[i] = 0;
        }
        for (int i = n - 2; i >= 0; i--) {
            if (post[i + 1] == 0)
                post[i] = 0;
            else if (nums[i] <= nums[i + 1])
                post[i] = 1;
            else
                post[i] = 0;
        }
        int l = 0;

        int r = n - 1;
        int ans = r;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (f(mid, n, pre, post, nums)) {
                ans = mid;
                r = mid - 1;
            } else
                l = mid + 1;
        }
        return ans;
    }
};