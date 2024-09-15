class Solution {
public:
    int findTheLongestSubstring(string s) {
        int ans=0;
        map<int,int>mp;
        int mask=0;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            if(s[i]=='a')
            mask^=1;
            else if(s[i]=='e')
            mask^=2;
            else if(s[i]=='i')
            mask^=4;
            else if(s[i]=='o')
            mask^=8;
            else if(s[i]=='u')
            mask^=16;
            if(mask==0)
            ans=i+1;
            else if(mp.find(mask)!=mp.end())
            ans=max(ans,i-mp[mask]);
            else
            mp[mask]=i;
        }
        return ans;
    }
};