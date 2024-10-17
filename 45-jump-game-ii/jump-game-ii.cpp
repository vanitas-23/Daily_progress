class Solution {
public:
    int f(int i,int n,int step,vector<int>& nums,vector<vector<int>>& dp)
    {
        if(i==n-1)
        return 0;
        if(dp[i][step]!=-1)
        return dp[i][step];
        int taken = 1+f(i+1,n,nums[i],nums,dp);
        int ntaken=INT_MAX;
        if(step>1)
        ntaken=f(i+1,n,step-1,nums,dp);
        return dp[i][step]=min(taken,ntaken);
    }
    int jump(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
        return 0;
        vector<vector<int>>dp(n-1,vector<int>(*max_element(nums.begin(),nums.end())+1,-1));
        return 1+f(1,n,nums[0],nums,dp);
    }
};