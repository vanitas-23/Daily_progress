class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n=nums.size();
        int mx=nums[n-1];
        int ans=-1;
        for(int i=n-2;i>=0;i--)
        {
            if(mx>nums[i])
            ans=max(ans,mx-nums[i]);
            mx=max(mx,nums[i]);
        }
        return ans;
    }
};