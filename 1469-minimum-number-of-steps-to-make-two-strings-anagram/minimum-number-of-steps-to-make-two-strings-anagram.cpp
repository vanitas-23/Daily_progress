class Solution {
public:
    int minSteps(string s, string t) {
        vector<int>arr(26);
        vector<int>brr(26);
        int an=0;
        for(char c:s)
        arr[c-'a']++;
        for(char c:t)
        brr[c-'a']++;
        for(int i=0;i<26;i++)
        if(arr[i]!=brr[i])
        an+=abs(arr[i]-brr[i]);

        return an/2;
    }      
};