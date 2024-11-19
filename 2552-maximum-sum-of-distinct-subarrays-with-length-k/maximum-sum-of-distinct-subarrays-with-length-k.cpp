class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans=0;
        unordered_map<int,int>mp;
        int n=nums.size();
        long long curr=0;
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
            curr+=nums[i];
            if(i>=k)
            {
                mp[nums[i-k]]--;
                if(mp[nums[i-k]]==0)
                mp.erase(nums[i-k]);
                curr-=nums[i-k];
            }
            if(mp.size()==k)
            ans=max(ans,curr);
        }
        return ans;
    }
};