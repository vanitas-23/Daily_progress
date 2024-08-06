class Solution {
public:
    unordered_map<char,int>mp;
    int minimumPushes(string word) {
        
        for(char c:word)
            mp[c]++;
        
        vector<char>req;
        for(auto i:mp)
            req.push_back(i.first);
        
        sort(req.begin(),req.end(),[&](char a, char b) {
        return mp[a]>mp[b];
    });
        int res=0;
        int i=0;
        int cr=2;
        for(char c:req)
        {
            res+=mp[c]*(i+1);
            
            if(cr<9)
                cr++;
            else{
            cr=2;
            i++;
            }
                
        }
        return res;
    }
};