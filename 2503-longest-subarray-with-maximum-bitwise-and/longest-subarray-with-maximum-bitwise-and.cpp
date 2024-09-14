class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ans=1;
        int n=nums.size();
        int mx=*max_element(nums.begin(),nums.end());
        int temp=1;
        for(int i=1;i<n;i++)
        {
            if(nums[i]==mx && nums[i-1]==nums[i])
            temp++;
            else
            temp=1;
            ans=max(ans,temp);
        }
        return ans;
    }
};