#define ll long long
class Solution {
public:
    ll lcm(ll a, ll b) {
        return a*b/__gcd(a,b);
    }
    int nthUglyNumber(int n, int a, int b, int c) {
        ll l=0;
        ll h=1e18;
        ll ans=0;
        while(l<=h)
        {
            ll mid=(l+h)/2;
            ll num = mid/a + mid/b + mid/c - mid/lcm(a,b) - mid/lcm(b,c) - mid/lcm(a,c) + mid/lcm(a,lcm(b,c));
            if(num<n)
            l=mid+1;
            else
            h=mid-1;
        }
        return l;
    }
};