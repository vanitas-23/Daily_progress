#define ll long long
class Solution {
public:
    unordered_map<int, int> mp;
    
    ll f(int i, int n, vector<int>& arr, vector<ll>& dp, vector<int>& nex) {
        if (i >= n)
            return 0;
        if (dp[i] != -1)
            return dp[i];
        ll nt = f(i + 1, n, arr, dp, nex);
        ll t = 0;
        t = mp[arr[i]] * 1ll * arr[i] + f(nex[i], n, arr, dp, nex);
        return dp[i] = max(t, nt);
    }
    
    ll maximumTotalDamage(vector<int>& power) {
        for (int i : power)
            mp[i]++;
        set<int> st(power.begin(), power.end());
        vector<int> arr(st.begin(), st.end());
        int n = arr.size();
        vector<int> nex;
        for (int i = 0; i < n; i++)
            nex.push_back(upper_bound(arr.begin(), arr.end(), arr[i] + 2) - arr.begin());
        vector<ll> dp(n, -1);
        return f(0, n, arr, dp, nex);
    }
};