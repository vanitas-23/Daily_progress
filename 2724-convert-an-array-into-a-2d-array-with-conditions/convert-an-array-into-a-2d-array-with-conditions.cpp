class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i:nums)
        mp[i]++;
        int mx=0;
        for(auto i:mp)
        mx=max(mx,i.second);
       // vector<unordered_set<int>>ch;
        vector<vector<int>>res(mx);
        for(auto i:mp){
            for(int j=0;j<i.second;j++)
            res[j].push_back(i.first);
        }
        return res;
    }
};