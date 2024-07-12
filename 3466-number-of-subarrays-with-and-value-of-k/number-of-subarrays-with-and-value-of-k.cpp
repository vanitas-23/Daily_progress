class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
    unordered_map<int, int> cnt;
    long long res = 0;
    for (int n : nums) {
        unordered_map<int, int> cnt1;
        if ((k & n) == k) {
            cnt1[n] = 1;
            for (auto [v, count] : cnt)
                cnt1[v & n] += count;
            res += cnt1[k];
        }
        swap(cnt, cnt1);
    }
    return res;
} 
};