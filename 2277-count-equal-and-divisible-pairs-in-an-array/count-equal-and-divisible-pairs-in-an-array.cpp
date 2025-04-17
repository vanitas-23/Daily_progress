class Solution {
public:
    vector<int> f(int num) {
        vector<int> factors;
        for (int i = 1; i <= num; i++) {
            if (num % i == 0) {
                factors.push_back(i);
            }
        }
        return factors;
    }
    int countPairs(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < nums.size(); i++)
            mp[nums[i]].push_back(i);
        auto dv = f(k);
        int ans = 0;
        for (auto i : mp) {
            unordered_map<int, int> req;
            for (auto j : i.second) {
                ans += req[k / __gcd(j, k)];
                for (int d : dv)
                    if (j % d == 0)
                        req[d]++;
            }
        }
        return ans;
    }
};