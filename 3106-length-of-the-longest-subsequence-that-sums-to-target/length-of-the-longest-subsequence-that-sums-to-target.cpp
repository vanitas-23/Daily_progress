class Solution {
public:
    int f(vector<int>& nums, int target,int i,int n,vector<vector<int>>& dp){
        if(target==0)
        return 0;
        if(target<0)
        return -1e9;
        if(i==n)
        return -1e9;
        if(dp[i][target]!=-1)
        return dp[i][target];
        int taken=1+f(nums,target-nums[i],i+1,n,dp);
        int ntaken=f(nums,target,i+1,n,dp)
        ;
        return dp[i][target]=max(taken,ntaken);
    }
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        return f(nums,target,0,n,dp)<0?-1:f(nums,target,0,n,dp);
    }
};