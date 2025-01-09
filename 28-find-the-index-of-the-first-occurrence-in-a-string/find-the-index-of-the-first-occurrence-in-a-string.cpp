class Solution {
public:
    vector<int> computeLPS(string& pattern) {
        int m = pattern.length();
        vector<int> lps(m, 0);

        int len = 0;
        int i = 1;

        while (i < m) {
            if (pattern[i] == pattern[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }

        return lps;
    }

    vector<int> searchKMP(string& s, string& a) {
        vector<int> result;
        int n = s.length();
        int m = a.length();
        vector<int> lps = computeLPS(a);

        int i = 0;
        int j = 0;

        while (i < n) {
            if (a[j] == s[i]) {
                j++;
                i++;
            }

            if (j == m) {
                result.push_back(i - j);
                j = lps[j - 1];
                
            } else if (i < n && a[j] != s[i]) {
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }

        return result;
    }

    int strStr(string h, string n) {
        auto x=searchKMP(h,n);
        return x.size()>0?x[0]:-1;
    }
};