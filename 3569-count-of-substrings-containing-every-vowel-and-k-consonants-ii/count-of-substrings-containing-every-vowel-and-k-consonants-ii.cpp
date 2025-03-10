#define ll long long
class Solution {
public:
    bool isV(char c)
    {
        return (c=='a') || (c=='e') || (c=='i') || (c=='o') || (c=='u');
    }
    ll f(string word,int k)
    {
        int n=word.size();
        int con=0;
        ll ans=0;
        int i=0;
        int j=0;
        unordered_map<char,int>mp;
        while(j<n)
        {
            if(isV(word[j]))
            mp[word[j]]++;
            else
            con++;
            while(mp.size()==5 && con>=k)
            {
                ans+=(n-j);
                if(mp.find(word[i])!=mp.end())
                {
                    mp[word[i]]--;
                    if(mp[word[i]]==0)
                    mp.erase(word[i]);
                }
                else
                con--;
                i++;
            }
            j++;
        }
        return ans;
    }
    ll countOfSubstrings(string word, int k) {
        return f(word,k)-f(word,k+1);
    }
};