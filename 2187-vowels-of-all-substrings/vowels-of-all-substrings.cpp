class Solution {
public:
    long long countVowels(string word) {
        long long ans=0;
        int n=word.size();
        for(int i=0;i<n;i++)
        {
            if((word[i]=='a') || (word[i]=='e') || (word[i]=='i') || (word[i]=='o')|| (word[i]=='u'))
            {
                ans+=(i+1)*1ll*(n-i);
            }
        }
        return ans;
    }
};