class Solution {
public:
    int minSteps(string s, string t) {
        vector<int>arr(26);
        int an=0;
        for(char c:s)
        arr[c-'a']++;
        for(char c:t)
        arr[c-'a']--;
        for(int i=0;i<26;i++)
        an+=abs(arr[i]);

        return an/2;
    }      
};