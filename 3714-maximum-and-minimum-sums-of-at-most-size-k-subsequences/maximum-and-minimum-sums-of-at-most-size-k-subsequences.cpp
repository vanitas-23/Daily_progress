#define ll long long
const int MOD = 1e9 + 7;

class Solution {
public:
    int minMaxSums(vector<int>& nums, int k) {
        const int MAXN = 100001;
        sort(nums.begin(), nums.end());
        
        // Precompute factorials and modular inverses
        vector<ll> fact(MAXN, 1), invFact(MAXN, 1);
        for (int i = 2; i < MAXN; ++i) {
            fact[i] = fact[i - 1] * i % MOD;
        }
        invFact[MAXN - 1] = modExp(fact[MAXN - 1], MOD - 2, MOD);
        for (int i = MAXN - 2; i >= 1; --i) {
            invFact[i] = invFact[i + 1] * (i + 1) % MOD;
        }

        // Lambda function for nCr
        auto nCr = [&](int n, int r) {
            if (r < 0 || r > n) return 0LL;
            return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
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

private:
    ll modExp(ll base, ll exp, ll mod) {
        ll result = 1;
        while (exp > 0) {
            if (exp % 2 == 1) {
                result = result * base % mod;
            }
            base = base * base % mod;
            exp /= 2;
        }
        return result;
    }
};
