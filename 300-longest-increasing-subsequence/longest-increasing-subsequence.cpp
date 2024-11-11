class Solution {
public:
    int f(int i,int n,vector<int>& nums,int pre, vector<vector<int>>& dp)
    {
        if(i==n)
        return 0;
        if(dp[i][pre]!=-1)
        return dp[i][pre];
        int nt=f(i+1,n,nums,pre, dp);
        int t=0;
        if(nums[pre]<nums[i])
        t=1+f(i+1,n,nums,i,dp);
        return dp[i][pre]= max(t,nt);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        vector<vector<int>>dp(n,vector<int>(n,-1));
        for(int i=0;i<n;i++)
        ans=max(ans,1+f(i+1,n,nums,i, dp));
        return ans;
    }
};