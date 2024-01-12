class Solution {
public:
   
    bool halvesAreAlike(string s) {
        int n = s.size(), k = (n >> 1);
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

        
        int countA = 0;
        for (int i = 0; i < k; i++) countA += vowels.count(s[i]);
        int countB = 0;
        for (int i = k; i < n; i++) countB += vowels.count(s[i]);
        return (countA == countB);
    }
};