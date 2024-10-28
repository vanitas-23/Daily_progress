class Solution {
public:
    int f(int i,int n,vector<int>& nums,vector<int>& dp)
    {
        if(i==n)
        return 0;
        if(dp[i]!=-1)
        return dp[i];
        auto it=lower_bound(nums.begin(),nums.end(),nums[i]*1ll*nums[i]);
        if(it==nums.end())
        return dp[i]=0;
        if(*it==nums[i]*nums[i])
        return dp[i]=1+f(it-nums.begin(),n,nums,dp);
        return dp[i]=0;
    }
    int longestSquareStreak(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int>dp(n,-1);
        int ans=0;
        for(int i=0;i<n;i++)
        ans=max(ans,1+f(i,n,nums,dp));
        return ans==1?-1:ans;
    }
};