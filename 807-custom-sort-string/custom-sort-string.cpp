class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char,int>mp;
        for(int i=0;i<order.size();i++)
        mp[order[i]]=i+1;

         auto cmp = [&](char a, char b) {
         if(mp[a]==mp[b])
         return false;

         return mp[a]<mp[b];
    };
    sort(s.begin(),s.end(),cmp);
    return s;
    }
};