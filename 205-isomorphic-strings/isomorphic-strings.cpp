class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size()!=t.size())
        return false;
        int mp[200]={0};
        int zp[200]={0};
        for(int i=0;i<s.size();i++){
            if(mp[s[i]]!=zp[t[i]])
            return false;
            mp[s[i]]=i+1;
            zp[t[i]]=i+1;
        }
        return true;
    }
};