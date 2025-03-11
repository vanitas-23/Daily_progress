class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        map<int,int>mp;
        int i=0;
        int ans=0;
        int j=0;
        while(j<n)
        {
            mp[s[j]-'a']++;
            while(mp.size()==3)
            {
                ans+=(n-j);
                mp[s[i]-'a']--;
                if(mp[s[i]-'a']==0)
                mp.erase(s[i]-'a');
                i++;
            }
            j++;
        }
        return ans;
    }
};