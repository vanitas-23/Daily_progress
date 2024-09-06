class Solution {
public:
    int minimumArrayLength(vector<int>& nums) {
        map<int,int>mp;
        for(auto i:nums)
        mp[i]++;
        int x=mp.begin()->first;
        for(int i:nums)
        if(i%x!=0)
        return 1;
        return (mp.begin()->second+1)/2;
    }
};