class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int ans=0;
        int n=nums.size();
        unordered_map<int,int>mp;
        int i=0;
        int j=0;
        while(j<n)
        {
            mp[nums[j]]++;
            while(mp[nums[j]]>k)
            mp[nums[i++]]--;
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};