class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,int>mp;
        for(auto i:matches){
        mp[i[1]]++;
        mp[i[0]]+=0;}

        vector<vector<int>>res(2);
        for(auto i:mp){
        if(i.second==0)
        res[0].push_back(i.first);
        else if(i.second==1)
        res[1].push_back(i.first);
    }
        return res;
    }
};