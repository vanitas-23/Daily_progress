#define ll long long
const int MOD = 1e9 + 7;
class Solution {
public:
    vector<vector<int>> generate(int n) {
        const int MAXN = 31;
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

        vector<vector<int>> ans(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++)
                ans[i].push_back(nCr(i, j));
        }
        return ans;
    }
};