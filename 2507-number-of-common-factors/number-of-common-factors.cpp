class Solution {
public:
    int noF(int n){
            int count = 0;
    for (int i = 1; i <= n; ++i) {
        if (n % i == 0) {
            count++;
        }
    }
    return count;
    }
    int commonFactors(int a, int b) {
        int x=__gcd(a,b);
        return noF(x);
    }
};