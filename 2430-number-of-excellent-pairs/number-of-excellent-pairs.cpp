#define ll long long
class Solution {
public:
    long long countExcellentPairs(vector<int>& arr, int k) {
        map<ll,int>mp;
        vector<int>nums;
        for(auto i:arr)
        {
            if(mp[i]) continue;
            nums.push_back(__builtin_popcount(i));
            mp[i]++;
        }
        sort(nums.begin(),nums.end());
        int l=0;
        int r=nums.size()-1;
        ll ans=0;
        while(l<nums.size() && r>=0)
        {
            if(nums[l]+nums[r]<k)
            l++;
            else
            {
                ans+=(nums.size()-l);
                r--;
            }
        }
        return ans;
    }
};