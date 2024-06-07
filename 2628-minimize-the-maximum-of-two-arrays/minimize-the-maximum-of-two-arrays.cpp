#define ll long long

class Solution {
public:
    ll findLCM(ll a, ll b) {
        return (1ll * a * b) / findGCD(a, b);
    }

    ll findGCD(ll a, ll b) {
        return (b == 0) ? a : findGCD(b, a % b);
    }

    bool isValidSet(ll total, int& d1, int& d2, int& c1, int& c2) {
        ll common = total / lcm;
        ll excess1 = max(0ll, (total / d1 - common) - c2);
        ll excess2 = max(0ll, (total / d2 - common) - c1);
        return (total - common - excess1 - excess2) >= c1 + c2;
    }

    ll lcm;

    int minimizeSet(int div1, int div2, int count1, int count2) {
        ll low = count1 + count2, high = INT_MAX;
        lcm = findLCM(div1, div2);

        while (low < high) {
            ll mid = (low + high) >> 1;
            bool valid = isValidSet(mid, div1, div2, count1, count2);

            if (valid)
                high = mid;
            else
                low = mid + 1;
        }

        return low;
    }
};