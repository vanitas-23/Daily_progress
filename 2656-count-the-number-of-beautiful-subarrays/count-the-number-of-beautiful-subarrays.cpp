class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        long long ans=0;
        int i=0;
        int j=0;
        int n=nums.size();
        int curr=0;
        unordered_map<int,int>mp;
        while(j<n)
        {
            curr^=nums[j];
            ans+=mp[curr];
            mp[curr]++;
            j++;
        }
        return ans+mp[0];
    }
};