class Solution {
public:
    string lcs(string a, string b) {
        int n = a.size(), m = b.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                dp[i][j] = a[i - 1] == b[j - 1]
                               ? dp[i - 1][j - 1] + 1
                               : max(dp[i - 1][j], dp[i][j - 1]);
        string res;
        int i = n, j = m;
        while (i > 0 && j > 0) {
            if (a[i - 1] == b[j - 1])
                res += a[i - 1], i--, j--;
            else if (dp[i - 1][j] > dp[i][j - 1])
                res+=a[i-1],i--;
            else
                res+=b[j-1],j--;
        }
        while (i > 0) res += a[--i];
        while (j > 0) res += b[--j];
        reverse(res.begin(), res.end());
        return res;
    }
    string shortestCommonSupersequence(string str1, string str2) {
        auto x = lcs(str1,str2);
        return x;
    }
};