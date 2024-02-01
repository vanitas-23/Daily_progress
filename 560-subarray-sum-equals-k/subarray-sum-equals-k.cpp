class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int ans=0;
        int sm=0;
        for(int i:nums)
        {
            sm+=i;
            if(sm==k)
            ans++;
            if(mp.find(sm-k)!=mp.end())
            ans+=mp[sm-k];

            mp[sm]++;
        }
        return ans;
    }
};