class Solution {
public:
    bool isprime(int x) {
        if (x <= 1)
            return false;
        if (x == 2 || x == 3)
            return true;
        if (x % 2 == 0 || x % 3 == 0)
            return false;
        if ((x - 1) % 6 != 0 && (x + 1) % 6 != 0)
            return false;
        for (int i = 5; i * i <= x; i += 6) {
            if (x % i == 0 || x % (i + 2) == 0)
                return false;
        }
        return true;
    }
    vector<int> closestPrimes(int left, int right) {
        vector<int> prs;
        for (int i = left; i <= right; i++) {
            if (isprime(i)) {
                if (prs.size() && i - prs.back() <= 2)
                    return {prs.back(), i};
                prs.push_back(i);
            }
        }
        if (prs.size() < 2)
            return {-1, -1};
        vector<int> ans(2);
        int mn = 1e9;
        for (int i = 1; i < prs.size(); i++) {
            if (prs[i] - prs[i - 1] < mn) {
                mn = prs[i] - prs[i - 1];
                ans[0] = prs[i - 1];
                ans[1] = prs[i];
            }
        }
        return ans;
    }
};