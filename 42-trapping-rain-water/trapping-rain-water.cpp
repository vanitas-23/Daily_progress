class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        int l = 0, r = height.size() - 1;
        int lmax = height[l], rmax = height[r];

        while (l < r) {
            if (lmax < rmax) {
                l++;
                lmax = max(lmax, height[l]);
                ans += lmax - height[l];
            } else {
                r--;
                rmax = max(rmax, height[r]);
                ans += rmax - height[r];
            }
        }

        return ans;
    }
};