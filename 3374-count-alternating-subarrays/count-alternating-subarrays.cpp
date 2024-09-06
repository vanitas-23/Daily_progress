class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        long long ans=0;
        int curr=1;
        int n=nums.size();
        for(int i=1;i<n;i++)
        {
            if(nums[i]==nums[i-1])
            ans+=(curr*1ll*(curr+1))/2,curr=1;
            else
            curr++;
        }
        return ans+(curr*1ll*(curr+1))/2;
    }
};