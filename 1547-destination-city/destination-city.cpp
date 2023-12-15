class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string,int>mp;
        for(auto i:paths)
        mp[i[0]]++;
        for(auto i:paths)
        if(mp.find(i[1])==mp.end())
        return i[1];
        return "";
    }
};