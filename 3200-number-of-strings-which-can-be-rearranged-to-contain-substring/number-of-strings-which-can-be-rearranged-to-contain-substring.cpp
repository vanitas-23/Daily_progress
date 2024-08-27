typedef long long int ll;

const int MOD = 1e9+7;

class Solution {
    
    ll FastPower (ll a, ll b) {
        ll ans = 1;
        while (b) {
            if (b&1) ans = (ans * a) % MOD;
            a = (a * a) % MOD;
            b /= 2;
        }
        return ans;
    }
    
public:
    int stringCount(int n) {
        return (
            FastPower(26, n)
            -
            (
                (FastPower(25, n-1) * (n + 75)) % MOD 
                -
                (FastPower(24, n-1) * (n*2 + 72)) % MOD
                + 
                (FastPower(23, n-1) * (n + 23)) % MOD
                + MOD
            ) % MOD
            + 
            MOD
        ) % MOD;
    }
};