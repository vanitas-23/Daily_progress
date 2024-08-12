class Solution {
public:
    long long f(int i,int n,vector<int>& nums,int par,int x,vector<vector<long long>>& dp)
    {
        if(i==n)
        return 0;
        if(dp[i][par]!=-1)
        return dp[i][par];
        long long nt=f(i+1,n,nums,par,x,dp);
        long long t=0;
        int pp=nums[i]%2;
        if(pp ^ par)
        t=nums[i]+f(i+1,n,nums,pp,x,dp)-x;
        else
        t=nums[i]+f(i+1,n,nums,pp,x,dp);
        return dp[i][par]=max(t,nt);
    }
    long long maxScore(vector<int>& nums, int x) {
        int n=nums.size();
        vector<vector<long long>>dp(n,vector<long long>(2,-1));
        return nums[0]+f(1,n,nums,nums[0]%2,x,dp);
    }
};