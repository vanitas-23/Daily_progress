class Solution {
public:
    int f(int i,int n,vector<int>& nums,vector<int>& dp)
    {
        if(i==n)
        return 1;
        if(dp[i]!=-1)
        return dp[i];
        bool b1=0,b2=0,b3=0;
        if(i+1<n && nums[i+1]==nums[i])
        b1=f(i+2,n,nums,dp);
        if(i+1<n && i+2<n && nums[i+1]==nums[i] && nums[i]==nums[i+2])
        b2=f(i+3,n,nums,dp);
        if(i+1<n && i+2<n && nums[i+1]==nums[i]+1 && nums[i+2]==nums[i+1]+1)
        b3=f(i+3,n,nums,dp);
        return dp[i]=b1|b2|b3;
    }
    bool validPartition(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        return f(0,n,nums,dp);
    }
};