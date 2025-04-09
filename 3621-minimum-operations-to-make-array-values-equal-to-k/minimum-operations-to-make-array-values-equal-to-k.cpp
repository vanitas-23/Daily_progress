class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        if(*min_element(nums.begin(),nums.end())<k)
        return -1;
        map<int,int>mp;
        for(auto i:nums)
        mp[i]++;
        if(mp.begin()->first==k)
        return mp.size()-1;
        return mp.size();
    }
};