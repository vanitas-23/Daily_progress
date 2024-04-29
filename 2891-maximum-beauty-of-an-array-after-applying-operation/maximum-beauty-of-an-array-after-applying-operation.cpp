class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        map<int,int>mp;
        for(int i:nums)
        mp[i-k]++,mp[i+k+1]--;
        int ans=0;
        int temp=0;
        for(auto i:mp)
        temp+=i.second,ans=max(ans,temp);
        return ans;
    }
};