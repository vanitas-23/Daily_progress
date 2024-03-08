class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int,int>mp;
        for(int i:nums)
            mp[i]++;
        int mx=0;
        for(auto i:mp)
            mx=max(mx,i.second);
        int ans=0;
        for(auto i:mp)
            if(i.second==mx)
                ans+=i.second;
        return ans;
    }
};