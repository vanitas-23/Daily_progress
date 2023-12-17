class Solution {
public:
    int partitionString(string s) {
        int feq[26] = {0};
        int ch, n = s.length();
        int l, r, part = 1;
        for(l = r = 0; r < n; r++) {
            ch = s[r] - 'a';
            feq[ch]++;
            if(feq[ch] > 1) {
                part++;
                while(l < r)
                    feq[s[l++] - 'a']--;
            }
        }
        return part;     
    }
};