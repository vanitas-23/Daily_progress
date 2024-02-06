class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>res;
        map<vector<int>,vector<string>>mp;
        for(auto i:strs)
        {
            vector<int>arr(26);
            for(char c:i)
            arr[c-'a']++;
            mp[arr].push_back(i);
        }
        for(auto i:mp)
        res.push_back(i.second);
        return res;
    }
};