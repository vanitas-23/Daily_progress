class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& mf, vector<int>& mt) {
        map<int,int>mp;
        for(int i:nums)
        mp[i]++;
        int n=mf.size();
        for(int i=0;i<n;i++){
            if(mt[i]==mf[i])
            continue;  
            mp[mt[i]]+=mf[i];
            mp.erase(mf[i]);
            
        }
        vector<int>res;
        for(auto i:mp)
        res.push_back(i.first);

        return res;
    }
};