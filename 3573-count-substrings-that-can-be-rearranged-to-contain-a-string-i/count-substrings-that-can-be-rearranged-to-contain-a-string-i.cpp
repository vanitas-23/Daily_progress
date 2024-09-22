class Solution {
public:
    long long validSubstringCount(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        vector<int> target(26, 0);
        for (char it : word2) {
            target[it- 'a']++;
        }
        
        long long result = 0;
        vector<int> count(26, 0);
        int valid = 0;
        int left = 0;
        
        for (int right = 0; right < n; right++) {
            count[word1[right] - 'a']++;
            if (count[word1[right] - 'a'] <= target[word1[right] - 'a']) {
                valid++;
            }
            while (valid == m && left <= right) {
                result += n - right;
                count[word1[left] - 'a']--;
                if (count[word1[left] - 'a'] < target[word1[left] - 'a']) {
                    valid--;
                }
                left++;
            }
        }
        return result;
    }
};