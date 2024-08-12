class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto i:nums)
        mp[i]++;
        int dom=0;
        int frq=0;
        for(auto i:mp)
        {
            if(i.second>frq)
            {
                frq=i.second;
                dom=i.first;
            }
        }
        int n=nums.size();
        mp.clear();
        int i=0;
        while(i<n)
        {
            mp[nums[i]]++;
            if(mp[dom]*2>(i+1) && (frq-mp[dom])*2>(n-i-1))
            return i;
            i++;
        }
        return -1;
    }
};