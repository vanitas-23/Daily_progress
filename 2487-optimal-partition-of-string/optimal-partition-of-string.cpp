class Solution {
public:
    int partitionString(string s) {
        vector<int>freq(26);
        int i=0;
        int j=0;
        int n=s.size();
        int ans=0;
        while(j<n){
            freq[s[j]-'a']++;
            if(freq[s[j]-'a']>1)
            {
                ans++;
                while(i<j)
                freq[s[i++]-'a']--;
            }
            j++;
        }
        return ans+1;
    }
};