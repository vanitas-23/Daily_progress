class Solution {
public:
    int firstUniqChar(string s) {
        int freq[26] = {0};
        
        // count frequency of each character in s
        for(char c : s) {
            freq[c - 'a']++;
        }
        
        // find first character in s that has frequency 1
        for(int i = 0; i < s.length(); i++) {
            if(freq[s[i] - 'a'] == 1) {
                return i;
            }
        }
        
        return -1;
    }
};