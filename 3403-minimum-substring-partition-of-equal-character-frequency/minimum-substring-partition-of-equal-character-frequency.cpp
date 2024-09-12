class Solution {
public:
    unordered_map<int, int> dp;
    int solve(string& s, int idx) {
        if(idx == s.length()) return 0;
        if (dp.find(idx) != dp.end()) return dp[idx];
        
        int ans = 1e9;
        unordered_map<char, int> f; 
        for(int i=idx;i<s.size();i++) {
            f[s[i]]++;
            int mn = INT_MAX, mx = INT_MIN;
            
            for(auto p : f) {
                mn = min(mn, p.second);
                mx = max(mx, p.second);
            }

            if(mn == mx) {
                int res = solve(s, i + 1);
                if(res != -1) {
                    ans = min(ans, 1 + res);
                }
            }
        }
        dp[idx] = (ans == 1e9) ? -1 : ans;
        return dp[idx];
    }

    int minimumSubstringsInPartition(string s) {
        dp.clear();
        return solve(s, 0);
    }
};