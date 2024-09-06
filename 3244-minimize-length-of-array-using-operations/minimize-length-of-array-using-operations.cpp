class Solution {
public:
    int minimumArrayLength(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int min_v = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            min_v = min(min_v, nums[i]);
        } 
        int cnt = count(nums.begin(), nums.end(), min_v);  
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % min_v != 0) {
                return 1;
            }
        }
        return (cnt+1)/2;
    }
};