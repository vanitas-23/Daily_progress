class Solution {
public:
    int longestPalindrome(string s) {
        map<char,int>mp;
        for(char c:s)
        mp[c]++;
        int ans=0;
        for(auto i:mp)
        {
            if(i.second%2==0)
            ans+=i.second;
            else if(i.second>1)
            ans+=i.second-1;
            
        }
        if(ans==s.size())
        return ans;
        return 1+ans;
    }
};