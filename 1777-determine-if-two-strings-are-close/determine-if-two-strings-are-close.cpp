class Solution {
public:
    bool closeStrings(string word1, string word2) {
        
        vector<int>arr(26);
        vector<int>brr(26);
        for(char c:word1)
        arr[c-'a']++;
        for(char c:word2)
        
        brr[c-'a']++;
         for (int i = 0; i < 26; i++) 
            if ((arr[i] == 0 && brr[i] != 0) || (arr[i] != 0 && brr[i] == 0)) 
                return false;
            
        
        sort(arr.begin(),arr.end());
        sort(brr.begin(),brr.end());
        return arr==brr;
    }
};