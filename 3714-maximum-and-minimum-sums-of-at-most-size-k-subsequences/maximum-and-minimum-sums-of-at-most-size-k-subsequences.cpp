#define ll long long
const int MOD = 1e9 + 7;

class Solution {
public:
    int minMaxSums(vector<int>& nums, int k) {
        const int MAXN = 100001;
        sort(nums.begin(),nums.end());
        vector<long long> FS(MAXN, 1), IFS(MAXN, 1), invs(MAXN, 1);
        for (int i = 2; i < MAXN; ++i) {
            FS[i] = FS[i - 1] * i % MOD;
            invs[i] = MOD - MOD / i * invs[MOD % i] % MOD;
            IFS[i] = IFS[i - 1] * invs[i] % MOD;
        }
        auto nCr = [&](int n, int r) {
            if (r < 0 || r > n) {
                return 0LL;
            }
            return FS[n] * IFS[r] % MOD * IFS[n - r] % MOD;
        };
        int n = nums.size();
        ll ans = 2ll * accumulate(nums.begin(), nums.end(), 0ll);
        for (int i = 2; i <= k; i++) {
            for (int j = 0; j < n; j++) {
                int left = j;
                int right = n - 1 - j;
                ll x = nCr(left, i - 1);
                ll y = nCr(right, i - 1);
                ans = (ans % MOD + nums[j] * 1ll * (x + y) % MOD) % MOD;
            }
        }
        return ans % MOD;
    }
};