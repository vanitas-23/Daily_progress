class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        vector<int>mp(26,-1);
        int ans=-1;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(mp[s[i]-'a']==-1)
            mp[s[i]-'a']=i;

            else
            ans=max(ans,i-mp[s[i]-'a']+1);
        }

        return ans==-1?-1:ans-2;
    }
};