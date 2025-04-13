class Solution {
public:
long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
    int countGoodNumbers(long long n) {
        const int m=1e9+7;
        if(n%2)
        return 5*binpow(20,n>>1,m)%m;
        return binpow(20,n>>1,m)%m;
    }
};